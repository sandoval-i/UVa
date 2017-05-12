#include <bits/stdc++.h>

using namespace std;
#define foi(i,k,n)  for(int i = (int)k; i <(int)n; ++i)
typedef long long ll;

void go(vector<ll>& ans, vector<ll>& s, int& high, ll sum, bool taken, int idx) {
    if(idx == 1 + high) {
        if(taken)   ans.push_back(sum);
        return;
    }
    go(ans, s, high, sum, taken, 1 + idx);
    go(ans, s, high, sum + s[idx], true, 1 + idx);
}

void go2(vector<ll>& ans, vector<ll>& s, int low, int high) {
    go(ans, s, high, 0LL, false, low);
}

ll bs(vector<ll>& s, ll k) {
    int pos1,pos2;
    pos1 = lower_bound(s.begin(), s.end(), k) - s.begin();
    if(pos1 == s.size() || s[pos1] != k)    return 0;
    pos2 = upper_bound(s.begin(), s.end(), k) - s.begin();
    return pos2 - pos1;
}

ll solve(vector <ll>& s, ll k) {
    if(s.size() == 1)   return s[0] == k;
    ll ans = 0;
    vector<ll> s1,s2;
    int low = 0, high = s.size() - 1;
    int mid = (low + high) >> 1;
    go2(s1, s, 0, mid);
    go2(s2, s, 1 + mid, high);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    foi(i,0,s1.size())
        ans += bs(s2, k - s1[i]);
    ans += bs(s2, k) + bs(s1, k);
    return ans;
}

vector<ll> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll t;
    while(cin >> n >> t) {
        s.resize(n);
        foi(i,0,n)  cin >> s[i];
        cout << solve(s, t) << '\n';
    }
    return 0;
}
