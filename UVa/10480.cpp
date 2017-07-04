#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int INF = 1e9;
const int MAX_NODES = 55;
int nodes, bottleneck;
bitset<MAX_NODES> visited;
int p[MAX_NODES],f[MAX_NODES][MAX_NODES], ini[MAX_NODES][MAX_NODES];
vector<vector<int> > g;
vector<bool> reachable;

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
                p[v] = u;
                q.push(v);
                if(v == t) return true;
            }
    }
    return false;
}

void path(int u) {
    if(~p[u]) {
        bottleneck = min(bottleneck, f[p[u]][u]);
        path(p[u]);
        f[p[u]][u] -= bottleneck;
        f[u][p[u]] += bottleneck;
    }
}

void edmonds(const int s, const int t) {
    while(bfs(s, t)) {
        bottleneck = INF;
        path(t);
    }
}

void dfs(int u) {
    reachable[u] = true;
    for(const auto& v: g[u])
        if(!reachable[v] && f[u][v] > 0)
            dfs(v);
}

void solve(const int s) {
    reachable.assign(nodes, false);
    dfs(s);
    for(int u = 0; u < nodes; ++u)
        if(reachable[u])
            for(const auto& v: g[u])
                if(!f[u][v] && !reachable[v])
                    cout << 1 + u << " " << 1 + v << '\n';
}

int main() {
    int edges,i,j,k;
    while(cin >> nodes >> edges, nodes || edges) {
        g.assign(nodes, vector<int>());
        memset(f, 0, sizeof f);
        memset(ini, 0, sizeof ini);
        while(edges--) {
            cin >> i >> j >> k;
            --i;--j;
            f[i][j] = f[j][i] = ini[i][j] = ini[j][i] = k;
            g[i].push_back(j);
            g[j].push_back(i);
        }
        edmonds(0,1);
        set<ii> s;
        solve(0);
        cout << '\n';
    }
    return 0;
}
