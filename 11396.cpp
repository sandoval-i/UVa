#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )

vector < vector < int > > graph;
vector < short > color;
int from , to;

bool bicolorable( int source )
{
  queue < int > bfs;
  bfs.push( source );
  color[source] = 0;
  while( !bfs.empty() )
  {
    from = bfs.front();
    bfs.pop();
    foi( i , 0 , graph[from].size() )
    {
      to = graph[from][i];
      if( color[to] == -1 )
      {
        color[to] = 1 - color[from];
        bfs.push( to );
      }
      else if( color[to] == color[from] )
        return false;
    }
  }
  return true;
}

int main()
{
  int V , from , to;
  bool can;
  while( scanf("%d", &V ) , V )
  {
    graph.assign( V , vector < int > () );
    while( scanf("%d %d", &from , &to ) , from || to )
    {
      graph[--from].push_back(--to);
      graph[to].push_back(from);
    }
    color.assign( V , -1 );
    can = true;
    for( int i = 0 ; i < color.size() && can ; ++i )
      if( color[i] == -1 )
        if( !bicolorable( i ) ) can = false;
    puts( can ? "YES" : "NO" );
  }
  return 0;
}
