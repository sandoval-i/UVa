#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; ++i )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

int main()
{
  int casos , caso = 0 , N , tenia , max_longitud_lis , max_longitud_lds ;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d", &N );
    vi heights( N , 0 ) , widths( N , 0 ) , peso_lis( N , 0 ) , peso_lds( N , 0 );
    foi( i , 0 , N )  scanf("%d", &heights[i] );
    foi( i , 0 , N )  scanf("%d", &widths[i] );
    max_longitud_lis = max_longitud_lds = 1 << 31;
    foi( j , 0 , N )
    {
      peso_lis[j] = peso_lds[j] = widths[j];
      foi( i , 0 , j )
      {
        if( heights[i] < heights[j] )
          peso_lis[j] = max( peso_lis[j] , widths[j] + peso_lis[i] );
        if( heights[i] > heights[j] )
          peso_lds[j] = max( peso_lds[j] , widths[j] + peso_lds[i] );
      }
      max_longitud_lis = max( max_longitud_lis , peso_lis[j] );
      max_longitud_lds = max( max_longitud_lds , peso_lds[j] );
    }
    if( max_longitud_lis >= max_longitud_lds )
      printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++caso , max_longitud_lis , max_longitud_lds );
    else
      printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++caso , max_longitud_lds , max_longitud_lis );
  }
  return 0;
}
