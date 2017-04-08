#include <bits/stdc++.h>

using namespace std;

int main()
{
  unsigned long n , a , b , t;
  bool bandera;
  while( scanf("%lu", &n ) && n != 0 )
  {

    t = a = b = 0;
    bandera = true;
    while( ( 1 << t ) <= n )
    {
      if( ( 1 << t ) & n )
        if( bandera )
        {
          a |= ( 1 << t );
          bandera = false;
        }
        else
        {
          b |= ( 1 << t );
          bandera = true;
        }
        t++;
    }
    printf( "%lu %lu\n", a , b );
  }
  return 0;
}
