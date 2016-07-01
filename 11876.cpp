#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore();

bitset< 1000001 > bs;
vi primes;

void sieve( ll upperbound )
{
  bs.set();
  bs[0] = bs[1] = 0;
  for( ll i = 2 ; i <= upperbound + 1 ; i++ )
    if( bs[i] )
    {
      for( ll j = i*i ; j <= upperbound + 1 ; j+= i )
        bs[j] = 0;
      primes.pb( int(i) );
    }
}

ll NOD( ll N )
{
  ll PF_idx = 0, PF = primes[PF_idx] , ans = 1 , power;
  while( PF * PF <= N )
  {
    power = 0;
    while( N % PF == 0 )
    {
      N /= PF;
      power++;
    }
    ans *= ( power + 1 );
    PF = primes[++PF_idx];
  }
  if( N != 1 )
    ans *= 2;
  return ans;
}

int main()
{
  int caso = 0 , queries , inicio , fin , ans , last , first;
  vector < ll > sequence( 1000001 , 0 );
  sieve( 1e6 + 1 );
  sequence[0] = 1;
  for( int i = 1 ; i < sequence.size ; i++ )
    sequence[i] = sequence[i-1] + NOD( sequence[i-1] );
  scanf("%d", &queries );
  while( queries-- )
  {
    scanf("%d %d", &inicio , &fin );
    first = lower_bound( sequence.begin() , sequence.end() , inicio ) - sequence.begin();
    last = upper_bound( sequence.begin() , sequence.end() , fin) - sequence.begin() - 1;
    ans = last - first;
    printf("Case %d: %d\n", ++caso , ans + 1 );
  }
  return 0;
}
