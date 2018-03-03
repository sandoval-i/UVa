#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAXN = 5 + 100;
int N;

struct point {
    double x,y;
    point(){}
    point(double _x, double _y){
        x = _x;
        y = _y;
    }
    bool operator < (const point& o) const {
        return this->x < o.x;
    }
};

struct line {
    double m, b;
    line(point p, point q) {
        m = ((double)p.y - (double)q.y) / ((double)p.x - (double)q.x);
        b = -m*(double)p.x + (double)p.y;
    }
    point findx(double y) {
        return point((y - b) / m, y);
    }
};

point arr[MAXN];

double dist(const point& p, const point& q) {
    double dx = p.x - q.x, dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ios::sync_with_stdio(false);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N;
        foi(i,0,N) cin >> arr[i].x >> arr[i].y;
        sort(arr, arr + N);
        double ans = dist(arr[N - 1], arr[N - 2]);
        double curry = arr[N - 2].y;
        for(int i = N - 3; i >= 0; --i)
            if(arr[i].y > curry) {
                ans += dist(arr[i], (new line(arr[i], arr[1 + i]))->findx(curry));
                curry = arr[i].y;
            }
        cout << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}

