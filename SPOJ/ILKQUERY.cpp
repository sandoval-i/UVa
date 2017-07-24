#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator it;
typedef pair<int,int> ii;

struct wt {
    struct node {
        node* left, *right;
        vector<int> mapl;
        node(int sz) : left(NULL), right(NULL), mapl(sz) {}
    };
    node* root;
    int mini, maxi;
    wt(vector<int> arr) {
        mini = LONG_MAX, maxi = LONG_MIN;
        for(const auto& u: arr) mini = min(mini, u), maxi = max(maxi, u);
        root = build(arr, mini, maxi, arr.begin(), arr.end());
    }
    int get_mapr(int idx, const vector<int>& mapl) {
        return 1 + idx - mapl[idx];
    }
    ii map_it(const int& i, const int& j, const vector<int>& mapl, bool f = false) {
        return f ? ii(i ? get_mapr(i - 1, mapl): 0, get_mapr(j, mapl) - 1) : ii(i ? mapl[i - 1] : 0, mapl[j] - 1);
    }
    int kth(int i, int j, int k) {
        int c, mid, low = mini, high = maxi;
        node* curr = root;
        ii l, r;
        for(;;) {
            if(low == high) return low;
            mid = (low + high) >> 1;
            l = map_it(i, j, curr->mapl);
            r = map_it(i, j, curr->mapl, true);
            c = curr->mapl[j] - (i ? curr->mapl[i - 1] : 0);
            if(k <= c) i = l.first, j = l.second, curr = curr->left, high = mid;
            else i = r.first, j = r.second, curr = curr->right, low = 1 + mid, k -= c;
        }
    }
    node* build(const vector<int>& arr, int low, int high, it s, it e) {
        node *n = new node(e - s);
        if(low == high) return n;
        int mid = (low + high) >> 1, i = 0;
        for(it u = s; u != e; ++u, ++i)
                n->mapl[i] = (*u <= mid) + (i ? n->mapl[i - 1] : 0);
        it m = stable_partition(s, e, [=](int k){return k<=mid;});
        n->left = build(arr, low, mid, s, m);
        n->right = build(arr, 1 + mid, high, m, e);
        return n;
    }
};

int main() {
    int N,Q,k,i,l, cons = 0;
    unordered_map<int,int> to_id;
    scanf("%d %d", &N, &Q);
    vector<int> arr(N), arr2(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }
    sort(arr2.begin(), arr2.end());
    for(const auto& u: arr2)
        if(!to_id.count(u))
            to_id[u] = cons++;
    for(auto& u: arr)
        u = to_id[u];
    vector<vector<int>> adj(cons, vector<int>());
    for(int i = 0; i < N; ++i)
        adj[arr[i]].push_back(i);
    wt tree(arr);
    while(Q--) {
        scanf("%d %d %d", &k, &i, &l);
        k = tree.kth(0, i, k);
        printf("%d\n", l <= (int)adj[k].size() ? adj[k][l - 1] : -1);
    }
}
