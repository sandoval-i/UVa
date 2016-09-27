#include <bits/stdc++.h>

using namespace std;

vector < vector < char > > rotar( vector < vector < char > > matriz )
{
  vector < vector < char > > ans( matriz.size() , vector < char > ( matriz.size() , '0' ) );
  int col = 0;
  for( int i = matriz.size() - 1 ; i >= 0 ; --i )
  {
    for( int j = 0 ; j < matriz.size() ; ++j )
      ans[j][col] = matriz[i][j];
    ++col;
  }
  return ans;
}

int matching( vector < vector < char > > &matriz , vector < vector < char > > &searching )
{
  int ans = 0;
  bool yes;
  for( int i = 0 ; i + searching.size() - 1 < matriz.size() ; ++i )
    for( int j = 0 ; j + searching.size() - 1 < matriz.size() ; ++j )
    {
      yes = true;
      for( int p = 0 ; p < searching.size() && yes ; ++p )
        for( int q = 0 ; q < searching.size() && yes ; ++q )
          if( searching[p][q] != matriz[p+i][q+j]  )
            yes = false;
      ans += yes;
    }
  return ans;
}

int main()
{
  int N , n , rotaciones[4];
  while( scanf("%d %d", &N , &n ) , N || n )
  {
    vector < vector < char > > matriz_grande(  N , vector < char > ( N , '0' ) );
    vector < vector < char > > matriz_peque(  n , vector < char > ( n , '0' ) );
    for( int i = 0 ; i < N ; ++i )
      for( int j = 0 ; j < N ; ++j )
        scanf(" %c", &matriz_grande[i][j] );
    for( int i = 0 ; i < n ; ++i )
      for( int j = 0 ; j < n ; ++j )
        scanf(" %c", &matriz_peque[i][j] );
    rotaciones[0] = matching( matriz_grande , matriz_peque );
    for( int i = 1 ; i < 4 ; ++i )
    {
      matriz_peque = rotar( matriz_peque );
      rotaciones[i] = matching( matriz_grande , matriz_peque );
    }
    for( int i = 0 ; i < 4 ; ++i )
      if( i == 0 )
        printf("%d", rotaciones[0] );
      else
        printf(" %d", rotaciones[i] );
    puts("");
  }
  return 0;
}
