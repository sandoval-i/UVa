#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore();

int relatives[501];

int main()
{
  int test , r , minDif , difNow;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d", &r );
    foi( i , 0 , r )  scanf("%d", &relatives[i] );
    minDif = 1 << 30;
    foi( i , 0 , r )
    {
      difNow = 0;
      foi( j , 0 , r )
      {
        if( i == j )  continue;
        difNow += abs( relatives[i] - relatives[j] );
      }
      minDif = min( minDif , difNow );
    }
    printf("%d\n", minDif );
  }
  return 0;
}
