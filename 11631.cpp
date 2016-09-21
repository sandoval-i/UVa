#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200000

struct DisjointSets
{
  vector < int > parent , rank;
  DisjointSets( int n )
  {
    rank.assign( n , 1 );
    for( int i = 0 ; i < n ; ++i )
      parent.push_back( i );
  }

  int root( int k )
  {
    if( parent[k] == k )
      return k;
    return parent[k] = root( parent[k] );
  }

  bool connected( int i , int j )
  {
    return root( i ) == root( j );
  }

  void unir( int p , int q )
  {
    int i = root(p) , j = root(q);
    if( i == j )  return;
    if( rank[i] > rank[j] )
    {
      rank[i] += rank[j];
      parent[j] = i;
    }
    else
    {
      rank[j] += rank[i];
      parent[i] = j;
    }
  }
};

struct edge
{
  int x , y , costo;
  edge() : x(0) , y(0) , costo(0) {};
  bool operator < ( const edge &other ) const
  {
    return this -> costo < other.costo;
  }
};

int main()
{
  int n , m , ans , total;
  edge edges[MAX_N];
  while( scanf("%d%d", &m , &n ) , m || n )
  {
    DisjointSets mst( m );
    total = 0;
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d %d %d", &edges[i].x , &edges[i].y , &edges[i].costo );
      total += edges[i].costo;
    }
    sort( edges , edges + n );
    ans = 0;
    for( int i = 0 ; i < n ; ++i )
      if( !mst.connected( edges[i].x , edges[i].y ) )
      {
        ans += edges[i].costo;
        mst.unir( edges[i].x , edges[i].y );
      }
    printf("%d\n", total - ans );
  }
  return 0;
}
