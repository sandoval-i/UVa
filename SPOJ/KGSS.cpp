#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;
#define INF 1e8

struct st
{
    vector < ii > tree;
    int tam;

    st(vector < int > &arr)
    {
        tam = arr.size();
        tree.assign(tam << 2, ii(0,0));
        build(0 , 0 , tam - 1 , arr);
    }

    ii get_best(ii f , ii s)
    {
        int a = f.first,b = f.second,c = s.first,d = s.second;
        int maxi = max(a , max(b , max(c,d)));
        if(a == maxi)
            return ii(maxi , max(b,max(c,d)));
        if(b == maxi)
            return ii(maxi , max(a,max(c,d)));
        if(c == maxi)
            return ii(maxi , max(a,max(b,d)));
        if(d == maxi)
            return ii(maxi , max(a,max(b,c)));
    }

    void build(int pos , int low , int high , vector < int > &arr)
    {
        if(low == high)
        {
            tree[pos].first = arr[low];
            tree[pos].second = 0;
            return;
        }
        int left = (pos << 1) | 1;
        int right = 1 + left;
        int mid = (low + high) >> 1;
        build(left , low , mid , arr);
        build(right , 1 + mid , high , arr);
        tree[pos] = get_best(tree[left] , tree[right]);
    }

    ii query(int pos , int &qlow , int &qhigh , int low , int high)
    {
        if(high < qlow || low > qhigh)
            return ii(-INF , -INF);
        if(low >= qlow && high <= qhigh)
            return tree[pos];
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        return get_best(query(left , qlow , qhigh , low , mid) , query(right , qlow , qhigh , 1 + mid , high));
    }

    ii query(int i , int j)
    {
        return query(0 , i , j , 0 , tam - 1);
    }

    void update(int pos , int &qpos , int &val , int low , int high)
    {
        if(qpos >= low && qpos <= high)
        {
            if(low == high)
            {
                tree[pos].first = val;
                return;
            }
            int mid = (low + high) >> 1;
            int left = (pos << 1) | 1;
            int right = 1 + left;
            update(left , qpos , val , low , mid);
            update(right , qpos , val , 1 + mid , high);
            tree[pos] = get_best(tree[left] , tree[right]);
        }
    }

    void update(int i , int val)
    {
        update(0 , i , val , 0 , tam - 1);
    }

};

int main()
{
    int n,q;
    while(scanf("%d" , &n) != EOF)
    {
        vector < int > arr(n);
        for(int i = 0 ; i < n ; ++i)
            scanf("%d" , &arr[i]);
        st tree(arr);
        scanf("%d" , &q);
        char p;
        int a,b;
        ii ans;
        while(q--)
        {
            scanf(" %c %d %d" , &p , &a , &b);
            if(p == 'Q')
            {
                ans = tree.query(a - 1 , b - 1);
                printf("%d\n" , ans.first  + ans.second);
            }
            else
                tree.update(a - 1 , b);
        }
    }
    return 0;
}
