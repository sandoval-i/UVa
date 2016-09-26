#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

int memo[MAX_N][MAX_N] , N;
char matriz[MAX_N][MAX_N];
const int MOD = 1e6 + 7;

inline bool in( int x , int y )
{
  return x >= 0 && x < N && y >= 0 && y < N;
}

int dp( int x , int y )
{
  if( x == 0 )  return 1;
  if( memo[x][y] != -1 )  return memo[x][y];
  int ans = 0;
  if( in( x - 1 , y - 1 ) )
  {
    if( matriz[ x - 1 ][ y - 1 ] == '.' )
      ans = ( ans + dp( x - 1 , y - 1 ) ) % MOD;
    else if( in( x - 2 , y - 2 ) )
      if( matriz[ x - 2][ y - 2 ] == '.' )
        ans = ( ans + dp( x - 2 , y - 2 ) ) % MOD;
  }
  if( in( x - 1 , y + 1 ) )
  {
    if( matriz[ x - 1 ][ y + 1 ] == '.' )
      ans = ( ans + dp( x - 1 , y + 1 ) ) % MOD;
    else if( in( x - 2 , y + 2 ) )
      if( matriz[ x - 2][ y + 2 ] == '.' )
        ans = ( ans + dp( x - 2 , y + 2 ) ) % MOD;
  }
  return memo[x][y] = ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int casos , x , y , caso = 0;
  cin >> casos;
  while( casos-- )
  {
    cin >> N;
    memset( memo , -1 , sizeof memo );
    for( int i = 0 ; i < N ; ++i ) for( int j = 0 ; j < N ; ++j )
    {
      cin >> matriz[i][j];
      if( matriz[i][j] == 'W' )
      {
        x = i;
        y = j;
      }
    }
    cout << "Case " << ( ++caso ) << ": " << dp(x,y) << '\n';
  }
  return 0;
}
