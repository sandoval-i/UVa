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

map < ii , bool > perdidos;
char direcciones[4] = { 'N' , 'E' , 'S' , 'W' } , direccion , instrucciones[101];
bool lost;
int _x , _y , limiteX , limiteY , posDir;

bool isIn( int x , int y )
{
  if( x >= 0 && y >= 0 )  if( x <= limiteX && y <= limiteY )  return true;
  return false;
}

void girar( int cambio )
{
  posDir += cambio;
  if( posDir < 0 )  posDir = 3;
  else if ( posDir > 3 )  posDir = 0;
}

void mover( int cambioX , int cambioY )
{
  if( isIn( _x + cambioX , _y + cambioY ) )
    _x += cambioX , _y += cambioY;
  else
    if( !perdidos[ ii( _x , _y ) ] )
      perdidos[ ii( _x , _y ) ] = lost = true ;
}

void avanzar( void )
{
  switch( posDir )
  {
    case 0:
      mover( 0 , 1 );
    break;
    case 1:
      mover( 1 , 0 );
    break;
    case 2:
      mover( 0 , -1 );
    break;
    case 3:
      mover( -1 , 0 );
    break;
  }
}

int main()
{
  scanf("%d %d", &limiteX , &limiteY );
  while( scanf("%d %d %c\n%s", &_x , &_y , &direccion , instrucciones ) != EOF )
  {
    lost = false;
    foi( i , 0 , 4 )  if( direcciones[i] == direccion ) { posDir = i ; break; }
    foi( i , 0 , strlen( instrucciones ) ) switch( instrucciones[i] )
    {
      case 'R':
        girar( 1 );
      break;
      case 'L':
        girar( -1 );
      break;
      case 'F':
        avanzar();
      if( lost )  goto fin;
      break;
    }
    printf("%d %d %c\n", _x , _y , direcciones[posDir] );
    continue;
    fin:
    printf("%d %d %c LOST\n", _x , _y , direcciones[posDir] );
  }
  return 0;
}
