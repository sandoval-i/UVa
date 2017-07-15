#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string& s) {
    vector<int> b(1 + s.size());
    int j;
    b[0] = b[1] = 0;
    for(int i = 2; i <= (int)s.size(); ++i) {
        j = b[i - 1];
        for(;;) {
            if(s[j] == s[i - 1]) {
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
vector<int> kmp(string& t, string& p, vector<int> b) {
    int i = 0, j = 0;
    vector<int> res;
    for(;;) {
        if(i >= (int)t.size()) break;
        if(t[i] != p[j]) { // mismatch
            if(!j) ++i;
            else j = b[j];
        } else // match
            ++i,++j;
        if(j == (int)p.size()) {
            res.push_back(i - p.size());
            j = b[j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    string t,p;
    bool f = true;
    int sz;
    while(cin >> sz >> p >> t) {
        if(!f) cout << '\n';
        f = false;
        vector<int> ans = kmp(t, p, prefix_function(p));
        for(const auto &q: ans) cout << q << '\n';
    }
    return 0;
}
