#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int R, C, love_cell_x, love_cell_y, init1_x, init1_y, init2_x, init2_y;
short state[42][42][42][42];
int pinguino1_x_libre[] = { -1 , 1 , 0 , 0 } , pinguino1_y_libre[] = { 0 , 0 , 1 , -1 };
int pinguino2_x_libre[] = { -1 , 1 , 0 , 0 } , pinguino2_y_libre[] = { 0 , 0 , -1 , 1 };
char matriz[42][42];

struct estado
{
  int x_1, y_1, x_2, y_2;
  estado( int x, int y, int xx, int yy ) : x_1(x), y_1(y), x_2(xx), y_2(yy) {}
  estado()
  {
    x_1 = y_1 = x_2 = y_2 = 0;
  }
};

int bfs()
{
  queue < estado > colaBFS;
  memset( state, -1, sizeof state );
  state[init1_x][init1_y][init2_x][init2_y] = /*state[init2_x][init2_y][init1_x][init1_y] = */0;
  colaBFS.push( estado( init1_x, init1_y, init2_x, init2_y ) );
  estado voy;
  int pasos , x_p1 , y_p1 , x_p2 , y_p2;
  while( !colaBFS.empty() )
  {
    if( state[love_cell_x][love_cell_y][love_cell_x][love_cell_y] != -1 )
      return state[love_cell_x][love_cell_y][love_cell_x][love_cell_y];
    voy = colaBFS.front();
    colaBFS.pop();
    pasos = state[voy.x_1][voy.y_1][voy.x_2][voy.y_2];
    ++pasos;
    for( int i = 0 ; i < 4 ; ++i )
    {
      x_p1 = voy.x_1 + pinguino1_x_libre[i];
      y_p1 = voy.y_1 + pinguino1_y_libre[i];
      x_p2 = voy.x_2 + pinguino2_x_libre[i];
      y_p2 = voy.y_2 + pinguino2_y_libre[i];
      if( matriz[x_p1][y_p1] != '#' && matriz[x_p2][y_p2] != '#' && state[x_p1][y_p1][x_p2][y_p2] == -1 )
      {
        colaBFS.push( estado( x_p1, y_p1, x_p2, y_p2 ) );
        state[x_p1][y_p1][x_p2][y_p2] = pasos;
        //state[x_p2][y_p2][x_p1][y_p1] = pasos;
        continue;
      }
      if( matriz[x_p1][y_p1] != '#' && matriz[x_p2][y_p2] == '#' && state[x_p1][y_p1][voy.x_2][voy.y_2] == -1 )
      {
        colaBFS.push( estado( x_p1 , y_p1 , voy.x_2 , voy.y_2 ) );
        state[x_p1][y_p1][voy.x_2][voy.y_2] = pasos;
        //state[voy.x_2][voy.y_2][x_p1][y_p1] = pasos;
        continue;
      }
      if( matriz[x_p1][y_p1] == '#' && matriz[x_p2][y_p2] != '#' && state[voy.x_1][voy.y_1][x_p2][y_p2] == -1  )
      {
        colaBFS.push( estado( voy.x_1, voy.y_1 , x_p2, y_p2 ) );
        state[voy.x_1][voy.y_1][x_p2][y_p2] = pasos;
        //state[x_p2][y_p2][voy.x_1][voy.y_1] = pasos;
        continue;
      }
    }
  }
  return -1;
}

int main()
{
  int ans;
  while( scanf( "%d %d", &R, &C ) != EOF )
  {
    scanf("%d %d %d %d %d %d", &love_cell_x, &love_cell_y, &init1_x, &init1_y, &init2_x, &init2_y );
    for( int i = 0 ; i <= R+1  ; ++i )
    {
      matriz[i][C+1]='#';
      matriz[i][0]='#';
    }
    for( int i = 0 ; i <= C+1  ; ++i )
    {
      matriz[R+1][i]='#';
      matriz[0][i]='#';
    }
    for( int i = 1 ; i <= R ; ++i )
      for( int j = 1 ; j <= C ; ++j )
        scanf( " %c", &matriz[i][j] );
    ans = bfs();
    if( ans != -1 )
      printf("%d\n", ans );
    else
      puts("NO LOVE");
  }
  return 0;
}

