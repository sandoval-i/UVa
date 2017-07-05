#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 201, INF = 1e9;
const int SOURCE = 200;
typedef pair<int,int> ii;
vector<vector<int>> g;
bitset<MAX_NODES> visited;
int initial_flow[MAX_NODES][MAX_NODES], residual_flow[MAX_NODES][MAX_NODES], p[MAX_NODES], bottleneck, nodes, tot_penguins;

struct piece {
    int x,y,max_jumps, penguins;
};

vector<piece> data;

bool dfs(int u, const int t) {
    visited[u] = true;
    if(u == t) return true;
    for(const auto& v: g[u])
        if(!visited[v] && residual_flow[u][v] > 0) {
            p[v] = u;
            if(dfs(v, t)) return true;
        }
    return false;
}

void path(int v) {
    int u = p[v];
    if(~u) {
        bottleneck = min(bottleneck, residual_flow[u][v]);
        path(u);
        residual_flow[u][v] -= bottleneck;
        residual_flow[v][u] += bottleneck;
    }
}

int fordf(const int s, const int t) {
    int ans = 0;
    for(;;) {
        visited.reset();
        p[s] = -1;
        bottleneck = INT_MAX;
        if(!dfs(s, t)) return ans;
        path(t);
        ans += bottleneck;
    }
}

void add_edge(int u, int v, int f) {
    g[u].push_back(v);
    g[v].push_back(u);
    initial_flow[u][v] = f;
}

long double dist(const piece& a, const piece& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

inline int in(int k) {
    return k;
}

inline int out(int k) {
    return 100 + k;
}

bool solve(const int t) {
    for(int i = 0; i < MAX_NODES; ++i)
        for(int j = 0; j < MAX_NODES; ++j)
            residual_flow[i][j] = initial_flow[i][j];
    g[SOURCE].clear();
    for(int i = 0; i < nodes; ++i)
        if(i != t && data[i].penguins) {
            g[SOURCE].push_back(in(i));
            residual_flow[SOURCE][in(i)] = data[i].penguins;
        }
    return (fordf(SOURCE, in(t)) + data[t].penguins) == tot_penguins;
}

int main() {
    int tc;
    long double max_dist;
    cin >> tc;
    while(tc--) {
        tot_penguins = 0;
        memset(initial_flow, 0, sizeof initial_flow);
        g.assign(MAX_NODES, vector<int>());
        data.assign(MAX_NODES,piece());
        cin >> nodes >> max_dist;
        for(int i = 0; i < nodes; ++i) {
            cin >> data[i].x >> data[i].y >> data[i].penguins >> data[i].max_jumps;
            tot_penguins += data[i].penguins;
        }
        for(int i = 0; i < nodes; ++i)
            for(int j = 1 + i; j < nodes; ++j)
                if(dist(data[i], data[j]) <= max_dist) {
                    add_edge(out(i), in(j), INF);
                    add_edge(out(j), in(i), INF);
                }
        for(int i = 0; i < nodes; ++i)
            add_edge(in(i), out(i), data[i].max_jumps);
        vector<int> ans;
        for(int i = 0; i < nodes; ++i)
            if(solve(i)) ans.push_back(i);
        if(ans.empty()) cout << "-1";
        else
            for(int i = 0; i < (int)ans.size(); ++i) {
                if(i) cout << ' ';
                cout << ans[i];
            }
        cout << '\n';
    }
    return 0;
}
