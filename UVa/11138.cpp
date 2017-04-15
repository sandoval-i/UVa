#include <bits/stdc++.h>

using namespace std;

#define foi(i,k,n)  for(int i = (int)k;i < (int)n; ++i)
#define MAX_N 510
#define MAX_K 510

vector < vector < int > > g;
bitset < MAX_N > visited;
int n,k,matching[MAX_K];
// n = numero de nodos en izquierda
// k = numero de nodos en la derecha
// matching[i] = nodo de la izquierda que matchea con i

bool kuhn(int u) {
  if(visited[u])  return false;
  visited[u] = true;
  int v;
  foi(i,0,g[u].size()) {
    v = g[u][i];
    if(matching[v] == -1 || kuhn(matching[v])) {
      matching[v] = u;
      return true;
    }
  }
  return false;
}

int kuhn() {
  int max_matching = 0;
  memset(matching, -1, sizeof matching);
  foi(i,0,n) {
    visited.reset();
    max_matching += kuhn(i);
  }
  return max_matching;
}

int main() {
  int c,temp;
  cin >> c;
  foi(p,0,c) {
    cin >> n >> k;
    g.assign(n, vector < int >());
    foi(i,0,n)foi(j,0,k) {
      cin >> temp;
      if(temp) g[i].push_back(j);
    }
    cout << "Case " << 1 + p << ": a maximum of " << kuhn() << " nuts and bolts can be fitted together\n";
  }
  return 0;
}
