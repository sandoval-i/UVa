#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > g;
vector<int> cost;
const int MAX_NODES = 150;
int p[MAX_NODES], bottleneck;
bitset<MAX_NODES> visited;
int nodes, f[MAX_NODES][MAX_NODES];

inline int out(int k) {
    if(k == 1 || k == nodes)
        return k;
    return k + 60;
}

inline int in(int k) {
    return k;
}

void path(int v) {
    int u = p[v];
    if(~u) {
        bottleneck = min(bottleneck, f[u][v]);
        path(u);
        f[u][v] -= bottleneck;
        f[v][u] += bottleneck;
    }
}

bool bfs(const int s, const int t) {
    queue<int> q;
    q.push(s);
    visited.reset();
    p[s] = -1;
    visited[s] = true;
    while(q.size()) {
        int u = q.front();q.pop();
        for(const auto& v: g[u])
            if(!visited[v] && f[u][v] > 0) {
                visited[v] = true;
                q.push(v);
                p[v] = u;
                if(v == t) return true;
            }
    }
    return false;
}

int edmonds(const int s, const int t) {
    int ans = 0;
    while(bfs(s, t)) {
        bottleneck = INT_MAX;
        path(t);
        ans += bottleneck;
    }
    return ans;
}

void add_edge(int u, int v, int flow) {
    g[u].push_back(v);
    g[v].push_back(u);
    f[u][v] += flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int edges,u,v,c;
    cost.resize(MAX_NODES);
    while(cin >> nodes >> edges, nodes || edges) {
        g.assign(MAX_NODES, vector<int>());
        memset(f, 0, sizeof f);
        for(int i = 0; i < nodes - 2; ++i) {
            int id;
            cin >> id;
            cin >> cost[id];
        }
        while(edges--) {
            cin >> u >> v >> c;
            add_edge(out(u), in(v), c);
            add_edge(out(v), in(u), c);
        }
        for(int u = 2; u < nodes; ++u)
            add_edge(in(u), out(u), cost[u]);
        cout << edmonds(1, nodes) << '\n';
    }
    return 0;
}
