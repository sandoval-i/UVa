#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_N = 1 + 1000000;
bitset<MAX_N> is_prime;
vector<int> primes;

void sieve() {
    is_prime.set();
    for(ll i = 2; i < MAX_N; ++i)
        if(is_prime[i]) {
            for(ll j = i * i; j < MAX_N; j += i)
                is_prime[j] = false;
            primes.push_back(i);
        }
}

ll solve(int n) {
    vector<int>::iterator it;
    ll ans = 0, idx1, idx2;
    for(int i = 0; i < (int)primes.size() && (primes[i] << 1) < n; ++i) {
        it = lower_bound(primes.begin() + i + 1, primes.end(), n - primes[i]);
        if(it == primes.end()) continue;
        if(*it != n - primes[i]) it--;
        idx1 = 1 + i;
        idx2 = it - primes.begin();
        ans += (1LL + idx2 - idx1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int n, cas = 0;
    while(cin >> n, n)
        cout << "Case " << (++cas) << ": " << solve(n) << '\n';
}
