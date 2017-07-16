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

string kmp(string& t, string& p, vector<int> b) {
    int i = 0, j = 0;
    for(;;) {
        if(i >= (int)t.size()) break;
        if(t[i] == p[j]) {
            ++i;++j;
        } else {
            if(!j) ++i;
            j = b[j];
        }
    }
    string res;
    for(; j < (int)p.size(); ++j)
        res += p[j];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string t, p;
    while(cin >> t) {
        p = t;
        reverse(p.begin(), p.end());
        cout << t + kmp(t, p, prefix_function(p)) << '\n';
    }
    return 0;
}
