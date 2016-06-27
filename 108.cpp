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

int N , maxKadane , sumKadane , maxNow , maxTotal;
vector < vi > matriz;
vi actual;

int kadane( vi &a )
{
  maxKadane = -9999999;
  sumKadane = a[0];
  for( int i = 1 ; i < a.size ; i++ )
  {
    sumKadane = max( sumKadane + a[i] , a[i] );
    if( sumKadane > maxKadane )
      maxKadane = sumKadane;
  }
  return maxKadane;
}

int solve()
{
  maxTotal = -99999999;
  foi( i , N )
  {
    actual.assign( N , 0 );
    for( int j = i ; j < N ; j++ )
    {
      foi( k , N )
        actual[k] += matriz[k][j];
      maxNow = kadane( actual );
      if( maxNow > maxTotal )
        maxTotal = maxNow;
    }
  }
  return maxTotal;
}

int main()
{
  while( scanf("%d", &N ) != EOF )
  {
    matriz.assign( N , vi(  N , 0 ) );
    foi( i , N )
      foi( j , N )
        scanf("%d", &matriz[i][j] );
    printf("%d\n", solve() );
  }
  return 0;
}
