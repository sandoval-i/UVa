#include <bits/stdc++.h>

using namespace std;

#define MAX_M 20
#define MAX_N 20

int M , N , best , X , Y , _x[] = { 0 , -1 , 0 , 1 } , _y[] = { -1 , 0 , 1 , 0 } , visited;
char water[MAX_M][MAX_N] , tierra;

inline bool in( int x , int y )
{
  return x >= 0 && y >= 0 && x < M && y < N;
}

void dfs( int x , int y )
{
  water[x][y] = '@';
  ++visited;
  int x_to , y_to;
  for( int i = 0 ; i < 4 ; ++i )
  {
    x_to = x + _x[i];
    y_to = y + _y[i];
    if( in( x_to , y_to ) && water[x_to][y_to] == tierra )
      dfs( x_to , y_to );
  }
  if( y == N - 1 && water[x][0] == tierra )
    dfs( x , 0 );
  if( y == 0 && water[x][N-1] == tierra )
    dfs( x , N - 1 );
}

int main()
{
  char aux;
  while( scanf("%d %d", &M , &N ) != EOF )
  {
    best = 0;
    for( int i = 0 ; i < M ; ++i ) for( int j = 0 ; j < N ; ++j  ) scanf(" %c", &water[i][j] );
    scanf("%d %d", &X , &Y );
    tierra = water[X][Y];
    dfs( X , Y );
    for( int i = 0 ; i < M ; ++i )
      for( int j = 0 ; j < N ; ++j )
        if( water[i][j] == tierra )
        {
          visited = 0;
          dfs(i,j);
          best = max( best , visited );
        }
    printf("%d\n", best );
  }
  return 0;
}
