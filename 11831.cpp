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

int filas , columnas , numInstrucciones , voyX , voyY , solution  , posDir;
char grafo[101][101] , instrucciones[50001] , direccion , direcciones[4] = { 'N' , 'L' , 'S' , 'O' };
bool found;

bool isIn( int x , int y )
{
  if( x >= 0 && y >= 0 ) if( x < filas && y < columnas )  return true;
  return false;
}

void mover( int addX , int addY )
{
  if( isIn( voyX + addX , voyY + addY ) )
    if( grafo[voyX + addX][voyY + addY] != '#' )
    {
      voyX += addX , voyY += addY;
      if( grafo[voyX][voyY] == '*' )
        solution++ , grafo[voyX][voyY] = '.';
    }
}

void avanzar()
{
  switch( posDir )
  {
    case 0:
      mover( -1 , 0 );
    break;
    case 1:
      mover( 0 , 1 );
    break;
    case 2:
      mover( 1 , 0 );
    break;
    case 3:
      mover( 0 , -1 );
    break;
  }
}

void girar( int cambio )
{
  posDir += cambio;
  if( posDir < 0 )
    posDir = 3;
  else if( posDir > 3 )
    posDir = 0;
}

int solve( void )
{
  solution = 0;
  foi( i , 0 , numInstrucciones )
  {
    switch( instrucciones[i] )
    {
      case 'F':
        avanzar();
        break;
      case 'D':
        girar( 1 );
        break;
      case 'E':
        girar( -1 );
        break;
    }
  }
  return solution;
}

int main()
{
  while( scanf( "%d %d %d" , &filas , &columnas , &numInstrucciones ) , filas || columnas || numInstrucciones )
  {
    found = false;
    foi( i , 0 , filas ) foi( j , 0 , columnas )
    {
      scanf(" %c", &grafo[i][j] );
      if( !found )
        if( grafo[i][j] != '*' && grafo[i][j] != '.' && grafo[i][j] != '#' )
          voyX = i , voyY = j , direccion = grafo[i][j] , grafo[i][j] = '.' , found = true;
    }
    foi( i , 0 , 4 ) if( direcciones[i] == direccion ){ posDir = i ; break; }
    foi( i , 0 , numInstrucciones ) scanf(" %c", &instrucciones[i] );
    printf("%d\n", solve() );
  }
  return 0;
}
