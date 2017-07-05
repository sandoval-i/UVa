#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1802, MAX_ROWS = 30, MAX_COLUMNS = 30;
const int SOURCE = 1800, TARGET = 1801, CONS = 900, INF = 1e6;
char mat[MAX_ROWS][MAX_COLUMNS];
int f[MAX_NODES][MAX_NODES], p[MAX_NODES], bottleneck;
bitset<MAX_NODES> visited;
vector<vector<int>> g;
int rows, columns;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool dfs(int u, const int t) {
    if(u == t) return true;
    visited[u] = true;
    for(const auto& v: g[u])
    if(!visited[v] && f[u][v] > 0) {
        p[v] = u;
        if(dfs(v, t)) return true;
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

int fordf(const int s, const int t) {
    int ans = 0;
    for(;;) {
        visited.reset();
        p[s] = -1;
        if(!dfs(s, t)) return ans;
        bottleneck = INT_MAX;
        path(t);
        ans += bottleneck;
    }
}

inline int in(int u) {
    return u;
}

inline int out(int u) {
    int x = u / columns, y = u % columns;
    return mat[x][y] == '#'? u: u + CONS;
}

inline int inside(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < columns;
}


inline int get_id(int x, int y) {
    return x * columns + y;
}

void add_edge(int u, int v, int flow) {
    g[u].push_back(v);
    g[v].push_back(u);
    f[u][v] += flow;
}

int main() {
    int q;
    while(cin >> rows >> columns >> q) {
        g.assign(MAX_NODES, vector<int>());
        memset(f, 0, sizeof f);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < columns; ++j) {
                cin >> mat[i][j];
                int u = get_id(i, j);
                if(mat[i][j] == '*') {
                    add_edge(in(u), out(u), 1);
                    g[SOURCE].push_back(in(u));
                    f[SOURCE][in(u)] = 1;
                }
                else if(mat[i][j] == '.')
                    add_edge(in(u), out(u), 1);
                else if(mat[i][j] == '#') {
                    g[out(u)].push_back(TARGET);
                    f[out(u)][TARGET] = q;
                }
                else if(mat[i][j] == '~')
                    add_edge(in(u), out(u), 0);
                else if(mat[i][j] == '@')
                    add_edge(in(u), out(u), INF);
            }
        for(int x = 0; x < rows; ++x)
            for(int y = 0; y < columns; ++y)
                for(int k = 0; k < 4; ++k) {
                        int xto = x + dx[k];
                        int yto = y + dy[k];
                        if(inside(xto, yto)) {
                            int u = get_id(x, y);
                            int v = get_id(xto, yto);
                            add_edge(out(u), in(v), INF);
                            add_edge(out(v), in(u), INF);
                        }
                }
        cout << fordf(SOURCE, TARGET) << '\n';
    }
    return 0;
}
