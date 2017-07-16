#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string& s) {
    vector<int> b(1 + s.size());
    b[0] = b[1] = 0;
    int j;
    for(int i = 2; i <= (int)s.size(); ++i) {
        j = b[i - 1];
        for(;;) {
            if(s[i - 1] == s[j]) {
                b[i] = 1 + j;
                break;
            }
            if(!j) {
                b[i] = 0;
                break;
            }
            j = b[j];
        }
    }
    return b;
}

string kmp(string& t, string& p, vector<int>& b) {
    int i = 0, j = 0;
    for(;;) {
        if(i >= (int)t.size()) break;
        if(t[i] == p[j]) {
            ++i;++j;
            continue;
        }
        if(!j) {
            ++i;
            continue;
        }
        j = b[j];
    }
    string res;
    for(; j < (int)p.size(); ++j)
        res += p[j];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,k,w;
    vector<string> arr;
    vector<vector<int>> bs;
    cin >> tc;
    while(tc--) {
        cin >> k >> w;
        arr.resize(w);
        bs.resize(w);
        for(int i = 0; i < w; ++i) {
            cin >> arr[i];
            bs[i] = prefix_function(arr[i]);
        }
        string ans = arr[0];
        for(int i = 1; i < w; ++i)
            ans += kmp(ans, arr[i], bs[i]);
        cout << ans.size() << '\n';
    }
    return 0;
}
