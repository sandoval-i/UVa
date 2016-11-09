#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2002
#define foi( i , n , k )  for( int i = n ; i < k ; ++i )

int dfs_num[MAX_N] , dfs_low[MAX_N] , iteration , num_scc;
bitset < MAX_N > visited;
vector < int > scc;
vector < vector < int > > graph;

void dfs( int u )
{
  scc.push_back(u);
  visited[u] = true;
  dfs_num[u] = dfs_low[u] = iteration++;
  foi( i , 0 , graph[u].size() )
  {
    int v = graph[u][i];
    if( dfs_num[v] == -1 )  dfs(v);
    if( visited[v] )  dfs_low[u] = min( dfs_low[u] , dfs_low[v] );
  }
  if( dfs_num[u] == dfs_low[u] )
  {
    ++num_scc;
    while(1)
    {
      int scc_part = scc.back();
      scc.pop_back();
      visited[scc_part] = false;
      if( scc_part == u ) break;
    }
  }
}

int main()
{
  int M , N , from , to , directional;
  while( scanf( "%d %d" , &M, &N ) , M || N )
  {
    graph.assign( M , vector < int > () );
    while( N-- )
    {
      scanf( "%d %d %d" , &from , &to , &directional );
      graph[--from].push_back(--to);
      if( directional == 2 )  graph[to].push_back(from);
    }
    visited.reset();
    memset( dfs_num , -1 , sizeof dfs_num );
    memset( dfs_low , -1 , sizeof dfs_low );
    iteration = num_scc = 0;
    foi( i , 0 , M )
      if( dfs_num[i] == -1 )
        dfs(i);
    printf("%d\n", num_scc == 1 );
  }
  return 0;
}
