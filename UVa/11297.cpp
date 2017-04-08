#include <bits/stdc++.h>

using namespace std;

#define INF 1e7

typedef pair < int , int > ii;

struct seg_tree
{

    vector < ii > tree;
    int tam;

    seg_tree(){}

    void create( vector < int > arr )
    {
        tam = arr.size();
        tree.resize(arr.size() << 2);
        build(0 , tam - 1 , 0 , arr );
    }

    void build( int low , int high , int pos , vector < int > &arr )
    {
        if( low == high )
        {
            tree[pos].first = tree[pos].second = arr[low];
            return;
        }
        int mid = ( low + high ) >> 1;
        int left = ( pos << 1 ) | 1;
        int right = 1 + left;
        build(low , mid , left , arr);
        build(1 + mid , high , right , arr);
        tree[pos].first = min(tree[left].first , tree[right].first);
        tree[pos].second = max(tree[left].second , tree[right].second);
    }

    ii query( int &qlow , int &qhigh , int low , int high , int pos )
    {
        if( qhigh < low || qlow > high )
            return ii( INF , -INF );
        if( low >= qlow && high <= qhigh )  return tree[pos];
        int mid = ( low + high ) >> 1;
        int left = ( pos << 1) | 1;
        int right = 1 + left;
        ii l = query( qlow , qhigh , low , mid , left );
        ii r = query( qlow , qhigh , 1 + mid , high , right );
        return ii(min( l.first , r.first ) , max( l.second , r.second ));
    }

    void update( int low , int high , int pos , int &i , int &val )
    {
        if( i >= low && i <= high )
        {
            if( low == high )
            {
                tree[pos].first = tree[pos].second = val;
                return;
            }
            int mid = ( low + high ) >> 1;
            int left = ( pos << 1 ) | 1;
            int right = 1 + left;
            update(low , mid , left , i , val);
            update(1 + mid , high , right , i , val);
            tree[pos].first = min( tree[left].first , tree[right].first );
            tree[pos].second = max( tree[left].second , tree[right].second );
        }
    }

    void update( int pos , int val )
    {
        update(0 , tam - 1 , 0 , pos , val );
    }

    ii query(int i , int j)
    {
        return query(i , j , 0 , tam - 1 , 0);
    }

};

int main()
{
    int N,Q , x1 , y1 , x2 , y2;
    ii ans , temp;
    char op;
    scanf("%d" , &N);
    vector < vector < int > > mat(N , vector < int >(N , 0) );
    for( int i = 0 ; i < N ; ++i )
        for( int j = 0 ; j < N ; ++j )
            scanf("%d" , &mat[i][j]);
    vector < seg_tree > s(N);
    for( int i = 0 ; i < N ; ++i )
        s[i].create(mat[i]);
    scanf("%d" , &Q);
    while(Q--)
    {
        scanf(" %c" , &op);
        if( op == 'q' )
        {
            scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2 );
            --x1;--x2;--y1;--y2;
            ans.first = INF;
            ans.second = -INF;
            for( int i = x1 ; i <= x2 ; ++i )
            {
                temp = s[i].query(y1,y2);
                ans.first = min(ans.first , temp.first);
                ans.second = max(ans.second , temp.second );
            }
            printf("%d %d\n" , ans.second , ans.first );
        }
        else
        {
            scanf("%d %d %d" , &x1 , &y1 , &x2 );
            --x1;--y1;
            s[x1].update(y1,x2);
        }
    }
    return 0;
}
