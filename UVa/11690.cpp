#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10010

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

vector < vector < int > > graph;
int money[MAX_N] , sum;
bitset < MAX_N > visited;
bool can;

void dfs( int u )
{
    sum += money[u];
    visited[u] = true;
    int v;
    foi( i , 0 , graph[u].size() )
    {
        v = graph[u][i];
        if( !visited[v] )   dfs(v);
    }
}

int main()
{
    int casos , nodes , edges , from , to;
    scanf( "%d" , &casos );
    while( casos-- )
    {
        can = true;
        scanf( "%d %d" , &nodes , &edges );
        graph.assign( nodes , vector < int >() );
        foi( i , 0 , nodes )    scanf( "%d" , &money[i]  );
        visited.reset();
        while( edges-- )
        {
            scanf( "%d %d" , &from , &to );
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for( int i = 0 ; i < nodes && can ; ++i )
            if( !visited[i] )
            {
                sum = 0;
                dfs(i);
                if( sum != 0 )  can = false;
            }
        puts( can ? "POSSIBLE" : "IMPOSSIBLE" );
    }
    return 0;
}
