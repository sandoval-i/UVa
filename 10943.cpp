#include <bits/stdc++.h>

using namespace std;

long long memo[1002][1002];

const long long MOD = 1000000LL;

long long dp( int n , int k )
{
  if( memo[n][k] != -1 )
    return memo[n][k];
  if( n == 0 || k == 1 )  return 1;
  long long ans = 0;
  for( int i = n ; i >= 0 ; --i )
    ans = ( ans + dp( i , k - 1 ) ) % MOD;
  return memo[n][k] = ans;
}

int main()
{
  int N , K;
  memset( memo , -1 , sizeof memo );
  while( scanf( "%d %d" , &N , &K ) , N || K )
    printf("%lld\n", dp( N , K ) );
  return 0;
}
