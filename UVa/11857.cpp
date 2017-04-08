#include <bits/stdc++.h>

using namespace std;

#define MAX_M 1000000

struct DisjointSets
{
  vector < int > parent , rank;

  DisjointSets( int n )
  {
    rank.assign( n , 1 );
    parent.assign( n , 0 );
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

pair < int , pair < int , int > > roads[MAX_M];

int main()
{
  int num_cities , num_roads , num_componentes , ans;
  std::ios::sync_with_stdio( false );
  cin.tie( NULL );
  while( cin >> num_cities >> num_roads , num_cities || num_roads )
  {
    DisjointSets union_find( num_cities );
    num_componentes = num_cities;
    for( int i = 0 ; i < num_roads ; ++i )
      cin >> roads[i].second.first >> roads[i].second.second >> roads[i].first;
    sort( roads , roads + num_roads );
    ans = -1;
    for( int i = 0 ; i < num_roads ; ++i )
      if( !union_find.connected( roads[i].second.first , roads[i].second.second ) )
      {
        union_find.unir( roads[i].second.first , roads[i].second.second );
        ans = max( ans , roads[i].first );
        --num_componentes;
      }
    if( num_componentes == 1 )
      cout << ans << '\n';
    else
      cout << "IMPOSSIBLE\n";
  }
  return 0;
}
