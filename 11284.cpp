#include <bits/stdc++.h>

using namespace std;

#define MAX_N 52
#define INF 1e8

pair < int , int > dvd[15]; // 1. store , 2. saving
int dist[MAX_N][MAX_N];
int memo[15][1 << 15];

int n , m , p;

int dp( int i , int btm )
{
    int u = dvd[i].first ,v;
    int ans = dvd[i].second - dist[u][0];
    if( memo[i][btm] != -1 )    return memo[i][btm];
    if( btm == ( ( 1 << p ) - 1 ) )
        return ans;
    for( int k = 0 ; k < p ; ++k )
    {
        v = dvd[k].first;
        if( btm & ( 1 << k ) || dist[u][v] >= INF )  continue;
        ans = max( ans , dp( k , btm | ( 1 << k ) ) + dvd[i].second - dist[u][v] );
    }
    return memo[i][btm] = ans;
}

int main()
{
    int tc , from , to;
    double cost;
    scanf("%d" , &tc);
    while(tc--)
    {
        memset(memo , -1 , sizeof memo);
        memset(dist , 0x3f3f3f3f , sizeof dist);
        scanf("%d %d" , &n , &m );
        for( int i = 0 ; i <= n ; ++i )
                dist[i][i] = 0;
        while( m-- )
        {
            scanf("%d %d %lf" , &from , &to , &cost );
            dist[from][to] = dist[to][from] = min( dist[from][to] , (int)round(cost * 100.0) );
        }
        scanf("%d" , &p);
        for( int i = 0 ; i < p ; ++i )
        {
            scanf("%d %lf" , &dvd[i].first , &cost );
            dvd[i].second = round(cost * 100.0);
        }
        for( int k = 0 ; k <= n ; ++k )
            for( int i = 0 ; i <= n ; ++i )
                for( int j = 0 ; j <= n ; ++j )
                    dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j] );
        int ans = -1;
        for( int i = 0 ; i < p ; ++i )
            ans = max( ans , dp( i , 1 << i ) - dist[0][dvd[i].first] );
        if( ans > 0 )
            printf("Daniel can save $%.2lf\n" , ans / 100.0 );
        else    puts("Don't leave the house");
    }
    return 0;
}
