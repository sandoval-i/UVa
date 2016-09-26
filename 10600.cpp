#include <bits/stdc++.h>

using namespace std;

struct DisjointSets
{
  vector < int > rank , parent;

  DisjointSets( int n  )
  {
    rank.assign( n , 1 );
    parent.assign( n , 0 );
    for( int i = 1 ; i < n ; ++i )
      parent[i] = i;
  }

  void resett( void )
  {
    for( int i = 0 ; i < parent.size() ; ++i )
    {
      parent[i] = i;
      rank[i] = 1;
    }
  }

  int find_root( int k )
  {
    return parent[k] == k ? k : parent[k] = find_root( parent[k] );
  }

  bool connected( int i , int j )
  {
    return find_root(i) == find_root(j);
  }

  void unir( int i , int j )
  {
    int p = find_root(i) , q = find_root(j);
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
};

vector < pair < int , pair < int , int > > > edges;

int main()
{
  int casos , num_nodos , num_aristas , origen , destino , componentes , best_mst , second_best_mst , mst , last_i;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d", &num_nodos , &num_aristas );
    edges.assign( num_aristas , pair < int , pair < int , int > > () );
    for( int i = 0 ; i < num_aristas ; ++i )
    {
      scanf("%d %d %d" , &origen , &destino , &edges[i].first );
      edges[i].second.first = --origen;
      edges[i].second.second = --destino;
    }
    sort( edges.begin() , edges.end() );
    DisjointSets union_find( num_nodos );
    best_mst = 0;
    second_best_mst = 1 << 30;
    vector < int > bst_edges;
    for( int i = 0 ; i < num_aristas ; ++i )
      if( !union_find.connected( edges[i].second.first , edges[i].second.second ) )
      {
        union_find.unir( edges[i].second.first , edges[i].second.second );
        best_mst += edges[i].first;
        bst_edges.push_back(i);
      }
    for( int i = 0 ; i < bst_edges.size() ; ++i )
    {
      union_find.resett();
      componentes = num_nodos;
      mst = 0;
      for( int j = 0 ; j < num_aristas ; ++j )
      {
        if( j == bst_edges[i] )
          continue;
        if( !union_find.connected( edges[j].second.first , edges[j].second.second ) )
        {
          mst += edges[j].first;
          union_find.unir( edges[j].second.first , edges[j].second.second );
          --componentes;
        }
      }
      if( componentes == 1 )
        second_best_mst = min( second_best_mst , mst );
    }
    printf("%d %d\n", best_mst , second_best_mst );
  }
  return 0;
}
