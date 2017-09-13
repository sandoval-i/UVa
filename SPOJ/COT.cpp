#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
int sz;
struct lca {
    vector<vector<int> > table;
    vector<int> euler,p,h,fo;
    lca(vector<vector<int> >& tree) { // O(nlgn)
        p.resize(tree.size());
        h.resize(tree.size());
        fo.resize(tree.size());
        dfs(tree);
        build(euler);
    }
    void dfs(vector<vector<int> >& tree, int u = 0, int alt = 0) {
        fo[u] = euler.size();
        h[u] = alt;
        euler.push_back(u);
        int v;
        foi(i,0,tree[u].size()) {
            v = tree[u][i];
            if(p[u] == v)    continue;
            p[v] = u;
            dfs(tree, v, 1 + alt);
            euler.push_back(u);
        }
    }
    void build(vector<int>& arr) {
        int columns = 1 + floor(log2(arr.size()));
        table.assign(arr.size(), vector<int>(columns , -2));
        foi(i,0,arr.size()) table[i][0] = arr[i];
        foi(j,1,columns)
            for(int i = 0; i + (1 << j) - 1 < (int)arr.size(); ++i) {
                table[i][j] = table[i][j-1];
                if(h[table[i + (1 << (j - 1))][j-1]] < h[table[i][j]])
                    table[i][j] = table[i + (1 << (j - 1))][j-1];
            }
    }
    int st_query(int i, int j) {
        if(i > j) swap(i, j);
        int len = j - i + 1, k = floor(log2(len));
        int ans = table[i][k];
        if(h[table[i + len - (1 << k)][k]] < h[ans])
            ans = table[i + len - (1 << k)][k];
        return ans;
    }
    int query(int u, int v) { // O(1)
        return st_query(fo[u], fo[v]);
    }};

struct pst {
    struct node {
        node* l, *r;
        int val;
        node() {
            l = r = NULL;
            val = 0;
        }
        node(const node& o) {
            l = o.l;
            r = o.r;
            val = o.val;
        }};
    node* root;
    pst(node* _new) {
        root = _new;
    }
    pst() {
        root = build();
    }
    node* build(int low = 0, int high = sz - 1) {
        node* n = new node;
        if(low != high) {
            int mid = (low + high) >> 1;
            n->l = build(low, mid);
            n->r = build(1 + mid, high);
        }
        return n;
    }
    node* inc(const int& upos, int low, int high, node* curr) {
        node* n = new node(*curr);
        int mid = (low + high) >> 1;
        if(low != high) {
            if(upos <= mid)
                n->l = inc(upos, low, mid, curr->l);
            else
                n->r = inc(upos, 1 + mid, high, curr->r);
            n->val = n->l->val + n->r->val;
        } else
            ++n->val;
        return n;
    }
    int query(int low, int high, int k, node* curr) {
        int mid = (low + high) >> 1;
        if(low == high) return curr->val;
        if(k <= mid)
            return query(low, mid, k, curr->l);
        return query(1 + mid, high, k, curr->r);
    }
    int query(int k) {
        return query(0, sz - 1, k, root);
    }
    node* inc(int pos) {
        return inc(pos, 0, sz - 1, root);
    }};
vector<int> to;
vector<pst> trees;
vector<vector<int> > g;
vector<int> w;

void dfs(int u = 0, int prev = -1) {
    to[u] = trees.size();
    if(~prev)
        trees.push_back(pst(trees[to[prev]].inc(w[u])));
    else
        trees.push_back(pst(trees.back().inc(w[u])));
    int v;
    foi(i,0,g[u].size()) {
        v = g[u][i];
        if(v != prev)
            dfs(v, u);
    }
}

map<int,int> mm;
vector<int> inv;

int query(pst::node* unode, pst::node* vnode, pst::node* lcanode, int k, int l, int low = 0, int high = sz - 1) {
    if(low == high) return low;
    int left = unode->l->val + vnode->l->val - (lcanode->l->val << 1), mid = (low + high) >> 1;
    if(w[l] <= mid && w[l] >= low) ++left;
    if(k <= left)
        return query(unode->l, vnode->l, lcanode->l, k, l, low, mid);
    return query(unode->r, vnode->r, lcanode->r, k - left, l, 1 + mid, high);
}

int solve(int u, int v, int lcanode, int k) {
    return inv[query(trees[to[u]].root, trees[to[v]].root, trees[to[lcanode]].root, k, lcanode)];
}

void compress() {
    sz = 0;
    vector<int> w2(w.size());
    inv.resize(w.size());
    foi(i,0,w.size()) w2[i] = w[i];
    sort(w2.begin(), w2.end());
    foi(i,0,w2.size())
        if(!mm.count(w2[i])) {
            mm[w2[i]] = sz;
            inv[sz] = w2[i];
            ++sz;
        }
    foi(i,0,w.size())
        w[i] = mm[w[i]];
    trees.push_back(pst());
}
int n;

int main() {
    int m,u,v,k;
    scanf("%d %d", &n, &m);
    g.assign(n, vector<int>());
    w.resize(n);
    to.resize(n);
    foi(i,0,n) scanf("%d", &w[i]);
    foi(i,0,n - 1) {
        scanf("%d %d", &u, &v);
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    lca l(g);
    compress();
    dfs();
    while(m--) {
        scanf("%d %d %d", &u, &v, &k);
        --u;--v;
        printf("%d\n", solve(u,v,l.query(u, v),k));
    }
    return 0;
}
