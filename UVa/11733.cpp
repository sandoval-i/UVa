#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
typedef pair < int , pair < int , int > > edge;
#define foi( i , k , n ) for( int i = k ; i < n ; ++i )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

struct DisjointSets
{
  vi rank , father;

  DisjointSets( int n )
  {
    rank.assign( n , 1 );
    father.assign( n , 0 );
    foi( i , 0 , n )  father[i] = i;
  }

  int find( int k )
  {
    if( k == father[k] )
      return k;
    return father[k] = find( father[k] );
  }

  bool connected( int p , int q )
  {
    return find( p ) == find( q );
  }

  void join( int p , int q )
  {
    int i = find( p );
    int j = find( q );
    if( i == j ) return;
    if( rank[i] > rank[j] )
    {
      father[j] = i;
      rank[i] += rank[j];
    }
    else
    {
      father[i] = j;
      rank[j] += rank[i];
    }
  }

};

int N , M , A , numComponentes;
unsigned long long minCost;

int main()
{
  int casos , x , y , costo , caso = 0;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d %d", &N , &M , &A );
    minCost = 0;
    numComponentes = N;
    vector < edge > lados;
    DisjointSets ds( N );
    foi( i , 0 , M )
    {
      scanf("%d %d %d", &x , &y , &costo );
      if( costo < A ) lados.pb( edge( costo , ii( x - 1 , y - 1 ) ) );
    }
    sort( lados.begin() , lados.end() );
    foi( i , 0 , lados.size )
      if( !ds.connected( lados[i].second.first , lados[i].second.second ) ) ds.join( lados[i].second.first , lados[i].second.second ) , minCost += lados[i].first , --numComponentes;
    printf("Case #%d: %llu %d\n", ++caso , numComponentes * A + minCost , numComponentes );
  }
  return 0;
}

