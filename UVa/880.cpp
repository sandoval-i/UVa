#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll num = 1LL, cont = 1LL;
    vector<ll> inis;
    while(inis.size() <= 5 * 1000000) {
        inis.push_back(cont);
        cont += (num++);
    }
    ll n,idx;
    vector<ll>::iterator it;
    while(cin >> n) {
        it = lower_bound(inis.begin(), inis.end(), n);
        idx = 1LL + it - inis.begin();
        if(*it == n)
            cout << idx << '/' << 1 << '\n';
        else {
            --idx;
            --it;
            cout << idx - abs(*it - n) << '/' << 1 + abs(*it - n) << '\n';
        }
    }
    return 0;
}
