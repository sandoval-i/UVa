#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = (int)n ; i < (int)k ; ++i )
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
    for( int i = 0 ; i < graph[u].size() ; ++i )
    {
        int v = graph[u][i];
        if( !visited[v] )   dfs(v , visited);
    }
}

void bellman_ford()
{
    dist.assign( num_nodos + 1 , INF );
    dist[1] = 0;
    cycle.reset();
    for( int i = 0 ; i < num_nodos - 1 ; ++i )
        for( int j = 0 ; j < edges.size() ; ++j )
        {
            int from = edges[j].first;
            int to = edges[j].second;
            int cost = ( busyness[to] - busyness[from] ) * ( busyness[to] - busyness[from] ) * ( busyness[to] - busyness[from] );
            if( dist[from] + cost < dist[to] )
                dist[to] = dist[from] + cost;
        }
    for( int i = 0 ; i < edges.size() ; ++i )
    {
        int from = edges[i].first;
        int to = edges[i].second;
        int cost = ( busyness[to] - busyness[from] ) * ( busyness[to] - busyness[from] ) * ( busyness[to] - busyness[from] );
        if( dist[from] + cost < dist[to] )
        {
            cycle[to] = true;
            cycle[from] = true;
        }
    }
}

int main()
{
    int num_edges , from , to , q , query , caso = 0;
    while( scanf( "%d" , &num_nodos ) == 1 )
    {
        for( int i = 1 ; i <= num_nodos ; ++i )    scanf( "%d" , &busyness[i] );
        graph.assign( num_nodos + 1 , vector < int >() );
        edges.clear();
        scanf( "%d" , &num_edges );
        while( num_edges-- )
        {
            scanf( "%d %d" , &from , &to );
            edges.push_back( ii(from , to) );
            graph[from].push_back(to);
        }
        bellman_ford();
        visited_source.reset();
        negative_cycle.reset();
        dfs( 1 , visited_source );
        for( int i = 1 ; i <= num_nodos ; ++i )
            if( visited_source[i] && cycle[i] && !negative_cycle[i] )
                    dfs( i , negative_cycle );
        scanf( "%d" , &q );
        printf( "Set #%d\n" , ++caso );
        while( q-- )
        {
            scanf( "%d" , &query );
            if( negative_cycle[query] || dist[query] == INF || dist[query] < 3 ) puts( "?" );
            else    printf( "%d\n" , dist[query] );
        }
    }
    return 0;
}

