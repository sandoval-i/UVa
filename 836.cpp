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

int matriz[25][25] , N , llevo[25] , max_so_far , dim;
bool valid;

void max_1d( void )
{
  dim = max_so_far = 0;
  foi( i , 0 , N )
  {
    if( llevo[i] == 0 )
    {
      ++dim;
      valid = true;
    }
    else
      dim = 0;
    max_so_far = max( max_so_far , dim );
  }
}

int max_area( void )
{
  int maximo = 0;
  foi( i , 0 , N )
  {
    memset( llevo , 0 , sizeof llevo );
    foi( j , i , N )
    {
      foi( k , 0 , N )  llevo[k] += matriz[k][j];
      valid = false;
      max_1d();
      if( !valid )
        goto next_col;
      maximo = max( maximo , ( j - i + 1 ) * max_so_far );
    }
    next_col:;
  }
  return maximo;
}

int main()
{
  int cases , linea_voy;
  string linea;
  scanf("%d", &cases );
  cin.ignore( 1000000 , '\n' );
  cin.ignore( 1000000 , '\n' );
  while( cases-- )
  {
    linea_voy = 0;
    while( getline( cin , linea ) , linea != "" )
    {
      N = linea.size;
      foi( i , 0 , linea.size )
        matriz[linea_voy][i] = linea[i] == '1' ? 0 : 1;
      ++linea_voy;
    }
    printf("%d\n", max_area() );
    if( cases )
      puts( "" );
  }
  return 0;
}
