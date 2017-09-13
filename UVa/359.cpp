#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
struct sat {
    vector<vector<int>> revg, scc, compact; // scc to nodes
    vector<int> my_scc; // node to scc
    stack<int> topo;
    vector<bool> visited;
    sat(vector<vector<int>>& g) {
        my_scc.resize(g.size());
        visited.assign(g.size(), false);
        revg.assign(g.size(), vector<int>());
        foi(u,0,g.size()) {
            if(!visited[u]) dfs(u,g);
            for(const auto& v: g[u])
                revg[v].push_back(u);
        }
        visited.assign(g.size(), false);
        scc.reserve(g.size());
        while(topo.size()) {
            int u = topo.top();topo.pop();
            if(!visited[u]) {
                scc.push_back(vector<int>());
                dfs2(u, revg);
            }
        }
    }
    bool solve(int n) {
        foi(u,0,n)
            if(my_scc[u] == my_scc[u + n])
                return false;
        return true;
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
vector<vector<int>> g, parents;
vector<int> deg,s;
bool ok;

void dfs(int u) {
    s[u] = 0;
    for(int& v: g[u])
        if(s[v] == -1)
            dfs(v);
        else if(s[v] == 0) {
            ok = false;
            return;
        }
    s[u] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v,num = 1, p1, p2;
    while(cin >> n >> m) {
        ok = true;
        g.assign(n, vector<int>());
        parents.assign(n, vector<int>());
        deg.assign(n, 0);
        s.assign(n, -1);
        while(m--) {
            cin >> u >> v;
            g[--u].push_back(--v);
            ++deg[v];
        }
        for(int i = 0; i < n && ok; ++i) {
            if(deg[i] > 2)
                ok = false;
            if(s[i] == -1)
                dfs(i);
        }
        foi(p,0,n)
            for(int& x: g[p])
                parents[x].push_back(p);
        vector<vector<int>> newone(n << 1, vector<int>());
        if(ok) {
            foi(i,0,n)
                if(parents[i].size() > 1) {
                    p1 = parents[i][0];
                    p2 = parents[i][1];
                    newone[p1 + n].push_back(p2);
                    newone[p2 + n].push_back(p1);
                    newone[p1].push_back(p2 + n);
                    newone[p2].push_back(p1 + n);
                }
        }
        sat k(newone);
        cout << "Graph number " << num << " is ";
        if(ok && k.solve(n)) cout << "sexy\n";
        else cout << "not sexy\n";
        ++num;
    }
    return 0;
}
