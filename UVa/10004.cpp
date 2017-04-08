#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; ++i )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

vector < vi > grafo;
int voy , color[200] , n;

bool colorear( void )
{
  foi( i , 1 , n )  color[i] = -1;
  color[0] = 0;
  queue < int > bipartite;
  bipartite.push( 0 );
  while( !bipartite.empty() )
  {
    voy = bipartite.front();
    bipartite.pop();
    foi( i , 0 , grafo[voy].size )
    {
      if( color[grafo[voy][i]] == color[voy] )  return false;
      if( color[grafo[voy][i]] == -1 )  bipartite.push( grafo[voy][i] );
      color[grafo[voy][i]] = 1 - color[voy];
    }
  }
  return true;
}

int main()
{
  int l , origen , destino;
  while( scanf("%d", &n ) , n )
  {
    grafo.assign( n , vi() );
    scanf("%d", &l );
    while( l-- )
    {
      scanf("%d %d", &origen , &destino );
      grafo[origen].pb( destino );
      grafo[destino].pb( origen );
    }
    printf("%s\n", colorear() ? "BICOLORABLE." : "NOT BICOLORABLE." );
  }
  return 0;
}
