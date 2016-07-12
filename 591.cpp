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

int n , heights[51] , total , each , mov;

int main()
{
  int caso = 0;
  while( scanf("%d", &n ) , n )
  {
    total = mov = 0;
    foi( i , 0 , n )  scanf("%d", &heights[i] ) , total += heights[i];
    each = total / n;
    foi( i , 0 , n )
    {
      if( heights[i] <= each )  continue;
      mov += heights[i] - each;
    }
    printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++caso , mov );
  }
  return 0;
}
