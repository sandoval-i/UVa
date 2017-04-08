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
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )

vector < vi > matriz;
int n;

int play( int fila , int columnasUsadas , int total )
{
  if( fila == n )
    return total;
  int llevo = 1e9;
  foi( i , n )
    if( !testBit( columnasUsadas , i ) )
      llevo = min( llevo , play( fila + 1 , turnOnBit( columnasUsadas , i )  , total + matriz[fila][i] ) );
  return llevo;
}

int main()
{
  int test;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d", &n );
    matriz.assign( n , vi( n , 0 ) );
    foi( i , n )
      foi( j , n )
        scanf("%d", &matriz[i][j] );
    printf("%d\n", play( 0 , 0 , 0 ) );
  }
  return 0;
}
