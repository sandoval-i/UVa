#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int cnt[1000001];

void divisors() {
    for(int i = 1; i <= 1e6; ++i)
        for(int j = i; j <= 1e6; j += i)
            ++cnt[j];
}

struct stree {
    int sz;
    vector<int> tree;
    stree(int* arr, int n) {
        sz = n;
        tree.resize(n << 2);
        build(1, n - 1, 0, arr);
    }
    int build(int low, int high, int pos, int* arr) {
        int mid = (low + high) >> 1, left = (pos << 1) | 1, right = 1 + left;
        return tree[pos] = low == high ? arr[low] : max(build(low, mid, left, arr), build(1 + mid, high, right, arr));
    }
    ii query(int& qhigh, int low, int high, int pos) {
        if(low > qhigh) return ii(-1, -1);
        if(low == high) return ii(tree[pos], low);
        int ans = tree[pos], mid = (low + high) >> 1, left = (pos << 1) | 1, right = 1 + left;
        ii l, r;
        if(high <= qhigh)
            return tree[right] == ans ? query(qhigh, 1 + mid, high, right) : query(qhigh, low, mid, left);
        l = query(qhigh, low, mid, left);
        r = query(qhigh, 1 + mid, high, right);
        if(l.first == r.first)
            return l.second > r.second ? l : r;
        return l.first > r.first ? l : r;
    }
    int query(int k) {return query(k, 1, sz - 1, 0).second;}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    divisors();
    stree st(cnt, 1 + 1e6);
    int t,k;
    cin >> t;
    while(t--) {
        cin >> k;
        cout << st.query(k) << '\n';
    }
    return 0;
}
