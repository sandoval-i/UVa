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

ll K , area[100][100] , N , M , costo_actual , area_actual , max_area , min_costo;

pair < ll , ll > maxArea( void )
{
  max_area = min_costo = 0;
  foi( i , 0 , N )  foi( j , 0 , M )  foi( k , i , N )  foi( l , j , M )
  {
    costo_actual = area[k][l];
    area_actual = ( k - i + 1 ) * ( l - j + 1 );
    if( i > 0 ) costo_actual -= area[i-1][l];
    if( j > 0 ) costo_actual -= area[k][j-1];
    if( i > 0 && j > 0 )  costo_actual += area[i-1][j-1];
    if( costo_actual > K )
      continue;
    if( area_actual > max_area )
      max_area = area_actual , min_costo = costo_actual;
    else if( area_actual == max_area && costo_actual < min_costo )
      min_costo = costo_actual;
  }
  return pair < ll , ll >( max_area , min_costo );
}

int main()
{
  int casos , caso = 0 ;
  pair < ll , ll > ans;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%lld %lld %lld", &N , &M , &K );
    foi( i , 0 , N )  foi( j , 0 , M )
    {
      scanf("%lld", &area[i][j] );
      if( i > 0 ) area[i][j] += area[i-1][j];
      if( j > 0 ) area[i][j] += area[i][j-1];
      if( i > 0 && j > 0 )  area[i][j] -= area[i-1][j-1];
    }
    ans = maxArea();
    printf("Case #%d: %lld %lld\n", ++caso , ans.first , ans.second );
  }
  return 0;
}
