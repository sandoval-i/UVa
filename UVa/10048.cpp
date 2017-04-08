#include <bits/stdc++.h>

using namespace std;

#define MAX_S 1000
#define INF 999999

struct DisjointSets
{
  vector < int > parent , rank;
  DisjointSets( int n )
  {
    parent.assign( n , 0 );
    rank.assign( n , 1 );
    for( int i = 1 ; i < n ; ++i )
      parent[i] = i;
  }

  int find_parent( int k )
  {
    return parent[k] == k ? k : parent[k] = find_parent( parent[k] );
  }

  void unir( int i , int j )
  {
    int p = find_parent(i) , q = find_parent(j);
    if( p == q )  return;
    if( rank[p] > rank[q] )
    {
      rank[p] += rank[q];
      parent[q] = p;
    }
    else
    {
      rank[q] += rank[p];
      parent[p] = q;
    }
  }

  bool connected( int i , int j )
  {
    return find_parent(i) == find_parent(j);
  }

};

pair < int , pair < int , int > > edges[MAX_S];
vector < vector < pair < int , int > > > grafo;
int ans_minimo , destino;
bitset < 100 > visited;

void dfs( int from , int minimo )
{
  visited[from] = true;
  if( from == destino )
    ans_minimo = max( ans_minimo , minimo );
  for( int i = 0 ; i < grafo[from].size() ; ++i )
  {
    int to = grafo[from][i].first , costo = grafo[from][i].second;
    if( !visited[to] )
      dfs( to , max( minimo , costo ) );
  }
}

int main()
{
  int num_nodos , num_aristas , num_queries , origen , u , v , caso = 0;
  bool first = true;
  while( scanf("%d %d %d", &num_nodos , &num_aristas , &num_queries ) , num_nodos || num_aristas || num_queries )
  {
    if( first )
      first = false;
    else  puts("");
    printf("Case #%d\n", ++caso );
    for( int i = 0 ; i < num_aristas ; ++i )
    {
      scanf("%d %d %d", &origen , &destino , &edges[i].first );
      edges[i].second.first = --origen;
      edges[i].second.second = --destino;
    }
    sort( edges , edges + num_aristas );
    grafo.assign( num_nodos , vector < pair < int , int > > () );
    DisjointSets union_find( num_nodos );
    for( int i = 0 ; i < num_aristas ; ++i )
    {
      u = edges[i].second.first;
      v = edges[i].second.second;
      if( !union_find.connected( u , v ) )
      {
        union_find.unir( u , v );
        grafo[u].push_back( pair < int , int >( v , edges[i].first ) );
        grafo[v].push_back( pair < int , int >( u , edges[i].first ) );
      }
    }
    while( num_queries-- )
    {
      scanf("%d %d", &origen , &destino );
      --origen,--destino;
      if( !union_find.connected( origen , destino ) )
        puts("no path");
      else
      {
        ans_minimo = -INF;
        visited.reset();
        dfs( origen , -1 );
        printf("%d\n", ans_minimo );
      }
    }
  }
  return 0;
}
