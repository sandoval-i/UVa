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
    int query(int low, int high, int k, node* curr, node* curro) {
        if(low == high) return low;
        int mid = (low + high) >> 1, lval = curr->l->val - curro->l->val;
        return k <= lval ? query(low, mid, k, curr->l, curro->l) : query(1 + mid, high, k - lval, curr->r, curro->r);
    }
    int query(pst& o, int k) {
        return query(0, sz - 1, k, root, o.root);
    }
    node* build(int low, int high) {
        node* n = new node;
        if(low != high) {
            int mid = (low + high) >> 1;
            n->l = build(low, mid);
            n->r = build(1 + mid, high);
        }
        return n;
    }
    node* inc(int& upos, int low, int high, node* curr) {
        int mid = (low + high) >> 1;
        node* n = new node(*curr);
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
    node* inc(int pos) {
        return inc(pos, 0, sz - 1, root);
    }};
const int MAX_N = 100010;
int arr[MAX_N],arr2[MAX_N],inv[MAX_N],n;
unordered_map<int,int> m;
vector<pst> trees;

void preprocess() {
    trees.push_back(pst());
    for(int i = n - 1; i >= 0; --i)
        trees.push_back(pst(trees.back().inc(arr[i])));
    reverse(trees.begin(), trees.end());
}

void compress() {
    sort(arr2, arr2 + n);
    sz = 0;
    foi(i,0,n)
        if(!m.count(arr2[i])) {
            m[arr2[i]] = sz;
            inv[sz] = arr2[i];
            ++sz;
        }
    foi(i,0,n)
        arr[i] = m[arr[i]];
}

int query(int i, int j, int k) {
    return trees[i].query(trees[1 + j], k);
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    foi(i,0,n) {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }
    compress();
    preprocess();
    int i,j,k;
    while(q--) {
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", inv[query(i - 1,j - 1,k)]);
    }
    return 0;
}
