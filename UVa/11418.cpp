#include <bits/stdc++.h>

using namespace std;

int problemsno, sz;
vector<vector<string> > res;
vector<vector<int> > g;
vector<int> matching, l;
vector<bool> visited;

bool kuhn(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    for(int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if(matching[v] == -1 || kuhn(matching[v])) {
            matching[v] = u;
            l[u] = v;
            return true;
        }
    }
    return false;
}

void kuhn() {
    matching.assign(problemsno, -1);
    l.assign(28, -1);
    for(int i = 0; i < problemsno; ++i) {
        visited.assign(28, false);
        kuhn(i);
    }
}

char uppercase(char c) {
    return c >= 'A' && c <= 'Z' ? c : char(c - 32);
}

char lowercase(char c) {
    return c >= 'a' && c <= 'z' ? c : char(c + 32);
}

string format(string s) {
    string ans;
    ans += uppercase(s[0]);
    for(int i = 1; i < (int)s.size(); ++i)
        ans += lowercase(s[i]);
    return ans;
}

void solve() {
    for(int u = 0; u < problemsno; ++u)
        cout << format(res[l[u]][u]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, caso = 0;
    string name;
    cin >> tc;
    while(tc--) {
        cin >> problemsno;
        g.assign(28, vector<int>());
        res.assign(problemsno, vector<string>(28, ""));
        for(int i = 0; i < problemsno; ++i) {
            cin >> sz;
            while(sz--) {
                cin >> name;
                g[uppercase(name[0]) - 'A'].push_back(i);
                res[i][uppercase(name[0]) - 'A'] = name;
            }
        }
        kuhn();
        cout << "Case #" << ++caso << ":\n";
        solve();
    }
    return 0;
}
