#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50001

vector < vector < int > > grafo;
bitset < MAX_N > visited ;
int num_visitados[MAX_N];

int dfs( int u )
{
  visited[u] = true;
  num_visitados[u] = 0;
  int v = grafo[u][0];
  if( !visited[v] )
    num_visitados[u] += 1 + dfs(v);
  visited[u] = false;
  return num_visitados[u];
}

int main()
{
  int casos , N , origen , destino , ans_node , ans_max , caso = 0;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d", &N );
    grafo.assign( N , vector < int > () );
    visited.reset();
    ans_node = ans_max = -1;
    memset( num_visitados , -1 , sizeof num_visitados );
    for( int i = 0 ; i < N ; ++i )
    {
      scanf("%d %d", &origen , &destino );
      grafo[--origen].push_back( --destino );
    }
    for( int i = 0 ; i < N ; ++i )
    {
      if( num_visitados[i] == -1 ) dfs( i );
      if( num_visitados[i] > ans_max )
        ans_max = num_visitados[i] , ans_node = i + 1;
    }
    printf("Case %d: %d\n", ++caso , ans_node );
  }
  return 0;
}
