#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull solve(ull L, ull U, int N) {
    ull ans = L,num;
    for(int i = 40; i >= 0; --i) {
        if(N & (1ULL << i)) continue;
        num = ans | (1ULL << i);
        if(!(ans & (1ULL << i)))
            num &= ~((1ULL << i) - 1ULL);
        if(num > U) continue;
        ans = num;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    ull N,L,U;
    while(cin >> N >> L >> U)
        cout << solve(L,U,N) << '\n';
    return 0;
}

