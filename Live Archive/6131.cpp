#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

using namespace std;
typedef long long ll;

const int MAXN = 5 + 1000;
ll POS[MAXN], W[MAXN], memo[MAXN][MAXN], c[MAXN][MAXN];
int N, K;

int dp(int k, int i, int mink, int maxk) {
    int bestk = -1;
    ll ans = numeric_limits<ll>::max();
    for(int j = max(k - 1, mink); j <= min(maxk, i); ++j) {
        if(c[j][i] + memo[k - 1][j - 1] < ans) {
            ans = c[j][i] + memo[k - 1][j - 1];
            bestk = j;
        }
    }
    memo[k][i] = ans;
    return bestk;
}

void calc(int klay, int mink, int maxk, int l, int r) {
    if(l > r) return;
    int m = (l + r) >> 1;
    int bestk = dp(klay, m, mink, maxk);
    calc(klay, mink, bestk, l, m - 1);
    calc(klay, bestk, maxk, 1 + m, r);
}

ll solve() {
    foi(i,0,N)
        memo[1][i] = c[0][i];
    foi(k,2,1+K) calc(k,0,N-1,k-1,N-1);
    return memo[K][N - 1];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin >> N >> K) {
        foi(i,0,N) cin >> POS[i] >> W[i];
        foi(i,0,N) {
            ll ans = 0LL;
            for(int j = i; j >= 0; --j) {
                ans += (W[j] * (POS[i] - POS[j]));
                c[j][i] = ans;
            }
        }
        cout << solve() << '\n';
    }
    return 0;
}
