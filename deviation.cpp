#include <bits/stdc++.h>

using namespace std;

vector < long double > deviation;

long double hallar( unsigned long long i )
{
  if( deviation[i] == -1 )
    deviation[i] = sqrt( ( long double )( i * ( i + 1 ) ) / 3 );
  return deviation[i];
}

int main()
{
  unsigned long long entrada;
  deviation.assign( 1000001 , -1 );
  while( scanf("%llu", &entrada ) && entrada != 0 )
  {
    printf("%.6Lf\n", hallar( entrada ) );
  }
  return 0;
}
