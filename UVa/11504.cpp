#include <bits/stdc++.h>
using namespace std;
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
struct kosaraju {
    vector<vector<int>> revg, scc; // scc to nodes
    vector<int> my_scc; // node to scc
    stack<int> topo;
    vector<bool> visited;
    kosaraju(vector<vector<int>>& g) {
        my_scc.resize(g.size());
        visited.assign(g.size(), false);
        revg.assign(g.size(), vector<int>());
        foi(u,0,g.size()) {
            if(!visited[u]) dfs(u,g);
            for(const auto& v: g[u])
                revg[v].push_back(u);
        }
        visited.assign(g.size(), false);
        while(topo.size()) {
            int u = topo.top();topo.pop();
            if(!visited[u]) {
                scc.push_back(vector<int>());
                dfs2(u, revg);
            }
        }
    }
    void dfs(int u, vector<vector<int>>& g) {
        visited[u] = true;
        for(const auto& v: g[u])
            if(!visited[v]) dfs(v,g);
        topo.push(u);
    }
    void dfs2(int u, vector<vector<int>>& g) {
        visited[u] = true;
        scc[scc.size() - 1].push_back(u);
        my_scc[u] = scc.size() - 1;
        for(const auto& v: g[u])
            if(!visited[v]) dfs2(v,g);
    }};

vector<bool> vis;
vector<int> t;

void topo(int u, vector<vector<int>>& g) {
    vis[u] = true;
    for(const auto& v: g[u])
        if(!vis[v]) topo(v,g);
    t.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> g;
    int tc,N,M,u,v;
    cin >> tc;
    while(tc--) {
        cin >> N >> M;
        g.assign(N, vector<int>());
        while(M--) {
            cin >> u >> v;
            g[--u].push_back(--v);
        }
        kosaraju k(g);
        vector<vector<int>> newg(k.scc.size(), vector<int>());
        vis.assign(k.scc.size(), false);
        t.clear();
        for(int u = 0; u < N; ++u)
            for(const auto& v: g[u])
                if(k.my_scc[u] != k.my_scc[v])
                    newg[k.my_scc[u]].push_back(k.my_scc[v]);
        for(int u = 0; u < (int)k.scc.size(); ++u)
            if(!vis[u])
                topo(u, newg);
        vis.assign(k.scc.size(), false);
        int ans = 0;
        for(int i = t.size() - 1; i >= 0; --i) {
            int u = t[i];
            if(!vis[u]) {
                topo(u, newg);
                ++ans;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}
