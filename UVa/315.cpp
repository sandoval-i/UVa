#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

int N , origen, destino , low[MAX_N] , num[MAX_N] , parent[MAX_N] , iteration , dfs_root , cont , children;
bitset < MAX_N > visited , ap;
vector < vector < int > > grafo;

void dfs( int from )
{
  visited[from] = true;
  low[from] = num[from] = iteration++;
  for( int i = 0 ; i < grafo[from].size() ; ++i )
  {
    int to = grafo[from][i];
    if( !visited[to] )
    {
      parent[to] = from;
      dfs( to );
      low[from] = min( low[from] , low[to] );
      if( from == dfs_root ) ++children;
      if( num[from] <= low[to] && parent[from] != -1 )
        ap[from] = true;
    }
    else if( parent[from] != to )
      low[from] = min( low[from] , num[to] );
  }
}

int main()
{
  while( scanf("%d", &N ) , N )
  {
    grafo.assign(  N , vector < int > () );
    string linea , num_1;
    cin.ignore( 10000 , '\n' );
    while( getline( cin , linea ) , linea != "0" )
    {
      stringstream token( linea );
      token >> num_1;
      origen = atoi( num_1.c_str() );
      --origen;
      while( token >> num_1 )
      {
        destino = atoi( num_1.c_str() );
        --destino;
        grafo[origen].push_back( destino );
        grafo[destino].push_back( origen );
      }
    }
    visited.reset();
    ap.reset();
    memset( low , 0 , sizeof low );
    memset( num , 0 , sizeof num );
    memset( parent , -1 , sizeof parent );
    iteration = 0;
    for( int i = 0 ; i < N ; ++i )
      if( !visited[i] )
      {
        children = 0;
        dfs_root = i;
        dfs(i);
        if( children > 1 )
          ap[i] = true;
      }
    cont = 0;
    for( int i = 0 ; i < N ; ++i ) cont += ap[i];
    printf("%d\n", cont );
  }
  return 0;
}
