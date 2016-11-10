#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define INF 1e8
typedef pair < int , int > ii;

vector < int > dijkstra( vector < vector < ii > > graph , int source )
{
    vector < int > dist( graph.size() , INF );
    dist[source] = 0;
    priority_queue < ii , vector < ii > , greater < ii > > pq;
    pq.push( ii( 0 , source ) );
    while( !pq.empty() )
    {
        ii aux = pq.top();  pq.pop();
        int node = aux.second;
        int costo = aux.first;
        if( costo > dist[node] )    continue;
        foi( i , 0 , graph[node].size() )
        {
            int costo_to = graph[node][i].second + costo;
            int node_to = graph[node][i].first;
            if( costo_to < dist[node_to] )
            {
                pq.push( ii( costo_to , node_to ) );
                dist[node_to] = costo_to;
            }
        }
    }
    return dist;
}

int main()
{
    int casos , from , to , cost;
    int N , M , s , t , p;
    int ans;
    scanf( "%d" , &casos );
    while( casos-- )
    {
        scanf( "%d %d %d %d %d" , &N , &M , &s , &t , &p );
        vector < vector < ii > > graph( N , vector < ii > () );
        vector < vector < ii > > reversed_graph( N , vector < ii > () );
        while( M-- )
        {
            scanf( "%d %d %d" , &from , &to , &cost );
            graph[--from].push_back( ii( --to , cost ) );
            reversed_graph[to].push_back( ii( from , cost ) );
        }
        vector < int > ans_graph = dijkstra( graph , --s );
        vector < int > ans_reversed_graph = dijkstra( reversed_graph , --t );
        ans = -1;
        for( int i = 0 ; i < graph.size() ; ++i )
        {
            int node_from = i;
            for( int j = 0 ; j < graph[node_from].size() ; ++j )
            {
                int node_to = graph[node_from][j].first;
                int costo_to = graph[node_from][j].second;
                if( ans_graph[node_from] + costo_to + ans_reversed_graph[node_to] <= p )
                    ans = max( ans , costo_to );
            }
        }
        printf( "%d\n" , ans );
    }
    return 0;
}
