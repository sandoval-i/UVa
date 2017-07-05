#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 202, SOURCE = 201, TARGET = 200;
int f[MAX_NODES][MAX_NODES], p[MAX_NODES], bottleneck;
vector<vector<int>> g;
bitset<MAX_NODES> visited;

bool bfs(const int s, const int t) {
    visited.reset();

    queue<int> q;
    q.push(s);
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

void path(int v) {
    int u = p[v];
    if(~u) {
        bottleneck = min(bottleneck, f[u][v]);
        path(u);
        f[u][v] -= bottleneck;
        f[v][u] += bottleneck;
    }
}

int edmonds(const int s, const int t) {
    int flow = 0;
    while(bfs(s, t)) {
        bottleneck = INT_MAX;
        path(t);
        flow += bottleneck;
    }
    return flow;
}

inline int in(int u) {
    return u;
}

inline int out(int u) {
    return 100 + u;
}

void add_edge(int u, int v, int flow) {
    g[u].push_back(v);
    g[v].push_back(u);
    f[u][v] += flow;
}

int main() {
    int nodes,edges,u,v,c,B,D;
    while(cin >> nodes) {
        memset(f, 0, sizeof f);
        g.assign(MAX_NODES, vector<int>());
        for(int i = 0; i < nodes; ++i) {
            cin >> c;
            add_edge(in(i), out(i), c);
        }
        cin >> edges;
        while(edges--) {
            cin >> u >> v >> c;
            add_edge(out(--u), in(--v), c);
        }
        cin >> B >> D;
        for(int i = 0; i < B; ++i) {
            cin >> v;
            add_edge(SOURCE, in(--v), INT_MAX);
        }
        for(int i = 0; i < D; ++i) {
            cin >> v;
            add_edge(out(--v), TARGET, INT_MAX);
        }
        cout << edmonds(SOURCE, TARGET) << '\n';
    }
    return 0;
}
