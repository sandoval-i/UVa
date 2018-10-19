#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXNW = 5 + 100000;
const string START = "?";
const string END = "@";
unordered_map<string,int> toid;
map<ii,int> m;
int st[MAXNW], cont[MAXNW], ans[MAXNW];
int totw;
string words[MAXNW];

bool dfs(int u) {
    int v = ans[u];
    st[u] = 0;
    if(~v && (st[v] == 0 || (st[v] == -1 && dfs(v)))) return true;
    st[u] = 1;
    return false;
}

vector<string> get(const string& s) {
    string curr;
    vector<string> v; v.emplace_back(START);
    foi(i,0,s.size()) {
        if(isspace(s[i])) {
            if(!curr.empty()) v.emplace_back(curr);
            curr.clear();
        } else curr += s[i];
    }
    if(!curr.empty()) v.emplace_back(curr);
    v.emplace_back(END);
    return v;
}

vector<int> add(const vector<string>& v) {
    vector<int> nums; int u;
    for(const string& s: v) {
        if(toid.find(s) == toid.end()) {
            u = toid[s] = totw;
            cont[u] = 1;
            ans[u] = st[u] = -1;
            words[u] = s;
            totw++;
        } else {
            u = toid[s];
            ++cont[u];
        }
        nums.emplace_back(u);
    }
    return nums;
}

void update(int u, int v) {
    if(ans[u] == -1) {
        ans[u] = v;
    } else {
        int& curr = ans[u];
        if(m[{u,v}] > m[{u,curr}]) curr = v;
        else if(m[{u,v}] == m[{u,curr}]) {
            if(cont[v] > cont[curr]) curr = v;
            else if(cont[v] == cont[curr]) {
                if(words[v] < words[curr]) curr = v;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    totw = 0;
    string s; int ntex;
    while(cin >> ntex) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        totw = 0;
        toid.clear(); m.clear();
        vector<ii> pi;
        while(ntex--) {
            getline(cin, s);
            vector<int> p = add(get(s));
            foi(i,1,p.size()) {
                pi.emplace_back(p[i - 1], p[i]);
                ++m[{p[i - 1], p[i]}];
            }
        }
        foi(i,0,pi.size()) {
            update(pi[i].first, pi[i].second);
        }
        if(dfs(toid[START])) cout << "INFINITE\n";
        else {
            bool f = true;
            int u = toid[START], v = toid[END]; u = ans[u];
            while(u != v) {
                if(!f) cout << ' ';
                f = false;
                cout << words[u];
                u = ans[u];
            }
            cout << '\n';
        }
    }
    return 0;
}
