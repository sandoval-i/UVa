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
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

int numJugadores , numSnakesLadders , numDados;
int tablero[101] , posJugadores[1000001] , dados[1000001];

int main()
{
  int test , origen , destino , turno ;
  scanf("%d", &test );
  while( test-- )
  {
    turno = 0;
    memset( tablero , 0 , sizeof tablero );
    scanf("%d %d %d", &numJugadores , &numSnakesLadders , &numDados );
    foi( i , 0 , numJugadores ) posJugadores[i] = 1;
    while( numSnakesLadders-- )
      scanf("%d %d", &origen , &destino ) , tablero[origen] = destino;
    foi( i , 0 , numDados ) scanf("%d", &dados[i] );
    foi( i , 0 , numDados )
    {
      posJugadores[turno] += dados[i];
      if( tablero[posJugadores[turno]] != 0 )
        posJugadores[turno] = tablero[posJugadores[turno]];
      if( posJugadores[turno] >= 100 )
        break;
      if( ++turno == numJugadores ) turno = 0;
    }
    foi( i , 0 , numJugadores )
      printf("Position of player %d is %d.\n", i+1 , posJugadores[i] );
  }
  return 0;
}
