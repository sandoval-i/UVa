#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2000
#define MAX_M 50000

pair < int , pair < int , int > > aristas[MAX_M];

struct DisjointSets
{
  int parent[MAX_N] , rank[MAX_N];

  DisjointSets( int num_nodos )
  {
    for( int i = 0 ; i < num_nodos ; ++i )
    {
      parent[i] = i;
      rank[i] = 1;
    }
  }

  int find_root( int k )
  {
    return k == parent[k] ? k : parent[k] = find_root( parent[k] );
  }

  bool connected(int i , int j )
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

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie( NULL );
  int num_nodos , num_aristas , consecutivo , casos , id_origen , id_destino , ans;
  string origen , destino;
  cin >> casos;
  while( casos-- )
  {
    cin >> num_nodos >> num_aristas;
    consecutivo = ans = 0;
    unordered_map < string , int > cities;
    for( int i = 0 ; i < num_aristas ; ++i )
    {
      cin >> origen >> destino >> aristas[i].first;
      if( cities.find( origen ) == cities.end() )
        cities[origen] = id_origen = consecutivo++;
      else
        id_origen = cities[origen];
      if( cities.find( destino ) == cities.end() )
        cities[destino] = id_destino = consecutivo++;
      else
        id_destino = cities[destino];
      aristas[i].second.first = id_origen;
      aristas[i].second.second = id_destino;
    }
    sort( aristas , aristas + num_aristas );
    DisjointSets union_find( num_nodos );
    for( int i = 0 ; i < num_aristas ; ++i )
      if( !union_find.connected( aristas[i].second.first , aristas[i].second.second ) )
      {
        union_find.unir( aristas[i].second.first , aristas[i].second.second );
        ans += aristas[i].first;
      }
    cout << ans << '\n';
    if( casos )
      cout << '\n';
  }
  return 0;
}
