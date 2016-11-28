#include <bits/stdc++.h>

using namespace std;

#define MAX_N 40
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define INF 1e8
int adjMatriz[MAX_N][MAX_N];
int min_edge;
vector < int > parent;
vector < vector < int > > adjList;
bitset < MAX_N > visited;
char ans[12];

bool bfs( int source , int target )
{
    parent.assign( 38 , -1 );
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
        foi( v , 0 , MAX_N )
        {
            if( adjMatriz[u][v] > 0 && !visited[v] )
            {
                q.push( v );
                parent[v] = u;
                visited[v] = true;
            }
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
    int total , from , to , mf , persons;
    char pcs[150];
    string linea;
    char app;
    bool works;
    while( 1 )
    {
        strcpy( ans , "__________" );
        memset( adjMatriz ,  0 , sizeof adjMatriz );
        adjList.assign( 38 , vector < int  >() );
        for( int i = 27 ; i <= 36 ; ++i )
        {
            adjList[i].push_back(37);
            adjMatriz[i][37] = 1;
        }
        total = 0;
        works = false;
        while( getline( cin , linea ) && linea.size() > 0 )
        {
            works = true;
            sscanf( linea.c_str() , "%c%d %s" , &app , &persons , &pcs );
            adjMatriz[0][app -'A' + 1] = persons;
            total += persons;
            foi( i , 0 , strlen(pcs) - 1 )
            {
                from = app -'A' + 1;
                to = pcs[i] - '0' + 27;
                adjMatriz[from][to] = 1;
            }
        }
        if( !works )    return 0;
        mf = 0;
        while(1)
        {
            if( !bfs( 0 , 37 ) ) break;
            min_edge = INF;
            augmentPath( 37 );
            mf += min_edge;
        }
        foi( i , 27 , 37 )
            foi( j , 1 , 27 )
                if( adjMatriz[i][j] == 1 )
                        ans[i - 27] = char(j - 1 + 'A');
        if( mf != total )
            cout << "!\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
