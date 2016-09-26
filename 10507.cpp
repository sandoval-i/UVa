#include <bits/stdc++.h>

using namespace std;

#define MAX_N 26

vector < vector < int > > grafo;
int in_degree[MAX_N];
bitset < MAX_N > awake;

int main()
{
  int N , M , consecutivo , year , id_1 , id_2;
  char conexion[4];
  bool at_least_one , wake;
  while( scanf("%d %d", &N  , &M ) != EOF )
  {
    consecutivo = year = 0;
    map < char , int > ids;
    grafo.assign( N , vector < int > () );
    awake.reset();
    scanf("%s", conexion );
    for( int i = 0 ; i < 3 ; ++i )
    {
      ids[conexion[i]] = consecutivo;
      awake[consecutivo++] = true;
    }
    for( int i = 0 ; i < M ; ++i )
    {
      scanf("%s", conexion );
      if( ids.find( conexion[0] ) == ids.end() )
        id_1 = ids[conexion[0]] = consecutivo++;
      else
        id_1 = ids[conexion[0]];
      if( ids.find( conexion[1] ) == ids.end() )
        id_2 = ids[conexion[1]] = consecutivo++;
      else
        id_2 = ids[conexion[1]];
      grafo[id_1].push_back( id_2 );
      grafo[id_2].push_back( id_1 );
    }
    year = 0;
    while(1)
    {
      at_least_one = false;
      memset( in_degree , 0 , sizeof in_degree );
      for( int i = 0 ; i < N ; ++i  )
        if( awake[i] )
          for( int j = 0 ; j < grafo[i].size() ; ++j )
            ++in_degree[grafo[i][j]];
      for( int i = 0 ; i < N ; ++i )
        if( !awake[i] && in_degree[i] >= 3 )
        {
          awake[i] = true;
          at_least_one = true;
        }
      if( !at_least_one )
        break;
      ++year;
    }
    wake = true;
    for( int i = 0 ; i < N ; ++i )
      if( !awake[i] )
      {
        puts("THIS BRAIN NEVER WAKES UP");
        wake = false;
        break;
      }
    if( wake )
      printf("WAKE UP IN, %d, YEARS\n", year );
  }
  return 0;
}
