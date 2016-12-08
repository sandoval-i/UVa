#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef pair < int , ull > ii;

#define MAX_N 100010
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
vector < vector < ii > > graph;
ull path_sum[MAX_N];
int frs_oc[MAX_N];
int height[MAX_N];
vector < vector < int > > st;

void build( vector < int > &ocurrences )
{
    int columns = 1 + floor( log2(ocurrences.size()));
    st.assign( ocurrences.size() , vector < int >( columns , -1) );
    foi( i , 0 , ocurrences.size() )    st[i][0] = ocurrences[i];
    for( int j = 1 ; j < columns ; ++j )
        for( int i = 0 ; i + ( 1 << j ) - 1 < ocurrences.size() ; ++i )
            if( height[st[i + ( 1 << ( j - 1) )][j-1]] < height[st[i][j-1]] )
                st[i][j] = st[i + ( 1 << ( j - 1) )][j-1];
            else
                st[i][j] = st[i][j-1];
}

int query_st( int i , int j )
{
    if( i > j ) swap(i,j);
    int len = j - i + 1;
    int k = floor(log2(len));
    return height[st[i][k]] < height[st[i + len - ( 1 << k )][k]] ? st[i][k] : st[i + len - ( 1 << k )][k];
}

void dfs( int u , int alt , ull sum , int prev , vector < int > &ocurrences)
{
    frs_oc[u] = ocurrences.size();
    height[u] = alt;
    path_sum[u] = sum;
    ocurrences.push_back(u);
    int v;
    foi( i , 0 , graph[u].size() )
    {
        v = graph[u][i].first;
        if( v == prev ) continue;
        dfs(v , 1 + alt , sum + graph[u][i].second , u , ocurrences);
        ocurrences.push_back(u);
    }
}

ull query( int from , int  to )
{
    return path_sum[from] + path_sum[to] - 2ULL * path_sum[query_st(frs_oc[from] , frs_oc[to])];
}

int main()
{
    int n , to , q , from;
    ull cost;
    while( scanf("%d" , &n) , n )
    {
        graph.assign( n , vector < ii >() );
        foi( i , 1 , n )
        {
            scanf("%d %llu" , &to , &cost);
            graph[i].push_back( ii(to , cost) );
            graph[to].push_back( ii(i , cost) );
        }
        vector < int > ocurrences;
        dfs(0 , 0 , 0ULL , -1 , ocurrences);
        build(ocurrences);
        scanf("%d" , &q);
        while(q--)
        {
            scanf("%d %d" , &from , &to);
            printf( "%llu" , query( from , to ) );
            if( q > 0 ) printf(" ");
        }
        puts("");
    }
    return 0;
}
