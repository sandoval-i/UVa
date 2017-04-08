#include <bits/stdc++.h>

using namespace std;

int N , i , j , minimo;

void simular( int low , int high , int altura )
{
  if( i >= low && j <= high )
  {
    minimo = min( minimo , N - altura );
    int mid = ( low + high ) >> 1;
    simular( low , mid , altura + 1 );
    simular( mid + 1 , high , altura + 1 );
  }
}

int main()
{
  int a , b;
  while( scanf("%d %d %d", &N , &a , &b ) != EOF )
  {
    i = min( a , b );
    j = max( a , b );
    minimo = N;
    simular( 1 , 1 << N , 0 );
    printf("%d\n", minimo );
  }
  return 0;
}
