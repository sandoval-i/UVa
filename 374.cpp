#include <bits/stdc++.h>

using namespace std;

unsigned long long fastPow( unsigned long long base , unsigned long long exponente , unsigned long long MOD )
{
  unsigned long long res = base , llevo = 1 ;
  int i = 0;
  while( ( 1LL << i ) <= exponente )
  {
    if( ( exponente & ( 1LL << i ) ) != 0 )
      llevo = ( llevo * res ) % MOD;
    res = res * res % MOD;
    ++i;
  }
  return llevo;
}

int main()
{
  unsigned long long B , P , M;
  while( scanf("%llu %llu %llu", &B , &P , &M ) != EOF )
    printf("%llu\n", fastPow( B , P , M ) );
  return 0;
}
