#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
typedef unsigned long long ull;
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

int N , Q , D , M , numeros[200];
map < int , int > dp[10][200];

int knap( int numerosVoy , int indexVoy , int sumaLlevo )
{
  if( numerosVoy == M )
  {
    if( sumaLlevo % D == 0 )
      return 1;
    return 0;
  }
  if( dp[numerosVoy][indexVoy].count( sumaLlevo % D ) )
    return dp[ numerosVoy ][ indexVoy ][ sumaLlevo % D ];
  if( indexVoy == N ) return 0;
  return dp[ numerosVoy ][ indexVoy ][ sumaLlevo % D ] = knap( numerosVoy + 1 , indexVoy + 1 , sumaLlevo + numeros[indexVoy] ) + knap( numerosVoy , indexVoy + 1 , sumaLlevo );
}

int main()
{
  int caso = 0 , query;
  while( scanf("%d %d", &N , &Q ) , N || Q )
  {
    query = 0;
    foi( i , 0 , N ) scanf("%d", &numeros[i] );
    printf("SET %d:\n", ++ caso );
    foi( i , 0 , Q )
    {
      foi( i , 0 , 10 ) foi( j , 0 , 200 )  dp[i][j].clear();
      scanf("%d %d", &D , &M );
      printf("QUERY %d: %d\n", ++query , knap( 0 , 0 , 0  ) );
    }
  }
  return 0;
}
