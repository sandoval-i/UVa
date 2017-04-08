#include <bits/stdc++.h>

using namespace std;

#define MAX_N 105
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define INF 1e8
int num_nodos;
int adjMatriz[MAX_N][MAX_N];
int min_edge;
vector < int > parent;
bitset < MAX_N > visited;

bool bfs( int source , int target )
{
    parent.assign( num_nodos , -1 );
    queue < int > q;
    visited.reset();
    q.push( source );
    visited[source] = true;
    int u , v;
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        if( u == target )   return true;
        foi( v , 0 , num_nodos )
            if( adjMatriz[u][v] > 0 && !visited[v] )
            {
                q.push( v );
                parent[v] = u;
                visited[v] = true;
            }
    }
    return visited[target];
}

void augmentPath( int u )
{
    if( parent[u] == -1 )   return;
    min_edge = min( min_edge , adjMatriz[parent[u]][u] );
    augmentPath( parent[u] );
    adjMatriz[parent[u]][u] -= min_edge;
    adjMatriz[u][parent[u]] += min_edge;
}

int main()
{
    int s , t , c , from , to , cost , caso = 0 , mf;
    while( scanf( "%d" , &num_nodos ) , num_nodos )
    {
        scanf( "%d %d %d" , &s , &t , &c );
        memset( adjMatriz ,  0 , sizeof adjMatriz );
        while( c-- )
        {
            scanf( "%d %d %d" , &from , &to , &cost );
            adjMatriz[--from][--to] += cost;
            adjMatriz[to][from] += cost;
        }
        mf = 0;
        while(1)
        {
            if( !bfs( s - 1 , t - 1 ) ) break;
            min_edge = INF;
            augmentPath( t - 1 );
            mf += min_edge;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n" , ++caso , mf );
    }
    return 0;
}
