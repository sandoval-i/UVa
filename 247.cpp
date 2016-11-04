#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )

int v,e;
vector < vector < int > > graph;
int dfs_num[100] , dfs_low[100] , iteration;
vector < int > stack_scc;
vector < vector < int > > sccs;
bitset < 100 > visited;

void dfs( int u )
{
  dfs_num[u] = dfs_low[u] = iteration++;
  stack_scc.push_back(u);
  visited[u] = true;
  int is , to;
  foi( i , 0 , graph[u].size() )
  {
    to = graph[u][i];
    if( dfs_num[to] == -1 )
      dfs(to);
    if( visited[to] )
    dfs_low[u] = min( dfs_low[u] , dfs_low[to] );
  }
  if( dfs_num[u] == dfs_low[u] ) // SCC
  {
    vector < int > root_scc;
    while(1)
    {
      is = stack_scc.back();
      stack_scc.pop_back();
      visited[is] = false;
      root_scc.push_back(is);
      if( is == u ) break;
    }
    sccs.push_back(root_scc);
  }
}

int main()
{
  int consecutivo , id_from , id_to , caso = 0;
  string name_from , name_to;
  bool first = true;
  // ios::sync_with_stdio(false);
  // cin.tie(NULL);
  while( cin >> v >> e , v || e )
  {
    if( first ) first = false;
    else  cout << '\n';
    map < string , int > ids;
    map < int , string > names;
    consecutivo = iteration = 0;
    stack_scc.clear();
    sccs.clear();
    graph.assign( v , vector < int >() );
    while(e--)
    {
      cin >> name_from >> name_to;
      if( ids.find( name_from ) == ids.end() )
      {
        id_from = ids[name_from] = consecutivo++;
        names[id_from] = name_from;
      }
      else  id_from = ids[name_from];
      if( ids.find( name_to ) == ids.end() )
      {
        id_to = ids[name_to] = consecutivo++;
        names[id_to] = name_to;
      }
      else  id_to = ids[name_to];
      graph[id_from].push_back(id_to);
    }
    memset( dfs_num , -1 , sizeof dfs_num );
    memset( dfs_low , -1 , sizeof dfs_low );
    visited.reset();
    foi( i , 0 , v )  if( dfs_num[i] == -1 ) dfs(i);
    cout << "Calling circles for data set " << ++caso << ":\n";
    foi( i , 0 , sccs.size() )
    {
      foi( j , 0 , sccs[i].size() )
      {
        cout << names[sccs[i][j]];
        if( j != sccs[i].size() - 1 )
          cout << ", ";
      }
      cout << '\n';
    }
  }
  return 0;
}
