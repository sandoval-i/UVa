#include <bits/stdc++.h>

using namespace std;

#define foi(i, k, n)    for(int i = k ; i < n ; ++i)

struct comp {
    int y, f, s;
};

vector < comp > pcs;

int shows(comp p, int y) {
    if(y >= p.f && y < p.s) return y;
    return p.f + ((y - p.f) % (p.s - p.f));
}

bool works(int year, int k) {
    foi(i, 0 , pcs.size()) {
        if(i == k)  continue;
        if(year < pcs[i].y || shows(pcs[i], year) != pcs[i].y)    return false;
    }
    return true;
}

void solve(int p, set < int >& s) {
    comp current = pcs[p];
    int year = current.y, diff = current.s - current.f;
    while(year < 10000) {
        if(works(year, p)){
            s.insert(year);
            return;
        }
        year += diff;
    }
}

int main() {
    int n, c = 0;
    while(scanf("%d", &n), n) {
        pcs.resize(n);
        set < int > possibles;
        foi(i, 0 , n) scanf("%d %d %d", &pcs[i].y, &pcs[i].f, &pcs[i].s);
        printf("Case #%d:\n", ++c);
        foi(i, 0, n)
            solve(i, possibles);
        if(possibles.empty())   puts("Unknown bugs detected.");
        else printf("The actual year is %d.\n", *possibles.begin());
        puts("");
    }
    return 0;
}
