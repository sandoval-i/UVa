#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
int sz;
struct pst {
    struct node {
        node* l, *r;
        int val;
        node(const node& o) {
            l = o.l;
            r = o.r;
            val = o.val;
        }
        node() {
            l = r = NULL;
            val = 0;
        }};
    node* root;
    pst() {
        root = build(0, sz - 1);
    }
    pst(node* _new) {
        root = _new;
    }
    node* build(int low, int high) {
        node* n = new node;
        if(low != high) {
            int mid = (low + high) >> 1;
            n->l = build(low, mid);
            n->r = build(1 + mid, high);
            n->val = n->l->val + n->r->val;
        }
        return n;
    }
    int query(int& qlow, int& qhigh, int low, int high, node* curr) {
        if(high < qlow || low > qhigh) return 0;
        if(low >= qlow && high <= qhigh) return curr->val;
        int mid = (low + high) >> 1;
        return query(qlow, qhigh, low, mid, curr->l) + query(qlow, qhigh, 1 + mid, high, curr->r);
    }
    int query(int i, int j) {
        return query(i, j, 0, sz - 1, root);
    }
    node* update(int upos) {
        return update(upos, 0, sz - 1, root);
    }
    node* update(int& upos, int low, int high, node* curr) {
        int mid = (low + high) >> 1;
        node* n = new node(*curr);
        if(low == high)
            n->val = 1 + curr->val;
        else {
            if(upos <= mid)
                n->l = update(upos, low, mid, curr->l);
            else
                n->r = update(upos, 1 + mid, high, curr->r);
            n->val = n->l->val + n->r->val;
        }
        return n;
    }};

vector<int> arr, arr2;
vector<pst> trees;
map<int,int> m;
int n;

void preprocess2() {
    trees.push_back(pst());
    for(int i = n - 1; i >= 0; --i)
        trees.push_back(trees.back().update(arr[i]));
    reverse(trees.begin(), trees.end());
}

void preprocess() {
    arr2.resize(n);
    foi(i,0,n)
        arr2[i] = arr[i];
    sort(arr2.begin(), arr2.end());
    sz = 0;
    foi(i,0,n)
        if(!m.count(arr2[i]))
            m[arr2[i]] = sz++;
    foi(i,0,n)
        arr[i] = m[arr[i]];
    preprocess2();
}

int solve(int i, int j, int k) {
    if(i < 1) i = 1;
    if(j > n) j = n;
    if(i > j) return 0;
    --i;--j;
    map<int,int>::iterator it = m.upper_bound(k);
    if(it == m.end()) return 0;
    int pos = it->second;
    return trees[i].query(pos, sz - 1) - trees[1 + j].query(pos, sz - 1);
    return 0;
}

int main() {
    int q,i,j,k,last_ans = 0, ans;
    scanf("%d", &n);
    arr.resize(n);
    foi(o,0,n) scanf("%d", &arr[o]);
    preprocess();
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d %d", &i, &j, &k);
        ans = solve(i ^ last_ans, j ^ last_ans, k ^ last_ans);
        printf("%d\n", ans);
        last_ans = ans;
    }
    return 0;
}
