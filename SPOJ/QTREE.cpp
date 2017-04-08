#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;
typedef pair < int , ii > iii;

#define MAX 10005

int N , stsize[MAX] , h[MAX] , htap[MAX] , stap[MAX] , chainHead[MAX] , chainNo , hldap[MAX] ,chainFrom[MAX] , edhld[MAX] , parent[MAX] , nohld[MAX];
vector < vector < iii > > tree;
vector < int > st_arr;
vector < int > ht;
vector < vector < int > > spt;

struct st
{
    vector < int > tree;
    int tam;

    st( vector < int > &arr )
    {
        tam = arr.size();
        tree.resize( arr.size() << 2 );
        build(0 , tam - 1 , 0 , arr);
    }

    void build( int low , int high , int pos , vector < int > &arr )
    {
        if( low == high )
        {
            tree[pos] = arr[low];
            return;
        }
        int mid = ( low + high ) >> 1;
        int left = ( pos << 1 ) | 1;
        int right = 1 + left;
        build( low , mid , left , arr);
        build(1 + mid , high , right , arr);
        tree[pos] = max(tree[left] , tree[right]);
    }

    void update( int low , int high , int pos , int &p , int &val )
    {
        if( p >= low && p <= high )
        {
            if( low == high )
            {
                tree[pos] = val;
                return;
            }
            int mid = (low + high) >> 1;
            int left = ( pos << 1 ) | 1;
            int right = 1 + left;
            update( low , mid , left , p , val );
            update( 1 + mid , high , right , p , val );
            tree[pos] = max( tree[left] , tree[right] );
        }
    }

    void update( int pos , int val )
    {
        update( 0 , tam - 1 , 0 , pos , val );
    }

    int query( int &qlow , int &qhigh , int low , int high , int pos )
    {
        if( low >= qlow && high <= qhigh )
            return tree[pos];
        if( qlow > high || qhigh < low )
            return -1e6;
        int mid = ( low + high ) >> 1;
        int left = ( pos << 1 ) | 1;
        int right = 1 + left;
        return max(query(qlow , qhigh , low , mid , left) , query(qlow , qhigh , 1 + mid , high , right ));
    }

    int query( int i , int j )
    {
        if( i > j )
            return 0;
        return query(i , j , 0 , tam - 1 , 0);;
    }


};

void buildspt( vector < int > &arr )
{
    int col = 1 + floor(log2(arr.size()));
    spt.assign( arr.size() , vector < int > (col , 0) );
    for( int i = 0 ; i < arr.size() ; ++i ) spt[i][0] = arr[i];
    for( int j = 1 ; j < col ; ++j )
        for( int i = 0 ; i < arr.size() && i + ( 1 << j ) <= arr.size() ; ++i )
        {
            spt[i][j] = spt[i][j-1];
            if(h[spt[i + ( 1 << (j - 1) )][j-1]] < h[spt[i][j]])
                spt[i][j] = spt[i + ( 1 << (j - 1) )][j-1];
        }
}

int queryspt( int i , int j )
{
    if( i > j )
        swap(i,j);
    int len = 1 + j - i;
    int k = floor(log2(len));
    return h[spt[i][k]] < h[spt[i + len - ( 1 << k )][k]] ? spt[i][k] : spt[i + len - ( 1 << k )][k];
}

int dfs( int u , int alt = 0 )
{
    h[u] = alt;
    htap[u] = ht.size();
    ht.push_back(u);
    int v;
    stsize[u] = 1;
    for( int i = 0 ; i < tree[u].size() ; ++i )
    {
        v = tree[u][i].first;
        if( parent[u] == v )    continue;
        parent[v] = u;
        stsize[u] += dfs(v , 1 + alt );
        ht.push_back(u);
    }
    return stsize[u];
}

int hldquery( int u , int v , st &segment_tree ) // u is parent of v
{
    int uchain = chainFrom[u] , vchain;
    int ans = -1e6;
    while(1)
    {
        vchain = chainFrom[v];
        if( uchain == vchain )
        {
            ans = max(ans , segment_tree.query(1 + nohld[u],nohld[v]) );
            break;
        }
        ans = max(ans , segment_tree.query(nohld[chainHead[vchain]],nohld[v]) );
        v = parent[chainHead[vchain]];
    }
    return ans;
}

int query( int u , int v , st &s )
{
    int lca = queryspt(htap[u] , htap[v]);
    return max( hldquery(lca,u,s) , hldquery(lca,v,s) );
}

void hld( int u , int c = -1 , int id = -1 )
{
    nohld[u] = st_arr.size();
    if( id != -1 )
        edhld[id] = st_arr.size();
    st_arr.push_back(c);
    chainFrom[u] = chainNo;
    if( chainHead[chainNo] == -1 )
        chainHead[chainNo] = u;
    int sc = - 1, v , scc, sccid;
    for( int i = 0 ; i < tree[u].size() ; ++i )
    {
        v = tree[u][i].first;
        if( v == parent[u] ) continue;
        if( sc == - 1 || stsize[v] > stsize[sc] )
        {
            sc = v;
            scc = tree[u][i].second.first;
            sccid = tree[u][i].second.second;
        }
    }
    if( sc != -1 )
        hld(sc , scc , sccid);
    for( int i = 0 ; i < tree[u].size() ; ++i )
    {
        v = tree[u][i].first;
        if( v == sc || v == parent[u] )   continue;
        ++chainNo;
        hld(v , tree[u][i].second.first , tree[u][i].second.second);
    }
}

int main()
{
    char op[20];
    int a,b;
    int t , u , v , c;
    scanf("%d" , &t);
    while(t--)
    {
        chainNo = 0;
        memset(chainHead , -1 , sizeof chainHead);
        ht.clear();
        scanf("%d" , &N);
        tree.assign( N , vector < iii >() );
        for( int i = 0 ; i < N - 1 ; ++i )
        {
            scanf("%d %d %d" , &u , &v , &c );
            tree[--u].push_back(iii(--v,ii(c,i)));
            tree[v].push_back(iii(u,ii(c,i)));
        }
        dfs(0);
        hld(0);
        buildspt(ht);
        st segment_tree(st_arr);
        while(scanf("%s" , op) , op[0] != 'D')
        {
            scanf("%d %d" , &a , &b);
            if( op[0] == 'C' )
                segment_tree.update(edhld[--a],b);
            else
                printf("%d\n" , query(--a,--b,segment_tree));
        }
    }
	return 0;
}
