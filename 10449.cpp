#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define MAX_NUM_NODOS 205
#define INF 1e8
typedef pair < int , int > ii;

vector < ii > edges;
vector < vector < int > > graph;
vector < int > dist;
bitset < MAX_NUM_NODOS > cycle;
bitset < MAX_NUM_NODOS > visited_source;
bitset < MAX_NUM_NODOS > negative_cycle;
int num_nodos;
int busyness[MAX_NUM_NODOS];

void dfs( int u , bitset < MAX_NUM_NODOS > &visited )
{
    visited[u] = true;
    foi( i , 0 , graph[u].size() )
    {
        int v = graph[u][i];
        if( !visited[v] )   dfs(v , visited);
    }
}

void bellman_ford()
{
    dist.assign( num_nodos , INF );
    dist[0] = 0;
    cycle.reset();
    foi( i , 0 , num_nodos - 1 )
        foi( j , 0 , edges.size() )
        {
            int from = edges[j].first;
            int to = edges[j].second;
            if( dist[from] + ( busyness[to] - busyness[from] ) < dist[to] )
                dist[to] = dist[from] + ( busyness[to] - busyness[from] );
        }
    foi( i , 0 , edges.size() )
    {
        int from = edges[i].first;
        int to = edges[i].second;
        if( dist[from] + ( busyness[to] - busyness[from] ) < dist[to] )
        {
            cycle[to] = true;
            cycle[from] = true;
        }
    }
}

int main()
{
    int num_edges , from , to , q , query , caso = 0;
    while( scanf( "%d" , &num_nodos ) != EOF )
    {
        foi( i , 0 , num_nodos )    scanf( "%d" , &busyness[i] );
        graph.assign( num_nodos , vector < int >() );
        edges.clear();
        scanf( "%d" , &num_edges );
        while( num_edges-- )
        {
            scanf( "%d %d" , &from , &to );
            edges.push_back( ii(--from , --to) );
            graph[from].push_back(to);
        }
        bellman_ford();
        visited_source.reset();
        negative_cycle.reset();
        dfs( 0 , visited_source );
        foi( i , 0 , num_nodos )
            if( visited_source[i] && cycle[i] )
                    dfs( i , negative_cycle );
        scanf( "%d" , &q );
        printf( "Set #%d\n" , ++caso );
        while( q-- )
        {
            scanf( "%d" , &query );
            --query;
            if( dist[query] < 3 || negative_cycle[query] ) puts( "?" );
            else    printf( "%d\n" , dist[query] );
        }
    }
    return 0;
}
