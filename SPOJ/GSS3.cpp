#include <bits/stdc++.h>

using namespace std;

#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

struct node {
    int tsum, msum, mprefixs, msuffixs;
    node mix(node l, node r) {
        this->tsum = l.tsum + r.tsum;
        this->mprefixs = max(l.mprefixs, l.tsum + r.mprefixs);
        this->msuffixs = max(r.msuffixs, l.msuffixs + r.tsum);
        this->msum = max(l.msum, max(r.msum, l.msuffixs + r.mprefixs));
        return *this;
    }
    node(node l, node r) {
        mix(l, r);
    }
    node() {}
    node go(int k) {
        tsum = msum = mprefixs = msuffixs = k;
        return *this;
    }
};

struct st {
    vector<node> tree;
    int sz;
    st(vector<int>& arr) {
        sz = arr.size();
        tree.resize(sz << 2);
        build(0, sz - 1, 0, arr);
    }
    node build(int low, int high, int pos, vector<int>& arr) {
        if(low == high) return tree[pos].go(arr[low]);
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        return tree[pos].mix(build(low, mid, left, arr), build(1 + mid, high, right, arr));
    }
    bool overlap(int qlow, int qhigh, int i, int j) {
        return !(qhigh < i || qlow > j);
    }
    node query(int& qlow, int& qhigh, int low, int high, int pos) {
        if(low >= qlow && high <= qhigh) return tree[pos];
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        if(overlap(qlow, qhigh, low, mid) && overlap(qlow, qhigh, 1 + mid, high))
            return node(query(qlow, qhigh, low, mid, left), query(qlow, qhigh, 1 + mid, high, right));
        if(overlap(qlow, qhigh, low, mid))
            return query(qlow, qhigh, low, mid, left);
        return query(qlow, qhigh, 1 + mid, high, right);
    }
    int query(int x, int y) {
        return query(x, y, 0, sz - 1, 0).msum;
    }
    node update(int& upos, int& val, int low, int high, int pos) {
        if(upos >= low && upos <= high) {
            if(low == high) return tree[pos].go(val);
            int mid = (low + high) >> 1;
            int left = (pos << 1) | 1;
            int right = 1 + left;
            return tree[pos].mix(update(upos, val, low, mid, left), update(upos, val, 1 + mid, high, right));
        }
        return tree[pos];
    }
    void update(int pos, int val) {
        update(pos, val, 0, sz - 1, 0);
    }
};

int main() {
    int n,q,op,x,y;
    scanf("%d", &n);
    vector<int> arr(n);
    foi(i,0,n)  scanf("%d", &arr[i]);
    st tree(arr);
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d %d", &op, &x, &y);
        if(!op)
            tree.update(x - 1, y);
        else
            printf("%d\n", tree.query(x - 1, y - 1));
    }
    return 0;
}
