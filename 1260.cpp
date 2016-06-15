#include <bits/stdc++.h>

using namespace std;

#define foi( i , n ) for( ; i < n ; i++ )

int main()
{
  int test , n , i , j;
  unsigned long total;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d", &n );
    vector < int > datos( n , 1e8 );
    i = total = 0;
    foi( i , n )
    {
      scanf("%d", &datos[i] );
      j = 0;
      foi( j , i )
      if( datos[j] <= datos[i] )
        total++;
    }
    printf("%lu\n", total );
  }
  return 0;
}
