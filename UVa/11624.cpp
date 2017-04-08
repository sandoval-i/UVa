#include <bits/stdc++.h>

using namespace std;

#define MAX_R 1010
#define MAX_C 1010
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
typedef pair < int , int > ii;

int R , C;
char maze[MAX_R][MAX_C];
int fire_time[MAX_R][MAX_C];
int player_time[MAX_R][MAX_C];
queue < ii > fire_bfs;
ii aux;

int dx[] = { 0 , -1 , 0 , 1 };
int dy[] = { -1 , 0 , 1 , 0 };

inline bool in( int x , int y )
{
    return x >= 0 && y >= 0 && x < R && y < C;
}

int bfs( queue < ii > &player_bfs )
{
    int x , y , x_to , y_to;
    while( !fire_bfs.empty() )
    {
        aux = fire_bfs.front();
        fire_bfs.pop();
        x = aux.first;
        y = aux.second;
        foi( i , 0 , 4 )
        {
            x_to = x + dx[i];
            y_to = y + dy[i];
            if( in( x_to , y_to ) && fire_time[x_to][y_to] == -1 && maze[x_to][y_to] != '#' )
            {
                fire_bfs.push( ii(x_to , y_to) );
                fire_time[x_to][y_to] = 1 + fire_time[x][y];
            }
        }
    }
    while( !player_bfs.empty() )
    {
        aux = player_bfs.front();
        player_bfs.pop();
        x = aux.first;
        y = aux.second;
        foi( i , 0 , 4 )
        {
            x_to = x + dx[i];
            y_to = y + dy[i];
            if( !in(x_to , y_to) )  return 1 + player_time[x][y];
            else if( player_time[x_to][y_to] == -1 && ( fire_time[x_to][y_to] == -1 || 1 + player_time[x][y] < fire_time[x_to][y_to] ) && maze[x_to][y_to] == '.' )
            {
                player_time[x_to][y_to] = 1 + player_time[x][y];
                player_bfs.push(ii(x_to , y_to));
            }
        }
    }
    return -1;
}

int main()
{
    char aux;
    int casos , ans;
    scanf("%d" , &casos);
    while( casos-- )
    {
        memset( fire_time , -1 , sizeof fire_time );
        memset( player_time , -1 , sizeof player_time );
        queue < ii > player_bfs;
        scanf("%d %d" , &R , &C);
        foi( i , 0 , R )    foi( j , 0 , C )
        {
            scanf( " %c" , &aux );
            if( aux == 'F' )
            {
                fire_time[i][j] = 0;
                fire_bfs.push( ii(i,j) );
            }
            else if( aux == 'J' )
            {
                player_time[i][j] = 0;
                player_bfs.push( ii(i,j) );
            }
            maze[i][j] = aux;
        }
        ans = bfs(player_bfs);
        if( ans == -1 ) puts("IMPOSSIBLE");
        else    printf( "%d\n" , ans );
    }
    return 0;
}
