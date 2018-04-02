#include <bits/stdc++.h>

#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;

int N;
const int MAXN = 5 + 1030;
int bit[1 + MAXN][1 + MAXN];
void upd(int x, int y, int val) { // 1-BASED, al inicio la matriz esta llena de ceros
    for(; x <= MAXN; x += (x & -x))
        for(int y1 = y; y1 <= MAXN; y1 += (y1 & -y1))
            bit[x][y1] += val;
}
int query(int x, int y) {
    int ans = 0LL;
    for(; x > 0; x -= (x & -x))
        for(int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            ans += bit[x][y1];
    return ans;
}
int query(int x1, int y1, int x2, int y2) { // 1-BASED, suma de esquina superior izquierda(x1,y1) hasta esquina inferior derecha(x2,y2)
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}


int main() {
    int tc,x1,y1,x2,y2;
    scanf("%d", &tc);
    char s[40];
    while(tc--) {
        scanf("%d", &N);
        foi(i,1,1+N) foi(j,1,1+N) bit[i][j] = 0LL;
        while(true) {
            scanf("%s", s);
            if(s[0] == 'E') break;
            else if(s[1] == 'E') { // set
                scanf("%d %d %d", &x1, &y1, &x2);
                upd(1 + x1,1 + y1,-query(1 + x1, 1 + y1, 1 + x1, 1 + y1));
                upd(1 + x1,1 + y1,x2);
            } else { // sum
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%d\n", query(1 + x1,1 + y1,1 + x2,1 + y2));
            }
        }
    }
    return 0;
}

