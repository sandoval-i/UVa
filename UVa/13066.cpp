#include <bits/stdc++.h>

using namespace std;
int N,M,rmatch[202];
bool dist[201][201];
bitset<101> visited;
vector<vector<int>> g;

bool kuhn(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    for(int& v: g[u])
        if(rmatch[v] == -1 || kuhn(rmatch[v])) {
            rmatch[v] = u;
            return true;
        }
    return false;
}

int kuhn() {
    int ans = 0;
    memset(rmatch, -1, sizeof rmatch);
    for(int i = 0; i < N; ++i) {
        visited.reset();
        ans += kuhn(i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int u,v;
    while(cin >> N >> M) {
        memset(dist, false, sizeof dist);
        for(int i = 0; i < N; ++i) dist[i][i] = true;
        while(M--) {
            cin >> u >> v;
            dist[u][v] = true;
        }
        for(int k = 0; k < N; ++k)
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    dist[i][j] |= (dist[i][k] && dist[k][j]);
        g.assign(N, vector<int>());
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                if(i != j && dist[i][j])
                    g[i].push_back(j + N);
        cout << N - kuhn() << '\n';
    }
    return 0;
}
