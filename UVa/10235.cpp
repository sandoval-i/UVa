#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000005
typedef long long ll;
bitset < MAX_N > is_prime;
int pot[10];

void sieve( int lim )
{
    is_prime.set();
    for( ll i = 2 ; i < lim ; ++i )
        if( is_prime[i] )
            for( ll j = i * i ; j < lim ; j += i )  is_prime[j] = false;

}

int voltear( int k )
{
    int ans = 0;
    int len = floor(log10(k));
    int potencia = pot[len];
    while(k)
    {
        ans += ( k % 10 ) * potencia;
        potencia /= 10;
        k /= 10;
    }
    return ans;
}

int main()
{
    int n , r_n;
    pot[0] = 1;
    for( int i = 1 ; i < 8 ; ++i )
        pot[i] = pot[i-1] * 10;
    sieve(MAX_N);
    while( scanf("%d" , &n) != EOF )
    {
        r_n = voltear(n);
        if( is_prime[n] && is_prime[r_n] && r_n != n )  printf("%d is emirp.\n" , n);
        else if( is_prime[n] )   printf("%d is prime.\n" , n);
        else    printf("%d is not prime.\n" , n);
    }
    return 0;
}
