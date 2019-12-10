#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
using ll = long long;
using ii = pair<int,int>;
constexpr int MOD = 1000000007;

inline int add(int a, int b) {
  int ans = a + b;
  if (ans >= MOD) ans -= MOD;
  return ans;
}

inline int sub(int a, int b) {
  int ans = a - b;
  if (ans < 0) ans += MOD;
  return ans;
}

inline int mul(int a, int b) {
  return (1LL * a * b) % MOD;
}

constexpr int MAXN = 52;
constexpr int MAXDFIF = 16;

int memo[MAXN][33][33][2][2]; // dp (posicion i, #6's - #3's, #9's - 6's, flag)
int cas[MAXN][33][33][2][2];
int current_case;

int dp(int i, int d36, int d69, bool f, bool g, const string& s) {
  if (d36 < -16 || d36 > 16 || d69 < -16 || d69 > 16) return 0;
  int& ans = memo[i][16 + d36][16 + d69][f][g];
  int& dpcase = cas[i][16 + d36][16 + d69][f][g];
  if (dpcase != current_case) {
    dpcase = current_case;
    if (i == (int) s.size()) {
      ans = (g && d36 == 0 && d69 == 0);
    } else {
      ans = 0;
      if (f) {
        ans = mul(7, dp(1 + i, d36, d69, f, g, s));
        for (char c : {'3', '6', '9'}) {
          ans = add(ans, dp(1 + i, d36 - (c == '3') + (c == '6'),
                                d69 - (c == '6') + (c == '9'), true, g || (c == '3'), s));
        }
      } else {
        for (char c = '0'; c <= s[i]; ++c) {
          ans = add(ans, dp(1 + i, d36 - (c == '3') + (c == '6'),
                                d69 - (c == '6') + (c == '9'), (c != s[i]), g || (c == '3'), s));
        }
      }
    }
  }
  return ans;
}

int ok(const string& s) {
  int a,b,c; a = b = c = 0;
  for (const char& x : s) {
    a += (x == '3');
    b += (x == '6');
    c += (x == '9');
  }
  if (a > 0 && a == b && b == c) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int tc; cin >> tc;
  current_case = 2;

  while (tc--) {
    string a,b; cin >> a >> b;

    ++current_case;
    int ans = dp(0,0,0,false,false,b);

    ++current_case;
    ans = sub(ans, dp(0,0,0,false,false,a));

    cout << add(ans, ok(a)) << '\n';
  }
  return 0;
}
