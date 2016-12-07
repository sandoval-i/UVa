#include <bits/stdc++.h>

using namespace std;
#define MAX_N 10005

typedef long long ll;
int sum[MAX_N];
bitset < MAX_N > is_prime;
vector < int > primes;

void sieve( int lim )
{
    is_prime.set();
    for( ll i = 2 ; i <= lim ; ++i  )
        if( is_prime[i] )
        {
            for( ll j = i * i ; j <= lim ; j += i )    is_prime[j] = false;
            primes.push_back(i);
        }
}

int main()
{
    int n , sum_now;
    sieve(MAX_N);
    memset( sum , 0 , sizeof sum );
    for( int i = 0 ; i < primes.size() ; ++i )
    {
        sum_now = 0;
        for( int j = i ; j < primes.size() ; ++j )
        {
            sum_now += primes[j];
            if( sum_now >= MAX_N )  break;
            ++sum[sum_now];
        }
    }
    while( scanf("%d" , &n) , n )
        printf("%d\n" , sum[n]);
    return 0;
}
