#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )
#define MAX_N 50005

int grafo[MAX_N];
int num_visitados[MAX_N];
int dfs_num[MAX_N] , dfs_low[MAX_N] , iteracion;
bitset < MAX_N > visited;
vector < int > pila_scc;
vector < vector < int > > scc;

void dfs( int i )
{
  dfs_num[i] = dfs_low[i] = iteracion++;
  visited[i] = true;
  pila_scc.push_back(i);
  if( dfs_num[grafo[i]] == -1 )
    dfs( grafo[i] );
  if( visited[grafo[i]] )
    dfs_low[i] = min( dfs_low[i] , dfs_low[grafo[i]] );
  if( dfs_num[i] == dfs_low[i] )
  {
    vector < int > this_scc;
    while(1)
    {
      int tope = pila_scc.back();
      pila_scc.pop_back();
      this_scc.push_back(tope);
      visited[tope] = false;
      if( tope == i ) break;
    }
    scc.push_back(this_scc);
  }
}

void dfs2( int u )
{
  if( num_visitados[grafo[u]] == -1 )
    dfs2(grafo[u]);
  num_visitados[u] = 1 + num_visitados[grafo[u]];
}

int main()
{
  int casos , nodos , from , to , m , visited_m , caso = 0;
  scanf( "%d" , &casos );
  while( casos-- )
  {
    scc.clear();
    visited.reset();
    memset( dfs_num , -1 , sizeof dfs_num );
    memset( dfs_low , -1 , sizeof dfs_low );
    memset( num_visitados , -1 , sizeof num_visitados );
    iteracion = 0;
    scanf( "%d" , &nodos );
    foi( i , 0 , nodos )
    {
      scanf( "%d %d" , &from , &to );
      grafo[from - 1] = to - 1;
    }
    visited_m = 0;
    foi( i , 0 , nodos )
      if( dfs_num[i] == -1 )
        dfs(i);
    foi( i , 0 , scc.size() )
      if( scc[i].size() > 1 )
          foi( j , 0 , scc[i].size() )
            num_visitados[scc[i][j]] = scc[i].size() - 1;
    foi( i , 0 , nodos )
      if( num_visitados[i] == -1 )
          dfs2(i);
    foi( i , 0 , nodos )
      if( num_visitados[i] > visited_m )
      {
        m = i;
        visited_m = num_visitados[i];
      }
    printf("Case %d: %d\n" , ++caso , m + 1 );
  }
  return 0;
}
