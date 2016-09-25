#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

pair < double , double > cities[1000];
pair < double , pair < int , int > > diferencias[1000000];
int num_diferencias;

double euclideanDistance( pair < double , double > a , pair < double , double > b )
{
  double diff_x = a.first - b.first;
  double diff_y = a.second - b.second;
  return sqrt( diff_x * diff_x + diff_y * diff_y );
}


struct DisjointSets
{
  int parent[MAX_N] , rank[MAX_N];
  DisjointSets( int n )
  {
    for( int i = 0 ; i < n ; ++i )
      parent[i] = i;
    for( int i = 0 ; i < n ; ++i )
      rank[i] = 1;
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

int main()
{
  int casos , states , caso = 0 , n;
  double ans_roads , ans_railroads , r;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %lf", &n , &r );
    num_diferencias = 0;
    states = n;
    ans_roads = ans_railroads = 0.0;
    DisjointSets union_find( n );
    for( int i = 0 ; i < n ; ++i ) scanf("%lf %lf", &cities[i].first , &cities[i].second );
    for( int i = 0 ; i < n ; ++i ) for( int j = i + 1 ; j < n ; ++j )
    {
      diferencias[num_diferencias].first = euclideanDistance( cities[i] , cities[j] );
      diferencias[num_diferencias].second.first = i;
      diferencias[num_diferencias++].second.second = j;
    }
    sort( diferencias , diferencias + num_diferencias );
    for( int i = 0 ; i < num_diferencias ; ++i )
      if( !union_find.connected( diferencias[i].second.first , diferencias[i].second.second ) )
      {
        union_find.unir( diferencias[i].second.first , diferencias[i].second.second );
        if( diferencias[i].first <= r )
        {
          ans_roads += diferencias[i].first;
          --states;
        }
        else
          ans_railroads += diferencias[i].first;
      }
    printf("Case #%d: %d %.0lf %.0lf\n", ++caso , states , ans_roads , ans_railroads );
  }
  return 0;
}
