#include <bits/stdc++.h>

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )

using namespace std;

int v , e , from , to;
vector < vector < int > > graph;
vector < short > color;
bool bicolorable;

int bfs( int source )
{
  int black , white;
  black = white = 0;
  color[source] = 1;
  queue < int > bfs_queue;
  bfs_queue.push( source );
  while( !bfs_queue.empty() && bicolorable )
  {
    from = bfs_queue.front();
    bfs_queue.pop();
    color[from] == 1 ? ++white : ++black;
    foi( i , 0 , graph[from].size() )
    {
      to = graph[from][i];
      if( color[to] == -1 )
      {
        color[to] = 1 - color[from];
        bfs_queue.push(to);
      }
      else if( color[to] == color[from] )
      {
        bicolorable = false;
        break;
      }
    }
  }
  return min( white , ( black > 0 ) ? black :( 1 << 30 )  );
}

int main()
{
  int casos , ans;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d", &v , &e );
    graph.assign( v , vector < int >() );
    foi( i , 0 , e )
    {
      scanf("%d %d", &from , &to );
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    color.assign( v , -1 );
    bicolorable = true;
    ans = 0;
    for( int i = 0 ; i < v && bicolorable ; ++i )
      if( color[i] == -1 )
        ans += bfs(i);
    printf("%d\n", bicolorable ? ans : -1 );
  }
  return 0;
}
