#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define MAX_N 10010
#define MOD 10000

vector < int > add;
int dist[MAX_N];

int bfs( int source , int target )
{
    memset( dist , -1 , sizeof dist);
    int u , v;
    queue < int > q;
    q.push( source );
    dist[source] = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( u == target )   return dist[u];
        foi( i , 0 , add.size() )
        {
            v = (u + add[i]) % MOD;
            if( dist[v] == -1 )
            {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }

    }
    return -1;
}

int main()
{
    int R , L , U , ans , caso = 0 , aux;
    while( scanf("%d %d %d" , &L , &U , &R) , L || U || R )
    {
        add.clear();
        foi( i , 0 , R )
        {
            cin >> aux;
            add.push_back(aux);
        }
        ans = bfs(L,U);
        printf("Case %d: " , ++caso);
        if( ans == -1 ) puts("Permanently Locked");
        else    printf("%d\n" , ans);
    }
}
