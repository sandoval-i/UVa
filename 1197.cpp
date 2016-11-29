#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

struct DisjointSets
{

    vector < int > parent , tam;

    DisjointSets( int n )
    {
        parent.assign( n , 0 );
        tam.assign( n , 0 );
        foi( i , 1 , n )    parent[i] = i;
    }

    int find_root( int k )
    {
        return k == parent[k] ? k : parent[k] = find_root( parent[k] );
    }

    bool connected( int i , int j )
    {
        return find_root(i) == find_root(j);
    }

    void unir( int i , int j )
    {
        int p = find_root(i) , q = find_root(j);
        if( i == j )    return;
        if( tam[p] > tam[q] )
        {
            parent[q] = p;
            tam[p] += tam[q];
        }
        else
        {
            parent[p] = q;
            tam[q] += tam[p];
        }
    }

};

int main()
{
    int n , m , k , aux , frt , group_infected , ans;
    while( scanf( "%d %d" , &n , &m ) , n || m )
    {
        ans = 0;
        DisjointSets ds( n );
        while( m-- )
        {
            scanf( "%d" , &k );
            if( k )
            {
                k--;
                scanf("%d" , &frt);
            }
            while( k-- )
            {
                scanf("%d" , &aux);
                ds.unir(aux , frt);
            }
        }
        foi( i , 0 , n )
            ans += ds.connected( i , 0 );
        printf("%d\n" , ans);
    }
    return 0;
}
