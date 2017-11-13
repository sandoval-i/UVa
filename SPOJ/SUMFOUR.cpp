#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0LL;
    vector<int> a(n),b(n),c(n),d(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> arr(n*n);
    int idx = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            arr[idx++] = c[i] + d[j];
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            ans += (ll)(upper_bound(arr.begin(), arr.end(), -(a[i] + b[j])) - lower_bound(arr.begin(), arr.end(), -(a[i] + b[j])));
    cout << ans << '\n';
    return 0;
}
