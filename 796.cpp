#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )
#define MAX_VERTICES 10005
typedef pair < int , int > ii;

int dfs_num[MAX_VERTICES] , dfs_low[MAX_VERTICES] , iteration , parent[MAX_VERTICES];
vector < vector < int > > graph;
vector < ii > bridges;
bitset < MAX_VERTICES > visited;

void dfs( int from )
{
  visited[from] = true;
  dfs_num[from] = dfs_low[from] = iteration++;
  foi( i , 0 , graph[from].size() )
  {
    int to = graph[from][i];
    if( parent[from] == to )  continue;
    if( !visited[to] )
    {
      parent[to] = from;
      dfs( to );
      dfs_low[from] = min( dfs_low[from] , dfs_low[to] );
      if( dfs_num[from] < dfs_low[to] )
        bridges.push_back( ii( from , to ) );
    }
    else
      dfs_low[from] = min( dfs_low[from] , dfs_num[to] );
  }
}

bool comp( ii a , ii b )
{
  return ( a.first == b.first ) ? ( a.second < b.second ) : ( a.first < b.first );
}

int main()
{
  int from , to , v , e;
  while( scanf("%d", &v ) != EOF )
  {
    graph.assign( v , vector < int >() );
    foi( i , 0 , v )
    {
      scanf("%d (%d)", &from , &e );
      while( e-- )
      {
        scanf("%d", &to );
        graph[from].push_back(to);
      }
    }
    memset( dfs_num , 0 , sizeof dfs_num );
    memset( dfs_low , 0 , sizeof dfs_low );
    memset( parent , -1 , sizeof parent );
    visited.reset();
    bridges.clear();
    iteration = 0;
    foi( i , 0 , v )
      if( !visited[i] )
        dfs(i);
    foi( i , 0 , bridges.size() )
      if( bridges[i].first > bridges[i].second )
        swap( bridges[i].first , bridges[i].second );
    sort( bridges.begin() , bridges.end() , comp );
    printf("%d critical links\n", (int)bridges.size() );
    foi( i , 0 , bridges.size() )
      printf("%d - %d\n", bridges[i].first , bridges[i].second );
    puts("");
  }
  return 0;
}
