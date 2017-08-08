#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> color;
bool ok;

void dfs(int u) {
    for(const auto& v: g[u])
        if(color[v] == -1) {
            color[v] = 1 - color[u];
            dfs(v);
        } else if(color[v] == color[u]) {
            ok = false;
            return;
        }
}


int main() {
    int tc,u,v;
    scanf("%d", &tc);
    for(int c = 1; c <= tc; ++c) {
        scanf("%d %d", &n, &m);
        g.assign(n, vector<int>());
        color.assign(n, -1);
        while(m--) {
            scanf("%d %d", &u, &v);
            g[--u].push_back(--v);
            g[v].push_back(u);
        }
        ok = true;
        for(int u = 0; u < n && ok; ++u)
            if(color[u] == -1) {
                color[u] = 0;
                dfs(u);
            }
        printf("Scenario #%d:\n%s\n", c, ok ? "No suspicious bugs found!" : "Suspicious bugs found!");
    }
    return 0;
}
