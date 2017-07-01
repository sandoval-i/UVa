#include <bits/stdc++.h>

using namespace std;

const int SOURCE = 0;
const int TARGET = 1021;
const int CATEGORIES_BEG = 1;
const int PROBLEMS_BEG = 21;
const int MAX_NODES = 1022;
const int INF = 1e9;
vector<vector<int> > g;
int f[MAX_NODES][MAX_NODES], p[MAX_NODES], bottleneck;
bitset<MAX_NODES> visited;

void init_flow(int nk, int np) {
    memset(f, 0, sizeof f);
    for(int i = CATEGORIES_BEG; i < CATEGORIES_BEG + nk; ++i)
        g[i].push_back(TARGET);
    for(int i = PROBLEMS_BEG; i < PROBLEMS_BEG + np; ++i) {
        g[SOURCE].push_back(i);
        f[SOURCE][i] = 1;
    }
}

bool dfs(int u, const int t) {
    visited[u] = true;
    if(u == t) return true;
    for(int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if(!visited[v] && f[u][v] > 0) {
            visited[v] = true;
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

int fordf(int s, int t) {
    int max_flow = 0;
    for(;;) {
        visited.reset();
        p[s] = -1;
        if(!dfs(s, t)) return max_flow;
        bottleneck = INF;
        path(t);
        max_flow += bottleneck;
    }
}

void print_solution(int nk, int np) {
    int cont;
    cout << 1 << '\n';
    for(int u = CATEGORIES_BEG; u < CATEGORIES_BEG + nk; ++u) {
        cont = 0;
        for(int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if(!f[v][u]) {
                if(cont++) cout << ' ';
                cout << 1 + v - PROBLEMS_BEG;
            }
        }
        cout << '\n';
    }
}

int main() {
    int nk, np, sz, v, total_sum, flow;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> nk >> np, nk || np) {
        g.assign(MAX_NODES, vector<int>());
        init_flow(nk, np);
        total_sum = 0;
        for(int i = CATEGORIES_BEG; i < CATEGORIES_BEG + nk; ++i) {
            cin >> f[i][TARGET];
            total_sum += f[i][TARGET];
        }
        for(int i = PROBLEMS_BEG; i < PROBLEMS_BEG + np; ++i) {
            cin >> sz;
            while(sz--) {
                cin >> v;
                g[i].push_back(v);
                g[v].push_back(i);
                f[i][v] = 1;
            }
        }
        flow = fordf(SOURCE, TARGET);
        if(flow == total_sum) print_solution(nk, np);
        else cout << 0 << '\n';
    }
    return 0;
}
