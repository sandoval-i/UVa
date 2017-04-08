#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define MAX_N 5010

vector < vector < int > > tree;
int p[MAX_N];
bitset < MAX_N > vis;

void dfs( int u )
{
    int v;
    foi( i , 0 , tree[u].size() )
    {
        v = tree[u][i];
        if( v == p[u] )    continue;
        p[v] = u;
        dfs(v);
    }
}

int lca_query( int u , int v )
{
    vis.reset();
    while(1)
    {
        vis[u] = true;
        if( p[u] == -1 )   break;
        u = p[u];
    }
    while(1)
    {
        if( vis[v] )    return v;
        v = p[v];
    }
}

vector < int > lca_path( int u , int lca )
{
    vector < int > ans;
    while(1)
    {
        ans.push_back(u);
        if( u == lca )  break;
        u = p[u];
    }
    return ans;
}

int main()
{
    int n , from , to , q , lca;
    while( scanf("%d" , &n) , n )
    {
        tree.assign(n , vector < int >());
        foi( i , 0 , n - 1 )
        {
            scanf( "%d %d" , &from , &to );
            tree[--from].push_back(--to);
            tree[to].push_back(from);
        }
        memset( p , -1 , sizeof p );
        dfs(0);
        scanf("%d" , &q);
        while(q--)
        {
            scanf("%d %d" , &from , &to);
            lca = lca_query(--from , --to);
            vector < int > u_path = lca_path( from , lca );
            vector < int > v_path = lca_path( to , lca );
            for( int i = v_path.size() - 2 ; i >= 0 ; --i )
                u_path.push_back(v_path[i]);
            if( u_path.size() & 1 )
                printf("The fleas meet at %d.\n" , 1 + u_path[u_path.size() >> 1] );
            else
                printf("The fleas jump forever between %d and %d.\n" , min( 1 + u_path[(u_path.size() >> 1) - 1] , 1 + u_path[u_path.size() >> 1] ) , max( 1 + u_path[(u_path.size() >> 1) - 1] , 1 + u_path[u_path.size() >> 1] ) );
        }
    }
    return 0;
}
