#include <bits/stdc++.h>

using namespace std;

#define foi(i,k,n)  for(int i = (int)k; i < (int)n; ++i)
typedef pair<int,int> ii;
#define MAX 100010
set<ii> s; // degree, node
vector<vector<int>> g;
int degree[MAX];
int A,B;

void undfs(int u) {
    int v;
    set<ii>::iterator e;
    foi(i,0,g[u].size()) {
        v = g[u][i];
        e = s.find(ii(degree[v], v));
        if(e != s.end()) {
            s.erase(e);
            s.insert(ii(--degree[v], v));
        }
    }
}

int go() {
    int tam, aux;
    set<ii>::iterator e;
    for(;;) {
        tam = s.size();
        if(!tam)    break;
        e = s.end();
        --e;
        if(s.begin()->first < A) {
            aux = s.begin()->second;
            s.erase(s.begin());
            undfs(aux);
        }
        else if(e->first > tam - B - 1) {
            aux = e->second;
            s.erase(e);
            undfs(aux);
        }
        else break;
    }
    return s.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,u,v;
    while(cin >> N >> M >> A >> B) {
        memset(degree, 0, sizeof degree);
        g.assign(N, vector<int>());
        s.clear();
        while(M--) {
            cin >> u >> v;
            g[--u].push_back(--v);
            g[v].push_back(u);
            ++degree[u];
            ++degree[v];
        }
        foi(u,0,N)
            s.insert(ii(degree[u], u));
        cout << go() << '\n';
    }
    return 0;
}
