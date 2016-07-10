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

vector < vi > soluciones;
vi need;

bool mismaPendiente( int x1 , int y1 , int x2 , int y2 )
{
  return abs( y2 - y1 ) == abs( x2 - x1 );
}

bool can( int fila , int columna , vi &looking )
{
  foi( i , 1 , columna )
    if( looking[i] == fila || mismaPendiente( fila , columna , looking[i] , i ) )  return false;
  return true;
}

void precalcular( int indice , vi llevo )
{
  if( indice == 9 )
  {
    soluciones.pb( llevo );
    return;
  }
  foi( i , 1 , 9 )
    if( can( i , indice , llevo ) )
    {
      llevo[indice] = i;
      precalcular( indice + 1 , llevo );
    }
}

int solve()
{
  int minChanges = 9999 , aux;
  foi( i , 0 , soluciones.size )
  {
    aux = 0;
    foi( j , 1 , 9 )
      if( need[j] != soluciones[i][j] ) aux++;
    minChanges = min( minChanges , aux );
  }
  return minChanges;
}

int main()
{
  int caso = 0;
  need.assign( 9 , 0 );
  precalcular( 1 , vi( 9 , 0 ) );
  while( scanf("%d%d%d%d%d%d%d%d", &need[1] , &need[2] , &need[3] , &need[4] , &need[5] , &need[6] , &need[7] , &need[8] ) != EOF )
    printf("Case %d: %d\n", ++caso , solve() );
  return 0;
}
