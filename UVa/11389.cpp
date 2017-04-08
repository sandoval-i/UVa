#include <bits/stdc++.h>

using namespace std;

int main() {
    vector < int > m,a;
    int n,d,r,pass;
    while(scanf("%d %d %d" , &n , &d , &r) , n || d || r )
    {
        pass = 0;
        m.resize(n);
        a.resize(n);
        for( int i = 0 ; i < n ; ++i )
            scanf("%d" , &m[i]);
        for( int i = 0 ; i < n ; ++i )
            scanf("%d" , &a[i]);
        sort(m.begin(), m.end());
        sort(a.rbegin(), a.rend());
        for( int i = 0 ; i < n ; ++i )
            pass += ( m[i] + a[i] ) > d ? (m[i] + a[i]) - d : 0;
        printf("%d\n" , pass * r);
    }
    return 0;
}
