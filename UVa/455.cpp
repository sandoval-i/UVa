#include <bits/stdc++.h>
using namespace std;

vector<int> find_divisors(int n) {
    int div1, div2;
    vector<int> vec;
    for(int i = 1; i * i <= n; ++i)
        if(!(n % i)) {
            div1 = n / i;
            div2 = i;
            vec.push_back(div1);
            if(div1 != div2) vec.push_back(div2);
        }
    vector<int> ans;
    for(const auto v: vec) if(v <= (n >> 1)) ans.push_back(v);
    sort(ans.begin(), ans.end());
    return ans;
}

bool ok(string& s, int k) {
    string q;
    for(int i = 0; i < k; ++i) q += s[i];
    for(int j = k; j < (int)s.size(); j += k)
        for(int i = 0; i < (int)q.size(); ++i)
            if(q[i] != s[j + i]) return false;
    return true;
}

int bs(string& k) {
    vector<int> divisors = find_divisors(k.size());
    for(int i = 0; i < (int)divisors.size(); ++i)
        if(ok(k, divisors[i])) return divisors[i];
    return k.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    bool f = true;
    cin >> tc;
    string t;
    while(tc--) {
        if(!f) cout << '\n';
        f = false;
        cin >> t;
        cout << bs(t) << '\n';
    }
    return 0;
}
