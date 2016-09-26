#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > DAG;
vector < int > memo;

int dp( int u )
{
  if( !DAG[u].size() ) return 1;
  if( memo[u] != -1 ) return memo[u];
  int ans = 0;
  for( int i = 0 ; i < DAG[u].size() ; ++i  )
    ans += dp( DAG[u][i] );
  return memo[u] = ans;
}

int main()
{
  int N , num , to;
  bool first = true;
  while( scanf("%d", &N ) != EOF )
  {
    if( first )
      first = false;
    else
      puts("");
    DAG.assign( N , vector < int >() );
    memo.assign( N , -1 );
    for( int i = 0 ; i < N ; ++i )
    {
      scanf("%d", &num );
      while( num-- )
      {
        scanf("%d", &to );
        DAG[i].push_back( to );
      }
    }
    printf("%d\n", dp(0) );
  }
  return 0;
}
