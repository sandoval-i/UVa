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

int M , N , matriz[100][100] , llevo[100] , maximo1D , llevo_ahora;
bool at_least_one;

void maxSum1D( int &tam )
{
  maximo1D = llevo_ahora = 0;
  foi( i , 0 , tam )
  {
    if( llevo[i] == 0 )
      ++llevo_ahora;
    else  llevo_ahora = 0;
    maximo1D = max( maximo1D , llevo_ahora );
  }
}

int max_area( void )
{
  int maxima_area = 0;
  foi( i , 0 , N )
  {
    memset( llevo , 0 , sizeof llevo );
    foi( j , i , N )
    {
      foi( p , 0 , M )  llevo[p] += matriz[p][j];
      maxSum1D( M );
      if( maximo1D == 0 )
        goto next_col;
      maxima_area = max( maxima_area , maximo1D * ( j - i + 1 ) );
    }
    next_col:
    ;
  }
  return maxima_area;
}

int main()
{
  while( scanf("%d %d", &M , &N ) , M || N )
  {
    foi( i , 0 , M )  foi( j , 0 , N ) scanf("%d", &matriz[i][j] );
    printf("%d\n", max_area() );
  }
  return 0;
}
