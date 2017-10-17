#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;

const int MAX_N = 20;
typedef long long ll;
const ll INF = 10000000000000000LL;
int cont;
ll dist[40][40];
ll memo[MAX_N][1 << (MAX_N+2)];
ll memo2[MAX_N][1 << (MAX_N+2)];
ll res;
int n;

ll dp(int u, int bm) {
    if(~memo[u][bm]) return memo[u][bm];
    if(!bm) return memo[u][bm] = dist[0][u];
    ll ans = INF;
    foi(v,1,n - 1)
        if(bm & (1 << v))
            ans = min(ans, dist[u][v] + dp(v, bm & ~(1 << v)));
    return memo[u][bm] = ans;
}

ll dp2(int u, int bm) {
    if(~memo2[u][bm]) return memo2[u][bm];
    if(!bm) return memo2[u][bm] = dist[u][n - 1];
    ll ans = INF;
    foi(v,1,n - 1)
        if(bm & (1 << v))
            ans = min(ans, dist[u][v] + dp2(v, bm & ~(1 << v)));
    return memo2[u][bm] = ans;
}

ll go(int bm, int bmo) {
    ll best = INF;
    foi(i,1,n - 1)
        foi(j,1,n-1)
            best = min(best, dp(i, bm & ~(1 << i)) + dp2(i, bmo& ~(1 << i)) + dp2(j, bm & ~(1 << j)) + dp(j, bmo & ~(1 << j)));
    return best;
}

void gen(int idx, int left, int bm = 0) {
    if(idx == n - 1) {
        if(!left)
            res = min(res, go(bm, ((1 << (n - 1)) - 2) ^ bm));
        return;
    }
    gen(1 + idx, left - 1, bm | (1 << idx));
    gen(1 + idx, left, bm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,u,v,cas = cont = 0;
    ll c;
    while(cin >> n >> m) {
        foi(i,0,40) foi(j,0,40) dist[i][j] = (i == j ? 0LL : INF);
        while(m--) {
            cin >> u >> v >> c;
            dist[u][v] = dist[v][u] = c;
        }
        foi(k,0,n)foi(i,0,n)foi(j,0,n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        if(n == 3) res = dist[0][1] + dist[1][2] + dist[2][1] + dist[1][0];
        else {
            memset(memo, -1, sizeof memo);
            memset(memo2, -1, sizeof memo2);
            res = INF;
            gen(1, (n - 2) >> 1);
        }
        cout << "Case " << (++cas) << ": " << res << '\n';
    }
    return 0;
}
