#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

bitset < 18409220 > isPrime;
vector < ii > sequence;

void sieve( unsigned long tam )
{
  isPrime.set();
  isPrime[0] = isPrime[1] = false;
  for( ll i = 2 ; i <= tam ; ++i )
  {
    if( isPrime[i] )
    {
        for( ll j = i * i ; j <= tam ; j += i  )
          isPrime[j] = false;
        if( isPrime[i-2] )  sequence.pb( ii( i - 2 , i ) );
    }
  }
}

int main()
{
  int need;
  sieve( 18409220 );
  while( scanf( "%d" , &need ) != EOF )
    printf("(%d, %d)\n", sequence[need-1].first , sequence[need-1].second );
  return 0;
}
