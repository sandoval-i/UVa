#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
#define MAX_M 25000

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
  bool first;
  int num_nodos , num_aristas;
  unsigned long long ans;
  while( scanf("%d %d", &num_nodos , &num_aristas ) , num_nodos || num_aristas )
  {
    for( int i = 0 ; i < num_aristas ; ++i )
      scanf("%d %d %d", &aristas[i].second.first , &aristas[i].second.second , &aristas[i].first );
    sort( aristas , aristas + num_aristas );
    DisjointSets union_find( num_nodos );
    ans = 0;
    first = true;
    for( int i = 0 ; i < num_aristas ; ++i )
    {
      if( !union_find.connected( aristas[i].second.first , aristas[i].second.second ) )
        union_find.unir( aristas[i].second.first , aristas[i].second.second );
      else
      {
        if( first )
        {
          printf("%d", aristas[i].first );
          first = false;
        }
        else  printf(" %d", aristas[i].first );
      }
    }
    if( first )
      puts("forest");
    else
      puts("");
  }
  return 0;
}
