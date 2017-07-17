#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 1000000000000000LL;
int N,K;
ll dp[1001][1001];
vector<ii> points;
vector<vector<ll>> c;

struct sum2d {
    vector<vector<ll>> sum;
    sum2d(vector<vector<ll>>& arr) {
        sum.resize(arr.size(), vector<ll>(arr[0].size(), 0LL));
        for(int j = 0; j < (int)arr[0].size(); ++j)
            for(int i = 0; i < (int)arr.size(); ++i) {
                sum[i][j] = arr[i][j];
                if(i) sum[i][j] += sum[i - 1][j];
            }
    }
    ll query(int l, int r) {
        ll res = sum[r][r];
        if(l) res -= sum[l - 1][r];
        if(l > r) return  INF;
        return res;
    }
};

void preprocess() {
    c.assign(points.size(), vector<ll>(points.size(), 0LL));
    for(int i = 0; i < (int)points.size(); ++i)
        for(int j = i; j < (int)points.size(); ++j)
            c[i][j] = points[i].second * (points[j].first - points[i].first);
}

int get_dp(int i, int j, int l, int r, sum2d& q) {
    dp[i][j] = INF;
    int res;
    for(int k = max(l, i - 2); k <= min(r, j - 1); ++k) {
        ll p = dp[i - 1][k] + q.query(1 + k, j);
        if(p < dp[i][j]) {
            dp[i][j] = p;
            res = k;
        }
    }
    return res;
}

void compute_dp(int i, int jleft, int jright, int kleft, int kright, sum2d& q) {
    if(jleft <= jright) {
        int jmid = (jleft + jright) >> 1;
        int bestk = get_dp(i, jmid, kleft, kright, q);
        compute_dp(i, jleft, jmid - 1, kleft, bestk, q);
        compute_dp(i, 1 + jmid, jright, bestk, kright, q);
    }
}

ll solve() {
    sum2d q(c);
    for(int i = 0; i < N; ++i)
        dp[1][i] = q.query(0, i);
    for(int i = 2; i <= K; ++i)
        compute_dp(i, i - 1, N - 1, 0, N - 1, q);
    return dp[K][N - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N >> K) {
        points.resize(N);
        for(auto &u: points) cin >> u.first >> u.second;
        preprocess();
        cout << solve() << '\n';
    }
    return 0;
}
