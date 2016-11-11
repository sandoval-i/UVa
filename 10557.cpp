#include <bits/stdc++.h>

using namespace std;

#define MAX_NODOS 105
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define INF 1e8
typedef pair < int , int > ii;

int num_nodos;
int costo_node[MAX_NODOS];
vector < ii > graph;
vector < vector < int > > adjList;
bitset < MAX_NODOS > cycle , can_source , can_to_target;

void dfs( int u , bitset < MAX_NODOS > &visited )
{
    visited[u] = true;
    foi( i , 0 , adjList[u].size() )
    {
        int v = adjList[u][i];
        if( !visited[v] )
                dfs(v , visited);
    }
}

bool cycle_on_path()
{
    can_source.reset();
    dfs(0 , can_source);
    foi( i , 0 , num_nodos )
        if( cycle[i] && can_source[i] )
        {
            can_to_target.reset();
            dfs( i , can_to_target );
            if( can_to_target[num_nodos-1] )    return true;
        }
    return false;
}

bool bellman_ford()
{
    vector < int > dist( num_nodos , -INF );
    cycle.reset();
    dist[0] = 100;
    int from , to;
    foi( i , 0 , num_nodos - 1 )
        foi( j , 0 , graph.size() )
        {
            from = graph[j].first;
            to = graph[j].second;
            if( dist[from] + costo_node[to] > dist[to] && dist[from] > 0 )
                dist[to] = dist[from] + costo_node[to];
        }
    foi( j , 0 , graph.size() )
    {
        from = graph[j].first;
        to = graph[j].second;
        if( dist[from] + costo_node[to] > dist[to] && dist[from] > 0 )
        {
            cycle[from] = true;
            cycle[to] = true;
        }
    }
    return dist[num_nodos - 1] > 0 || cycle_on_path();
}

int main()
{
    int num_edges , costo , to;
    while( scanf("%d" , &num_nodos) , num_nodos != -1 )
    {
        graph.clear();
        adjList.assign( num_nodos , vector < int > () );
        foi( i , 0 , num_nodos )
        {
            scanf( "%d %d" , &costo_node[i] , &num_edges );
            while( num_edges-- )
            {
                scanf( "%d" , &to );
                graph.push_back( ii( i , --to ) );
                adjList[i].push_back(to);
            }
        }
        puts( bellman_ford() ? "winnable" : "hopeless" );
    }
    return 0;
}
