#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

int aux , best;
vector < int > dp;
const unsigned long maximo = 1e8;
void swap( int &i , int &j )
{
  aux = i;
  i = j;
  j = i;
}

int calcular( unsigned long i )
{
  if( i == 1 )
    return 1;
  if( i < maximo )
  {
    if( dp[i] != - 1 )
      return dp[i];
    if( par( i ) )
      dp[i] = calcular( i >> 1 ) + 1;
    else
      dp[i] = calcular( 3 * i + 1 ) + 1;
    return dp[i];
  }
  if( par( i ) )
    return calcular( i >> 1 ) + 1;
  return calcular( 3 * i + 1 ) + 1;
}

int mayor( unsigned long i , unsigned long j )
{
  best = 0;
  if( i > j )
    swap( i , j );
  for( ; i <= j ; i++ )
  {
    if( dp[i] == -1 )
      calcular( i );
    best = max( best , dp[i] );
  }
  return best;
}

int main()
{
  unsigned long i , j;
  dp.assign( 1e8 , -1 );
  dp[1] = 1;
  while( scanf( "%lu%lu", &i , &j ) != EOF )
    printf("%lu %lu %d\n", i , j , mayor( i , j ) );
  return 0;
}
