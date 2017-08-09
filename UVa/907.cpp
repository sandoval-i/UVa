#include <bits/stdc++.h>

using namespace std;
int N,K;
int memo[602][302];
vector<int> arr;

int dp(int i, int left) {
    if(!left) return i == N ? 0 : INT_MAX;
    if(~memo[i][left]) return memo[i][left];
    int ans = INT_MAX, sum = 0;
    for(int j = i; j < N; ++j) {
        sum += arr[j];
        ans = min(ans, max(sum, dp(1 + j, left - 1)));
    }
    return memo[i][left] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N >> K) {
        ++N;++K;
        arr.resize(N);
        for(auto& x: arr) cin >> x;
        memset(memo, -1, sizeof memo);
        cout << dp(0, K) << '\n';
    }
    return 0;
}
