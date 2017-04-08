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

int nodes , edges , ans , nodoVoy ,  learning[101] , maximo , maximoCosto;
vector < vi > grafo;
vi :: iterator itr;
ii res;

ii BFS( void )
{
  queue < int > colaBFS;
  ans = 0;
  colaBFS.push( 0 );
  while( !colaBFS.empty() )
  {
    nodoVoy = colaBFS.front() ; colaBFS.pop();
    if( !grafo[nodoVoy].size )  return ii( ans + learning[0] , nodoVoy );
    maximoCosto = -1;
    foi( i , 0 , grafo[nodoVoy].size )
      if( learning[grafo[nodoVoy][i]] > maximoCosto )
        maximo = grafo[nodoVoy][i] , maximoCosto = learning[grafo[nodoVoy][i]];
    colaBFS.push( maximo );
    ans += maximoCosto;
  }
}

int main()
{
  int test , origen , destino , caso = 0;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &nodes , &edges );
    grafo.assign( nodes , vi() );
    foi( i , 0 , nodes )  scanf("%d", &learning[i] );
    while( edges-- )  scanf("%d %d", &origen , &destino ) , grafo[origen].pb( destino );
    res = BFS();
    printf("Case %d: %d %d\n", ++caso , res.first , res.second );
  }
  return 0;
}
