#include <bits/stdc++.h>

using namespace std;
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

struct node {
    int sum, maxprefix, maxsuffix, maxsum;
    node() {
    }
    node(const node& other) {
        sum = other.sum;
        maxprefix = other.maxprefix;
        maxsuffix = other.maxsuffix;
        maxsum = other.maxsum;
    }
    node(node left, node right) {
        sum = left.sum + right.sum;
        maxsum = max(left.maxsuffix + right.maxprefix, max(left.maxsum, right.maxsum));
        maxprefix = max(left.maxprefix, left.sum + right.maxprefix);
        maxsuffix = max(right.maxsuffix, right.sum + left.maxsuffix);
    }
    node(int k) {
        sum = maxprefix = maxsuffix = maxsum = k;
    }
};

struct st {
    vector <node> tree;
    int tam;
    st(vector <int>& arr) {
        tam = arr.size();
        tree.resize(tam << 2);
        build(0, tam - 1, 0, arr);
    }
    void build(int low, int high, int pos, vector <int>& arr) {
        if(low == high) {
            tree[pos] = node(arr[low]);
            return;
        }
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        build(low, mid, left, arr);
        build(1 + mid, high, right, arr);
        tree[pos] = node(tree[left], tree[right]);
    }
    bool outside(int &l, int &r, int low, int high) {
        return r < low || l > high;
    }
    node query(int&l, int& r, int low, int high, int pos) {
        if(low >= l && high <= r) return tree[pos];
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        node ans;
        if(outside(l, r, low, mid))
            return query(l, r, 1 + mid, high, right);
        if(outside(l, r, 1 + mid, high))
            return query(l, r, low, mid, left);
        return node(query(l, r, low, mid, left), query(l, r, 1 + mid, high, right));
    }

    int query(int l, int r) {
        return query(l, r, 0, tam - 1, 0).maxsum;
    }
};

int main() {
    int n,q,l,r;
    scanf("%d",&n);
    vector <int> arr(n);
    foi(i,0,n)  scanf("%d",&arr[i]);
    st tree(arr);
    scanf("%d",&q);
    while(q--) {
        scanf("%d %d",&l,&r);
        printf("%d\n", tree.query(l - 1, r - 1));
    }
    return 0;
}
