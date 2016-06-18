#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;

#define size size()
#define foi( i , n ) for( int i = 0 ; i < n ; i++  )

vector < vi > productos;
vector < vi > dp;
int M;

int backtrack( int money , int garment )
{
  if( money > M )
    return -1;
  if( garment == productos.size )
    return money;
  if( dp[garment][money] != -1 )
    return dp[garment][money];
  int maximo = -1;
  foi( i , productos[garment].size )
    maximo = max( maximo , backtrack( money + productos[garment][i] , garment + 1 ) );
  dp[garment][money] = maximo;
  return maximo;
}

int main()
{
  int N , C , total , num , actual;
  scanf("%d", &N );
  while( N-- )
  {
    scanf("%d%d", &M , &C );
    productos.assign( C , vi()  );
    foi( i , C )
    {
      scanf("%d", &num );
      productos[i].assign( num , 0 );
      foi( b , num )
        scanf("%d", &productos[i][b] );
    }
    dp.assign( C + 1 , vi(  M + 1 , -1 ) );
    total = backtrack( 0 , 0 );
    if( total != -1 )
      printf("%d\n", total );
    else
      printf("no solution\n" );
  }
  return 0;
}
