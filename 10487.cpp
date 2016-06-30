#include <bits/stdc++.h>

using namespace std;

#define foi( i , n ) for( ; i < n ; i++ )

int main()
{
  int caso = 0 , n , i , j , m , actual , closest , dif;
  while( true )
  {
    scanf("%d", &n );
    vector < int > numeros( n , 0 );
    vector < int > sumas;
    if( !n )
      break;
    i = 0;
    foi( i , n )
      scanf("%d", &numeros[i] );
    sort( numeros.begin() , numeros.end() );
    i = 0;
    foi( i , numeros.size() )
    {
      j = i + 1;
      foi( j , numeros.size() )
        if( numeros[i] != numeros[j] )
          sumas.push_back( numeros[i] + numeros[j] );
    }
    scanf("%d", &m );
    printf("Case %d:\n" , ++caso );
    while( m-- )
    {
      scanf("%d", &actual );
      closest = sumas[0];
      dif = abs( actual - closest );
      i = 1;
      foi( i , sumas.size() )
        if( abs( sumas[i] - actual ) < dif )
        {
          closest = sumas[i];
          dif = abs( actual - closest );
          if( !dif )
            break;
        }
      printf("Closest sum to %d is %d.\n" , actual , closest );
    }
  }
  return 0;
}
