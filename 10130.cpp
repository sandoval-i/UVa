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

int numObjetos , pesoMax;
vi precios , pesos ;
vector < vi > dp;

int knap( int i , int peso )
{
  if( i == numObjetos || peso == 0 )
    return 0;
  if( dp[i][peso] != -1 )
    return dp[i][peso];
  if( pesos[i] > peso )
    return dp[i][peso] = knap( i + 1, peso );
  return dp[i][peso] = max( knap( i + 1, peso ), precios[i] + knap( i + 1, peso - pesos[i] ) );
}

int main()
{
  int test , numPersonas , aux;
  scanf("%d", &test );
  while( test-- )
  {
    aux = 0;
    scanf("%d", &numObjetos );
    precios.assign( numObjetos , 0 );
    pesos.assign( numObjetos , 0 );
    foi( i , numObjetos )
      scanf("%d %d", &precios[i] , &pesos[i] );
    scanf("%d", &numPersonas );
    pesoMax = 0;
    dp.assign( numObjetos , vi( 3000 , -1 ) );
    while( numPersonas-- )
      scanf("%d", &pesoMax ) , aux += knap( 0 , pesoMax ) ;
    printf("%d\n", aux );
  }
  return 0;
}
