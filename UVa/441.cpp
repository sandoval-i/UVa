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
  int k , datos[14];
  scanf( "%d" , &k );
  while( true )
  {
    foi( i , 0 , k )  scanf("%d", &datos[i] );
    foi( a , 0 , k - 5 )
      foi( b , a + 1 , k - 4  )
        foi( c , b + 1 , k - 3 )
          foi( d , c + 1 , k - 2 )
            foi( e , d + 1 , k - 1 )
              foi( f , e + 1 , k )
                printf("%d %d %d %d %d %d\n", datos[a] , datos[b] , datos[c] , datos[d] , datos[e] , datos[f] );
    scanf("%d", &k );
    if( k )
      printf("\n");
    else
      break;
  }
  return 0;
}
