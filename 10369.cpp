#include <bits/stdc++.h>

using namespace std;

#define MAX_S 100
#define MAX_P 500

struct DisjointSets
{
  vector < int > rank , parent;

  DisjointSets( int n )
  {
    rank.assign( n , 1 );
    parent.assign( n , 0 );
    for( int i = 1 ; i < n ; ++i )
      parent[i] = i;
  }

  int root( int k )
  {
    return k == parent[k] ? k : parent[k] = root( parent[k] );
  }

  void reset()
  {
    for( int i = 0 ; i < parent.size() ; ++i )
    {
      parent[i] = i;
      rank[i] = 1;
    }
  }

  bool connected( int i , int j )
  {
    return root(i) == root(j);
  }

  void unir( int i , int j )
  {
    int p = root(i) , q = root(j);
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

long double euclideanDistance( pair < long double , long double > point1 , pair < long double , long double > point2 )
{
  long double diff_x = point1.first - point2.first , diff_y = point1.second - point2.second;
  return sqrt( diff_x * diff_x + diff_y * diff_y );
}

pair < long double , pair < int , int > > edges[MAX_P * MAX_P];
pair < long double , long double > outposts[MAX_P];

int main()
{
  int casos , S , P , num_aristas, componentes;
  long double ans;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d", &S , &P );
    for( int i = 0 ; i < P ; ++i )
      scanf("%Lf %Lf", &outposts[i].first , &outposts[i].second );
    num_aristas = 0;
    for( int i = 0 ; i < P ; ++i )
      for( int j = i + 1 ; j < P ; ++j )
      {
        edges[num_aristas].first = euclideanDistance( outposts[i] , outposts[j] );
        edges[num_aristas].second.first = i;
        edges[num_aristas++].second.second = j;
      }
    sort( edges , edges + num_aristas );
    DisjointSets union_find( P );
    componentes = P;
    for( int i = 0 ; i < num_aristas ; ++i )
      if( !union_find.connected( edges[i].second.first , edges[i].second.second ) )
      {
        union_find.unir( edges[i].second.first , edges[i].second.second );
        ans = edges[i].first;
        if( --componentes == S )
          break;
      }
    printf("%.2Lf\n", ans );
  }
  return 0;
}
