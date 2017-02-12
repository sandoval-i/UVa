#include <bits/stdc++.h>

using namespace std;

struct segment
{

    vector < unsigned short > tree;
    int tam;

    segment( vector < int > arr )
    {
        tam = arr.size();
        tree.resize(tam << 2);
        build(0 , tam - 1 , 0 , arr );
    }

    void build( int low , int high , int pos , vector < int > &arr )
    {
        if( low == high )
        {
            tree[pos] = 1 << arr[low];
            return;
        }
        int mid = ( low + high ) >> 1;
        int left = ( pos << 1 ) | 1;
        int right = 1 + left;
        build( low , mid , left , arr );
        build( 1 + mid , high , right , arr );
        tree[pos] = tree[left] | tree[right];
    }

    unsigned short query( int low , int high , int pos , int &qlow , int &qhigh )
    {
        if( high < qlow || low > qhigh )
            return 0;
        if( low >= qlow && high <= qhigh )  return tree[pos];
        int mid = ( low + high ) >> 1;
        int left = ( pos << 1 ) | 1;
        int right = 1 + left;
        return query( low , mid , left , qlow , qhigh ) | query(1 + mid , high , right , qlow , qhigh );
    }

    unsigned short query( int i , int j)
    {
        return query(0,tam - 1,0,i,j);
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,q;
    vector < int > arr;
    while( cin >> n )
    {
        arr.resize(n);
        for( int i = 0 ; i < n ; ++i )  cin >> arr[i];
        segment tree(arr);
        cin >> q;
        while(q--)
        {
            cin >> i >> j;
            cout << __builtin_popcount(tree.query(i-1,j-1)) << '\n';
        }
    }
    return 0;
}
