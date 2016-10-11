#include <bits/stdc++.h>

using namespace std;

long long a[3] , b[3] , c[3] , min_sum;
string ans;

void solve( string s )
{
  long long suma = 0;
  switch( s[0] )
  {
    case 'B':
      suma += b[0] + c[0];
      break;
    case 'G':
      suma += b[1] + c[1];
      break;
    case 'C':
      suma += b[2] + c[2];
      break;
  }
  switch( s[1] )
  {
    case 'B':
      suma += a[0] + c[0];
      break;
    case 'G':
      suma += a[1] + c[1];
      break;
    case 'C':
      suma += a[2] + c[2];
      break;
  }
  switch( s[2] )
  {
    case 'B':
      suma += a[0] + b[0];
      break;
    case 'G':
      suma += a[1] + b[1];
      break;
    case 'C':
      suma += a[2] + b[2];
      break;
  }
  if( suma < min_sum )
  {
    min_sum = suma;
    ans = s;
  }
}

int main()
{
  while( scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2], &c[0], &c[1], &c[2] ) != EOF )
  {
    min_sum = 1LL << 60;
    solve( "BCG" );
    solve( "BGC" );
    solve( "CBG" );
    solve( "CGB" );
    solve( "GBC" );
    solve( "GCB" );
    printf("%s %lld\n", ans.c_str() , min_sum );
  }
  return 0;
}
