#include <bits/stdc++.h>

using namespace std;

bitset < 1000005 > is_prime;
vector < int > primes;

void sieve( int lim )
{
  is_prime.set();
  is_prime[0] = is_prime[1] = false;
  for( long long i = 2 ; i <= lim ; ++i )
    if( is_prime[i] )
    {
      primes.push_back(i);
      for( long long j = i * i ; j <= lim ; j += i )
        is_prime[j] = false;
    }
}

int main()
{
  sieve(1e6);
  bool solved;
  int n , a , b;
  while( scanf("%d", &n ) , n )
  {
    solved = false;
    for( int i = 0 ; i < primes.size() ; ++i )
    {
      if( primes[i] > ( n >> 1 ) )
        break;
      a = primes[i];
      if( is_prime[n-a] )
      {
        printf("%d = %d + %d\n", n , a , n - a );
        solved = true;
        break;
      }
    }
    if( !solved )
      puts("Goldbach's conjecture is wrong.");
  }
  return 0;
}
