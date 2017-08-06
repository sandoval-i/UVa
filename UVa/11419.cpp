#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
int rows, columns, lmatch[1000], rmatch[2000];
bitset<2000> visited;

bool kuhn(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    for(const auto& v: g[u])
        if(rmatch[v] == -1 || kuhn(rmatch[v])) {
            lmatch[u] = v;
            rmatch[v] = u;
            return true;
        }
    return false;
}

void kuhn() {
    memset(rmatch, -1, sizeof rmatch);
    memset(lmatch, -1, sizeof lmatch);
    for(int i = 0; i < rows; ++i) {
        visited.reset();
        kuhn(i);
    }
}

vector<int> join(vector<int> a, vector<int> b) {
    set<int> s;
    vector<int> ans;
    for(auto x: a) s.insert(x);
    for(auto x: b) s.insert(x);
    ans.resize(s.size());
    int idx = 0;
    for(auto x: s)
        ans[idx++] = x;
    return ans;
}

vector<int> diff(vector<int>& a, vector<int>& b) {
    set<int> s1, s2;
    vector<int> ans;
    for(auto x: a) s1.insert(x);
    for(auto x: b) s2.insert(x);
    for(auto x: s1)
        if(!s2.count(x))
            ans.push_back(x);
    return ans;
}

vector<int> intersect(vector<int>& a, vector<int>& b) {
    set<int> s1, s2;
    vector<int> ans;
    for(auto x: a) s1.insert(x);
    for(auto x: b) s2.insert(x);
    for(auto x: s1)
        if(s2.count(x))
            ans.push_back(x);
    return ans;
}

void dfs(int u, vector<int>& Z, bool f = false) {
    if(visited[u]) return;
    Z.push_back(u);
    visited[u] = true;
    for(auto v: g[u])
        if(!f) {
            if(lmatch[u] != v)dfs(v, Z, true);
        } else if(rmatch[u] == v)
            dfs(v, Z, false);
}

vector<int> mvc() {
    vector<int> Z,L,R;
    for(int i = 0; i < rows; ++i) {
        if(lmatch[i] == -1) {
            visited.reset();
            dfs(i, Z);
        }
        L.push_back(i);
    }
    for(int i = 0; i < columns; ++i)
        R.push_back(rows + i);
    return join(diff(L, Z), intersect(R, Z));
}

int main() {
    int balls,x,y;
    while(scanf("%d %d %d", &rows, &columns, &balls), rows || columns || balls) {
        g.assign(rows + columns, vector<int>());
        while(balls--) {
            scanf("%d %d", &x, &y);
            --x;--y;
            g[x].push_back(y + rows);
            g[y + rows].push_back(x);
        }
        kuhn();
        vector<int> ans = mvc();
        printf("%d", (int)ans.size());
        for(int i = 0; i < (int)ans.size(); ++i)
            printf(" %c%d", ans[i] >= rows ? 'c' : 'r', 1 + (ans[i] >= rows ? ans[i] - rows : ans[i]));
        puts("");
    }
    return 0;
}
