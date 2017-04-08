#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define size size()
#define pb push_back
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

int main()
{
  int test , a , b , ans , caso = 0;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &a , &b );
    ans = 0;
    for( ; a <= b ; a++ )
      if( impar( a ) )
        ans += a;
    printf("Case %d: %d\n", ++caso , ans );
  }
  return 0;
}
