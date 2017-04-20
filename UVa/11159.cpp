#include <bits/stdc++.h>

using namespace std;

#define foi(i,k,n)  for(int i = (int)k; i < (int)n; ++i)
#define MAX_N 110
#define MAX_M 110

int n,m;
bitset < MAX_N > used, visited;
int match[MAX_N];
vector < vector < int > > g;
vector < int > arr1, arr2;

bool kuhn(int u) {
    if(visited[u])  return false;
    visited[u] = true;
    int v;
    foi(i,0,g[u].size()) {
        v = g[u][i];
        if(match[v] == -1 || kuhn(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int kuhn() {
    int ans = 0,v;
    memset(match, -1, sizeof match);
    used.reset();
    foi(u,0,n)
        foi(i,0,g[u].size()) {
            v = g[u][i];
            if(match[v] == -1) {
                ++ans;
                match[v] = u;
                used[u] = true;
                break;
            }
        }
    foi(u,0,n) {
        if(used[u]) continue;
        visited.reset();
        ans += kuhn(u);
    }
    return ans;
}

bool can(int u, int v) {
    if(!u && !v)    return true;
    if(u && !v) return true;
    if(!u && v) return false;
    return (v % u) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c,u,v;
    cin >> c;
    foi(p,0,c) {
        cin >> n;
        arr1.resize(n);
        g.assign(n, vector < int >());
        foi(i,0,n)  cin >> arr1[i];
        cin >> m;
        arr2.resize(m);
        foi(i,0,m)  cin >> arr2[i];
        foi(i,0,arr1.size()) {
            u = arr1[i];
            foi(j,0,arr2.size()) {
                v = arr2[j];
                if(can(u, v))   g[i].push_back(j);
            }
        }
        cout << "Case " << 1 + p << ": " << kuhn() << endl;
    }
    return 0;
}
