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

int rows , columns , voyX , voyY , dir;
string grafo[61];
char direcciones[4] = { 'N' , 'E' , 'S' , 'W' };
bool quit;
string instrucciones;

bool isIn( int x , int y )
{
  if( x >= 0 && y >= 0 )  if( x < rows && y < columns ) return true;
  return false;
}

void girar( int add )
{
  dir += add;
  if( dir < 0 )
    dir = 3;
  else if( dir > 3 )
    dir = 0;
}

void move( int x , int y )
{
  if( isIn( voyX + x , voyY + y ) )
    if( grafo[ voyX + x ][ voyY + y ] != '*' )
    voyX += x , voyY += y;
}

void avanzar( void )
{
  switch( dir )
  {
    case 0:
      move( -1 , 0 );
      break;
    case 1:
      move( 0 , 1 );
      break;
    case 2:
    move( 1 , 0 );
      break;
    case 3:
    move( 0 , -1 );
      break;
  }
}

void accion( char &operacion )
{
  switch( operacion )
  {
    case 'R':
      girar( 1 );
    break;
    case 'L':
      girar( -1 );
    break;
    case 'F':
      avanzar();
    break;
    case 'Q':
      quit = true;
      goto end;
  }
  end:
  return;
}

int main()
{
  int test;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &rows , &columns );
    ignore;
    foi( i , 0 , rows ) getline( cin , grafo[i] );
    scanf("%d%d", &voyX , &voyY );
    --voyX , --voyY;
    ignore;
    dir = 0;
    quit = false;
    while( getline( cin , instrucciones ) , instrucciones != "" )
      for( int i = 0 ; i < instrucciones.size && !quit ; ++i )
        accion( instrucciones[i] );
    printf("%d %d %c\n", voyX + 1, voyY + 1, direcciones[dir] );
    if( test )  printf("\n");
  }
  return 0;
}
