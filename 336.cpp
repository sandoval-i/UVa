#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < (int)n ; i++ )
#define size size()
#define pb push_back
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

int NC , source , TTL , origen , destino , caso , voy , dist , reachable;
ii par;
unordered_map < int , vi > grafo;

int solve( void )
{
  reachable = 1;
  queue < ii > colaBFS;
  unordered_map < int , bool > visitados;
  visitados[source] = true;
  colaBFS.push( ii( source , TTL ) );
  while( !colaBFS.empty() )
  {
    par = colaBFS.front(); colaBFS.pop();
    voy = par.first , dist = par.second;
    vi &vecinos = grafo[voy];
    foi( i , 0 , vecinos.size )
      if( !visitados[vecinos[i]] )
        if( dist > 0 )  colaBFS.push( ii( vecinos[i] , dist - 1 ) ) , visitados[vecinos[i]] = true , reachable++;
        else return grafo.size - reachable;
  }
  return grafo.size - reachable;
}

int main()
{
  caso = 0;
  while( scanf("%d", &NC ) , NC )
  {
    grafo.clear();
    while( NC-- ) scanf("%d %d", &origen , &destino ) , grafo[origen].pb( destino ) , grafo[destino].pb( origen );
    while( scanf("%d %d", &source , &TTL ) , source || TTL )
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caso , solve() , source , TTL );
  }
  return 0;
}
