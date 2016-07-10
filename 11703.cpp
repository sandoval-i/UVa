#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
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
#define maxI 1000001

ll dp[maxI];
int b;

ll calc( int i )
{
  if( dp[i] != -1 )
    return dp[i];
  return dp[i] = ( calc( floor( i - sqrt( i ) ) ) + calc( floor( log1p( i - 1 ) ) ) + calc( floor( i * sin( i ) * sin( i ) ) ) ) % 1000000;
}

int main()
{
  memset( dp , -1 , sizeof dp );
  dp[0] = 1;
  int i;
  while( scanf("%d", &i ) , i != -1 )
    printf("%lld\n", calc( i ) );
  return 0;
}
