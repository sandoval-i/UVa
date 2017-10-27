#include <bits/stdc++.h>

using namespace std;
vector<int> arr[26];
vector<int>::iterator it;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int tc,ans;
    string s;
    cin >> tc;
    while(tc--) {
        ans = 0;
        cin >> s;
        for(int i = 0; i < 26; ++i) arr[i].clear();
        for(int i = 0; i < (int)s.size(); ++i)
            arr[s[i] - 'A'].push_back(i);
        for(int i = 0; i < 26; ++i) {
            if(arr[i].empty()) continue;
            for(int j = 0; j < 26; ++j) {
                if(arr[j].empty()) continue;
                it = upper_bound(arr[j].begin(), arr[j].end(), arr[i][0]);
                if(it == arr[j].end()) continue;
                for(int k = 0; k < 26; ++k) {
                    if(arr[k].empty()) continue;
                    ans += (upper_bound(arr[k].begin(), arr[k].end(), *it) != arr[k].end());
                }
            }
        }
        cout << ans << '\n';
    }
}
