#include <bits/stdc++.h>

using namespace std;

int R, C, love_cell_x, love_cell_y, init1_x, init1_y, init2_x, init2_y, state[42][42][42][42];
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

inline bool in( int x, int y )
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

estado voy;
int pasos , x , y , xx , yy ;

void _reset( void )
{
    x = voy.x_1;
    y = voy.y_1;
    xx = voy.x_2;
    yy = voy.y_2;
}

void insert_bfs( queue < estado > &cola )
{
    if( in( x, y ) && in( xx, yy ) )
    {
        if( matriz[x][y] != '#' && matriz[xx][yy] != '#' && state[x][y][xx][yy] == -1 )
        {
            colaBFS.push( estado( x, y, xx, yy ) );
            state[x][y][xx][yy] = pasos;
        }
    }
}

void bfs()
{
    queue < estado > colaBFS;
    memset( state, -1, sizeof state );
    state[init1_x][init1_y][init2_x][init2_y] = 0;
    colaBFS.push( estado( init1_x, init1_y, init2_x, init2_y ) );
    while( !colaBFS.empty() )
    {
        voy = colaBFS.front();
        colaBFS.pop();
        if( love_cell_x == voy.x_1 && voy.x_1 == voy.x_2 && love_cell_y == voy.y_1 && voy.y_1 == voy.y_2 )
            return;
        pasos = state[voy.x_1][voy.y_1][voy.x_2][voy.y_2];
        ++pasos;
        // Move down
        _reset(); // Both down
        ++x , ++xx;
        insert_bfs(colaBFS);
        _reset(); // Left down , right stuck
        ++x;
        insert_bfs(colaBFS);
        _reset(); // Left stuck , right down
        ++xx;
        insert_bfs(colaBFS);
        // Move up
        _reset(); // Both up
        --x , --xx;
        insert_bfs(colaBFS);
        _reset(); // Left up , right stuck
        --x;
        insert_bfs(colaBFS);
        _reset(); // Left stuck , right up
        --xx;
        insert_bfs(colaBFS);
        // Move left , move right

        // Move right , move left
    }
}

int main()
{
    while( scanf( "%d %d", &R, &C ) != EOF )
    {
        scanf("%d %d %d %d %d %d", &love_cell_x, &love_cell_y, &init1_x, &init1_y, &init2_x, &init2_y );
        for( int i = 0 ; i < R ; ++i )
            for( int j = 0 ; j < C ; ++j )
                scanf( " %c", &matriz[i][j] );
        if( love_cell_x == init1_x && init1_x == init2_x && love_cell_y == init1_y && init1_y == init2_y )
        {
            puts("0");
            continue;
        }
        bfs();
        if( state[love_cell_x][love_cell_y][love_cell_x][love_cell_y] != -1 )
            printf("%d\n", state[love_cell_x][love_cell_y][love_cell_x][love_cell_y] );
        else
            puts("NO LOVE");
    }
    return 0;
}
