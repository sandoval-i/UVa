#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; ++i )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

class DisjointSets
{
public:
  vi father , rank;
  int consecutivo;
  DisjointSets( void ) : consecutivo( 0 ){}

  int insertar( void )
  {
    father.pb( consecutivo );
    rank.pb( 1 );
    return consecutivo++;
  }

  int root( int k )
  {
    while( k != father[k] )
      k = father[k] = father[father[k]];
    return k;
  }

  int join( int p , int q )
  {
    int i = root( p );
    int j = root( q );
    if( i == j )  return rank[i];
    if( rank[i] > rank[j] )
    {
      father[j] = father[i];
      rank[i] += rank[j];
      return rank[i];
    }
    father[i] = father[j];
    rank[j] += rank[i];
    return rank[j];
  }

};

int main()
{
  int casos , frienships ;
  string amigo1 , amigo2;
  scanf("%d", &casos );
  while( casos-- )
  {
    DisjointSets socialNetwork;
    unordered_map < string , bool > existe;
    unordered_map < string , int > ids;
    scanf("%d", &frienships );
    while( frienships-- )
    {
      cin >> amigo1 >> amigo2;
      if( !existe[amigo1] )
      {
        ids[amigo1] = socialNetwork.insertar();
        existe[amigo1] = true;
      }
      if( !existe[amigo2] )
      {
        ids[amigo2] = socialNetwork.insertar();
        existe[amigo2] = true;
      }
      printf("%d\n", socialNetwork.join( ids[amigo1] , ids[amigo2] ) );
    }
  }
  return 0;
}
