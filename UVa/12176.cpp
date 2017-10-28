#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
typedef pair<int,int> ii;

struct lca {
    vector<vector<int>> f,pw;
    vector<int> l;
    int MAX_LOG;
    lca(vector<vector<ii>>& tree) {
        MAX_LOG = 1 + floor(log2(tree.size()));
        f.assign(tree.size(), vector<int>(MAX_LOG, -1));
        pw.assign(tree.size(), vector<int>(MAX_LOG, -1));
        l.resize(tree.size());
        f[0][0] = 0;
        pw[0][0] = numeric_limits<int>::min();
        dfs(tree);
        foi(i,1,MAX_LOG)
            foi(u,0,tree.size()) {
                f[u][i] = f[f[u][i-1]][i - 1];
                pw[u][i] = max(pw[u][i - 1], pw[f[u][i-1]][i - 1]);
            }
    }
    void dfs(vector<vector<ii>>& tree, int u = 0, int lvl = 0) {
        int v,cost;
        l[u] = lvl;
        foi(i,0,tree[u].size()) {
            v = tree[u][i].first;
            cost = tree[u][i].second;
            if(f[u][0] != v) {
                f[v][0] = u;
                pw[v][0] = cost;
                dfs(tree, v, 1 + lvl);
            }
        }
    }
    ii query(int u, int v) {
        int maxi = numeric_limits<int>::min();
        if(l[u] < l[v]) swap(u,v);
        for(int i = MAX_LOG - 1; i >= 0; --i)
            if(l[f[u][i]] >= l[v]) {
                maxi = max(maxi, pw[u][i]);
                u = f[u][i];
            }
        if(u == v) return ii(u, maxi);
        for(int i = MAX_LOG - 1; i >= 0; --i)
            if(f[u][i] != f[v][i]) {
                maxi = max(maxi, pw[u][i]);
                maxi = max(maxi, pw[v][i]);
                u = f[u][i];
                v = f[v][i];
            }
        return ii(f[u][0],max(maxi, max(pw[u][0], pw[v][0]))); // lca(u,v), max_edge(u,v)
    }
};

void add(vector<vector<ii>>& tree, int u, int v, int c) {
    tree[u].push_back(ii(v,c));
    tree[v].push_back(ii(u,c));
}

struct dsu {
  vector<int> parent, sz;
  dsu(int n) {
    sz.assign(n, 1);
    parent.assign(n, 0);
    foi(i,1,n)
      parent[i] = i;
  }
  int find_parent(int k) {
    return parent[k] == k ? k : parent[k] = find_parent(parent[k]);
  }
  void join(int i, int j) {
    int p = find_parent(i),q = find_parent(j);
    if(p == q)  return;
    if(sz[q] > sz[p])   swap(p, q);
    sz[p] += sz[q];
    parent[q] = p;
  }
  bool connected(int i, int j) {
    return find_parent(i) == find_parent(j);
  }};


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int tc,n,m;
    int a,b,q;
    cin >> tc;
    foi(k,1,1 + tc) {
        cin >> n >> m;
        vector<pair<int,ii>> edges(m);
        vector<vector<ii>> tree(n, vector<ii>());
        foi(i,0,m) {
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
            --edges[i].second.first;
            --edges[i].second.second;
        }
        sort(edges.begin(), edges.end());
        dsu ds(n);
        foi(i,0,m)
            if(!ds.connected(edges[i].second.first, edges[i].second.second)) {
                ds.join(edges[i].second.first, edges[i].second.second);
                add(tree, edges[i].second.first, edges[i].second.second, edges[i].first);
            }
        cin >> q;
        lca l(tree);
        cout << "Case " << k << '\n';
        while(q--) {
            cin >> a >> b;
            cout << l.query(--a,--b).second << '\n';
        }
        cout << '\n';
    }
	return 0;
}
