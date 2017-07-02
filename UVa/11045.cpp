#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g, f;
vector<int> p;
vector<bool> visited;
string sizes[] = {"XXL", "XL", "L", "M", "S", "XS"};
int bottleneck;
const int INF = 1e9;

bool dfs(int u, const int t) {
    visited[u] = true;
    if(u == t) return true;
    for(int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if(!visited[v] && f[u][v] > 0) {
            p[v] = u;
            if(dfs(v, t)) return true;
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

int fordf(const int s, const int t, const int GRAPH_SZ) {
    int flow = 0;
    for(;;) {
        visited.assign(GRAPH_SZ, false);
        p.assign(GRAPH_SZ, -1);
        if(!dfs(s, t)) return flow;
        bottleneck = INF;
        path(t);
        flow += bottleneck;
    }
}

int main() {
    int N,M,tc;
    string t1, t2;
    cin >> tc;
    while(tc--) {
        cin >> N >> M;
        map<string, int> sizes_to_id;
        const int GRAPH_SZ = M + 6 + 2;
        const int SOURCE = GRAPH_SZ - 1;
        const int TARGET = GRAPH_SZ - 2;
        const int SIZES_BEG = M;
        g.assign(GRAPH_SZ, vector<int>());
        f.assign(GRAPH_SZ, vector<int>(GRAPH_SZ, false));
        for(int i = SIZES_BEG; i < SIZES_BEG + 6; ++i)
            sizes_to_id[sizes[i - SIZES_BEG]] = i;
        for(int i = 0; i < M; ++i) {
            g[SOURCE].push_back(i);
            f[SOURCE][i] = 1;
            cin >> t1 >> t2;
            int id1 = sizes_to_id[t1], id2 = sizes_to_id[t2];

            g[i].push_back(id1);
            g[id1].push_back(i);
            f[i][id1] = 1;

            g[i].push_back(id2);
            g[id2].push_back(i);
            f[i][id2] = 1;
        }
        for(int u = SIZES_BEG; u < SIZES_BEG + 6; ++u) {
            g[u].push_back(TARGET);
            f[u][TARGET] = N/6;
        }
        cout << (fordf(SOURCE, TARGET, GRAPH_SZ) == M ? "YES" : "NO") << '\n';
    }
    return 0;
}
