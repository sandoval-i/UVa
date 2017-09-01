#include <bits/stdc++.h>

using namespace std;
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
#define MAX 5002
vector<int> tree[MAX];
int best[MAX], best_pos[MAX], best2[MAX], p[MAX];
bool adj[MAX][MAX];

void dfs(int u = 0) {
    int v;
    best[u] = best2[u] = 0;
    best_pos[u] = -1;
    foi(i,0,tree[u].size()) {
        v = tree[u][i];
        if(p[u] != v) {
            p[v] = u;
            dfs(v);
            if(1 + best[v] > best[u]) {
                best[u] = 1 + best[v];
                best_pos[u] = v;
            }
        }
    }
    foi(i,0,tree[u].size()) {
        v = tree[u][i];
        if(p[u] != v && v != best_pos[u] && 1 + best[v] > best2[u])
            best2[u] = 1 + best[v];
    }
}

void dfs2(int u = 0) {
    if(u) {
        if(best_pos[p[u]] != u) {
            if(1 + best[p[u]] > best[u]) {
                best2[u] = best[u];
                best[u] = 1 + best[p[u]];
                best_pos[u] = p[u];
            } else if(1 + best[p[u]] > best2[u])
                best2[u] = 1 + best[p[u]];
        } else {
            if(1 + best2[p[u]] > best[u]) {
                best2[u] = best[u];
                best[u] = 1 + best2[p[u]];
                best_pos[u] = p[u];
            }
            else if(1 + best2[p[u]] > best2[u])
                best2[u] = 1 + best2[p[u]];
        }
    }
    int v;
    foi(i,0,tree[u].size()) {
        v = tree[u][i];
        if(p[u] != v)
            dfs2(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K,v;
    while(cin >> N) {
        memset(p, -1, sizeof p);
        memset(adj, false, sizeof adj);
        foi(u,0,N) tree[u].clear();
        foi(u,0,N) {
            cin >> K;
            while(K--) {
                cin >> v;
                --v;
                if(!adj[u][v]) {
                    tree[u].push_back(v);
                    tree[v].push_back(u);
                    adj[u][v] = adj[v][u] = true;
                }
            }
        }
        dfs();
        dfs2();
        int maxi = numeric_limits<int>::min(), mini = numeric_limits<int>::max();
        foi(i,0,N) {
            maxi = max(maxi, best[i]);
            mini = min(mini, best[i]);
        }
        cout << "Best Roots  :";
        foi(i,0,N)
            if(best[i] == mini)
                cout << ' ' << 1 + i;
        cout << "\nWorst Roots :";
        foi(i,0,N)
            if(best[i] == maxi)
                cout << ' ' << 1 + i;
        cout << '\n';
    }
    return 0;
}
