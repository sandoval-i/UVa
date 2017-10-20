#include <bits/stdc++.h>

using namespace std;
string s1,s2;
int memo1[35][35];
int memo2[35][35][65];

int lcs(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(~memo1[i][j]) return memo1[i][j];
    if(s1[i] == s2[j]) return memo1[i][j] = 1 + lcs(i - 1, j - 1);
    return memo1[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
}

int dp(int i, int j, int len) {
    if(len < 0) return 0;
    if(!len)
        return i == (int)s1.size() && j == (int)s2.size();
    if(~memo2[i][j][len]) return memo2[i][j][len];
    int ans = 0;
    if(i < (int)s1.size() && j < (int)s2.size() && s1[i] == s2[j]) {
        ans = dp(1 + i, 1 + j, len - 1);
    } else {
        if(i < (int)s1.size())
            ans += dp(1 + i, j, len - 1);
        if(j < (int)s2.size())
            ans += dp(i, 1 + j, len - 1);
    }
    return memo2[i][j][len] = ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,cas = 0;
    cin >> n;
    getline(cin, s1);
    while(n--) {
        getline(cin, s1);
        getline(cin, s2);
        memset(memo1, -1, sizeof memo1);
        memset(memo2, -1, sizeof memo2);
        cout << "Case #" << (++cas) << ": " << s1.size() + s2.size() - lcs(s1.size() - 1, s2.size() - 1) << ' ' << dp(0,0,s1.size() + s2.size() - lcs(s1.size() - 1, s2.size() - 1)) << '\n';
    }
    return 0;
}
