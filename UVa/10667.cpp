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

int s , casos , num_blocks , matriz[100][100] , x_inicial , y_inicial , x_final , y_final , llevo[100] , max_current , max_so_far;
bool valid;

void max1d( void )
{
  max_current = max_so_far = valid = false;
  foi( i , 0 , s )
  {
    if( llevo[i] == 0 )
    {
      ++max_so_far;
      valid = true;
    }
    else
      max_so_far = 0;
    max_current = max( max_current , max_so_far );
  }
}

int max_area( void )
{
  int maximo = 0;
  foi( i , 0 , s )
  {
    memset( llevo , 0 , sizeof llevo );
    foi( j , i , s )
    {
      foi( k , 0 , s )  llevo[k] += matriz[k][j];
      max1d();
      if( !valid )
        goto next_col;
      maximo = max( maximo , ( j - i + 1 ) * max_current );
    }
    next_col:;
  }
  return maximo;
}

int main()
{
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d", &s , &num_blocks );
    memset( matriz , 0 , sizeof matriz );
    while( num_blocks-- )
    {
      scanf("%d %d %d %d", &x_inicial , &y_inicial , &x_final , &y_final );
      --x_final;
      --y_final;
      --y_inicial;
      for( int i = --x_inicial ; i <= x_final ; ++i ) for( int j = y_inicial ; j <= y_final ; ++j ) matriz[i][j] = 1;
    }
    printf("%d\n", max_area() );
  }
  return 0;
}
