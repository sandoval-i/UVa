#include <bits/stdc++.h>

using namespace std;

#define MAX_N 55
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define INF 1e7

int adjMat[MAX_N << 1][MAX_N << 1];
int cost[MAX_N];
int p[MAX_N << 1];
int f;
bitset < MAX_N << 1 > visited;
vector < vector < int > > graph;
int M;

void addEdge( int u , int v , int c )
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    adjMat[u][v] += c;
}

int out( int n )
{
    return n + M;
}

bool bfs( int source , int target )
{
    int u , v;
    visited.reset();
    visited[source] = true;
    queue < int > q;
    q.push(source);
    p[source] = -1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( u == target )   return true;
        foi( i , 0 , graph[u].size() )
        {
            v = graph[u][i];
            if( !visited[v] && adjMat[u][v] > 0 )
            {
                visited[v] = true;
                q.push(v);
                p[v] = u;
            }
        }
    }
    return false;
}

void augmentPath( int u )
{
    if( p[u] == -1 )    return;
    f = min( f , adjMat[p[u]][u] );
    augmentPath(p[u]);
    adjMat[p[u]][u] -= f;
    adjMat[u][p[u]] += f;
}

int edmonds( int source , int target )
{
    int mf = 0;
    while(bfs(source , target))
    {
        f = INF;
        augmentPath(target);
        mf += f;
    }
    return mf;
}

int main()
{
    int W , id , costo , ans , from , to , a , b;
    while( scanf("%d %d" , &M , &W) , M || W )
    {
        ans = 0;
        memset( adjMat , 0 , sizeof adjMat );
        graph.assign( M << 1 , vector < int >() );
        foi( i , 0 , M - 2 )
        {
            scanf("%d %d" , &id , &costo );
            cost[id - 1] = costo;
        }
        while(W--)
        {
            scanf("%d %d %d" , &from , &to , &costo );
            addEdge(out(--from) , --to , costo);
            addEdge(out(to) , from , costo);
        }
        foi( i , 0 , M )
            addEdge( i , out(i) , i == 0 || i == M - 1 ? INF : cost[i]);
        printf("%d\n" , edmonds( 0 , graph.size() - 1 ));
    }
    return 0;
}
