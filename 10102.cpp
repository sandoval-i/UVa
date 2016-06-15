#include <bits/stdc++.h>

using namespace std;

typedef pair< int , int > ii;
typedef vector < ii > vii;

#define pb( i ) push_back( i )
#define foi( i , n ) for( ; i < n ; i++ )

int main()
{
  int N , i , j, actual , dist , minDistancia , maxTotal;
  char car;
  while( scanf("%d", &N ) != EOF)
  {
    maxTotal = -99;
    vii unos, tres;
    i = 0;
    foi( i , N )
    {
      j = 0;
      foi( j , N )
      {
        cin >> car;
        actual = int( car ) - '0';
        if( actual == 1 )
        unos.pb( ii( i , j ) );
        else if( actual == 3 )
        tres.pb( ii ( i , j ) );
      }
    }
    i = 0;
    foi( i , unos.size() )
    {
      j = 0;
      minDistancia = 1e9;
      foi( j , tres.size() )
      {
        dist = abs( unos[i].first - tres[j].first ) + abs( unos[i].second - tres[j].second );
          if( dist < minDistancia )
          minDistancia = dist;
      }
      if( minDistancia > maxTotal )
        maxTotal = minDistancia;
    }
    printf("%d\n", maxTotal );
  }
  return 0;
}
