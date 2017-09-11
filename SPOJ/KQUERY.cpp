#include <bits/stdc++.h>
using namespace std;
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

struct stree {
    #define mid ((low + high) >> 1)
    #define left ((pos << 1) | 1)
    #define right (1 + left)
    vector<int> tree;
    int sz;
    stree(int _sz) {
        tree.assign((sz = _sz) << 2, 0);
    }
    void inc(int& upos, int low, int high, int pos) {
        if(upos >= low && upos <= high) {
            if(low == high) {
                ++tree[pos];
                return;
            }
            inc(upos, low, mid, left);
            inc(upos, 1 + mid, high, right);
            tree[pos] = tree[left] + tree[right];
        }
    }
    void inc(int pos) {
        inc(pos, 0, sz - 1, 0);
    }
    int query(int i, int j) {
        return query(i, j, 0, sz - 1, 0);
    }
    int query(int& qlow, int qhigh, int low, int high, int pos) {
        if(low >= qlow && high <= qhigh) return tree[pos];
        if(qhigh < low || qlow > high) return 0;
        return query(qlow, qhigh, low, mid, left) + query(qlow, qhigh, 1 + mid, high, right);
    }};
struct query {
    int i,j,k,idx;
    bool operator < (const query& o) const {
        return k < o.k;
    }
};

vector<int> arr,ans;
vector<pair<int,int> > arr2;
vector<query> queries;
int n, last;

void preprocess() {
    sort(arr2.begin(), arr2.end());
    last = arr2.size() - 1;
}

void go(stree& t, int k) {
    while(arr2[last].first > k && last >= 0)
        t.inc(arr2[last--].second);
}

void solve() {
    stree t(n);
    sort(queries.rbegin(), queries.rend());
    foi(i,0,queries.size()) {
        go(t, queries[i].k);
        ans[queries[i].idx] = t.query(queries[i].i - 1, queries[i].j - 1);
    }
}

int main() {
    int q;
    scanf("%d", &n);
    arr.resize(n);
    arr2.resize(n);
    foi(i,0,n) {
        scanf("%d", &arr[i]);
        arr2[i].first = arr[i];
        arr2[i].second = i;
    }
    preprocess();
    scanf("%d", &q);
    queries.resize(q);
    ans.resize(q);
    foi(i,0,q) {
        scanf("%d %d %d", &queries[i].i, &queries[i].j, &queries[i].k);
        queries[i].idx = i;
    }
    solve();
    foi(i,0,q)
        printf("%d\n", ans[i]);
    return 0;
}
