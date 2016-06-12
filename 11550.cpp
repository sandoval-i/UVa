#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;

#define foi( i , n ) for( ; i < n ; i++ )

int filas , columnas;

bool puede( vector < vi > &matriz )
{
  vector < vector < bool > > connected( filas , vector < bool > ( filas , false ) );
  int i , j , x , y , cont;
  i = j = 0;
  foi( i , columnas )
  {
    j = cont = 0;
    foi( j , filas )
    {
      if( matriz[j][i] == 1 )
      {
        if( ++cont == 1 )
          x = j;
        else
          y = j;
      }
    }
    if( cont != 2 )
      return false;
    if( connected[x][y] )
      return false;
    connected[x][y] = true;
    connected[y][x] = true;
  }
  return true;
}

int main()
{
  int test , i , j;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &filas , &columnas );
    vector < vi > matriz( filas , vi( columnas , 0 ) );
    i = 0;
    foi( i , filas )
    {
      j = 0;
      foi( j , columnas )
      {
        scanf("%d", &matriz[i][j] );
      }
    }
    if( puede( matriz ) )
      printf("Yes\n" );
    else
      printf("No\n" );
  }
  return 0;
}
