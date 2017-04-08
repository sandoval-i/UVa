#include <bits/stdc++.h>

using namespace std;

#define MAX_R 100
#define MAX_C 100

int R , C , memo[MAX_R][MAX_C] , matriz[MAX_R][MAX_C];
int _x[] = { 0 , -1 , 0 , 1 };
int _y[] = { -1 , 0 , 1 , 0 };

inline bool in( int x , int y )
{
  return x >= 0 && y >= 0 && x < R && y < C;
}

int max_run( int i , int j )
{
  if( memo[i][j] != -1 )  return memo[i][j];
  int maximo = 1;
  for( int k = 0 ; k < 4 ; ++k )
  {
    int x = i + _x[k] , y = j + _y[k];
    if( in( x , y ) && matriz[x][y] < matriz[i][j] )
      maximo = max( maximo , 1 + max_run( x , y ) );
  }
  return memo[i][j] = maximo;
}

int main()
{
  int casos , maximo;
  char name[100];
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%s %d %d", name , &R , &C );
    maximo = -1;
    memset( memo , -1 , sizeof memo );
    for( int i = 0 ; i < R ; ++i ) for( int j = 0 ; j < C ; ++j ) scanf("%d", &matriz[i][j] );
    for( int i = 0 ; i < R ; ++i )  for( int j = 0 ; j < C ; ++j )  maximo = max( maximo , max_run( i , j ) );
    printf("%s: %d\n", name , maximo );
  }
  return 0;
}
