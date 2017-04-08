#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;
#define foi( i , n , k )  for( int i = n ; i < k ; ++i )
#define MAX_N 10005
vector < vector < int > > graph;
int dfs_num[MAX_N] , dfs_low[MAX_N] , parent[MAX_N] , iteracion , dfs_root , children;
vector < int > ap;
vector < ii > points;
bitset < MAX_N > visited;

void dfs( int from )
{
  dfs_num[from] = dfs_low[from] = iteracion++;
  int to;
  foi( i , 0 , graph[from].size() )
  {
    to = graph[from][i];
    if( parent[from] == to )  continue;
    if( dfs_num[to] == -1 )
    {
      if( from == dfs_root )  ++children;
      parent[to] = from;
      dfs(to);
      dfs_low[from] = min( dfs_low[from] , dfs_low[to] );
      if( dfs_num[from] <= dfs_low[to] && parent[from] != -1 )  ++ap[from];
    }
    else
      dfs_low[from] = min( dfs_low[from] , dfs_num[to] );
  }
}

bool comp( ii a , ii b )
{
  return ( a.second == b.second ) ? a.first < b.first : a.second > b.second;
}

int main()
{
  int n , m , from ,to;
  while( scanf("%d %d", &n , &m ) , n || m )
  {
    graph.assign( n , vector < int >() );
    while( scanf("%d %d", &from , &to ) , from != -1 && to != -1 )
    {
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    points.clear();
    memset( dfs_num , -1 , sizeof dfs_num );
    memset( dfs_low , -1 , sizeof dfs_low );
    memset( parent , -1 , sizeof parent );
    ap.assign( n , 1 );
    dfs_root = iteracion = children = 0;
    dfs(0);
    if( children >= 2 )
      ap[0] = children;
    foi( i , 0 , n )
        points.push_back( ii( i , ap[i] ) );
    sort( points.begin() , points.end() , comp );
    foi( i , 0 , m )
      printf("%d %d\n", points[i].first , points[i].second );
    puts("");
  }
  return 0;
}
