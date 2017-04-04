#include <bits/stdc++.h>

using namespace std;

unsigned int fast_pow(unsigned int base, unsigned int exp, unsigned int MOD) {
  unsigned int ans = 1, power = base;
  while(exp) {
    if(exp & 1)
      ans = (ans * power) % MOD;
    power = (power * power) % MOD;
    exp >>= 1;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  unsigned int x,y,MOD;
  cin >> tc;
  while(tc--) {
    cin >> x >> y >> MOD;
    cout << fast_pow(x, y, MOD) << '\n';
  }
  return 0;
}
