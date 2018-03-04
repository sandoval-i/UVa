#include <bits/stdc++.h>

using namespace std;
const int MAXN = 20;

struct point {
    double x,y;
    point(){}
};

point arr[MAXN];

struct vec {
    double x,y;
    vec(){}
    vec(point p, point q) {
        x = q.x - p.x;
        y = q.y - p.y;
    }
    double norm() {
        return sqrt(x*x + y*y);
    }
    double dot(vec b) {
        return (this->x * b.x) + (this->y * b.y);
    }
    double cross(vec b) {
        return (this->x * b.y) - (this->y * b.x);
    }
};

double distpointlinesegment(point A, point B, point C) { // distancia del punto C al segmento de recta formado por AB
    vec AB(A,B), BC(B,C), BA(B,A), AC(A,C);
    if(AB.dot(BC) > 0) return BC.norm();
    if(BA.dot(AC) > 0) return AC.norm();
    return fabs(AB.cross(AC)/AB.norm());
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    string s;
    while(cin >> s, s != "*") {
        int N = atoi(s.c_str());
        point r;
        cin >> r.x >> r.y;
        for(int i = 0; i < N; ++i)
            cin >> arr[i].x >> arr[i].y;
        arr[N] = arr[0];
        double ans = numeric_limits<double>::max();
        for(int i = 1; i <= N; ++i)
            ans = min(ans, distpointlinesegment(arr[i], arr[i - 1], r));
        cout << fixed << setprecision(3) << ans << '\n';
    }
}
