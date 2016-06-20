#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef unsigned long long ull;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

const ull maximoPro = 2000000000;
const ull maximaSuma = 2000;
const ull limite = 2000;

int main()
{
  ull k = 1e6 , x , y , d;
  for( ull a = 1 ; a < limite ; a++ )
  {
    if( a * a * a * a > maximoPro || 4 * a > maximaSuma )
      break;
    for( ull b = a ; b < limite - a ; b++ )
    {
      if( a * b * b * b > maximoPro || a + 3 * b > maximaSuma )
        break;
      for( ull c = b ; c < limite - ( a + b ); c++ )
      {
        if( a * b * c * c > maximoPro || a + b + 2 * c > maximaSuma )
          break;
        x = a + b + c;
        y = a * b * c;
        if( x > maximaSuma || y > maximoPro )
          break;
        if( y <= k )
          continue;
        if( ( k * x ) % ( y - k ) != 0 )
          continue;
        d = ( k * x ) / ( y - k );
        if( c > d )
          continue;
        if( x + d > maximaSuma || y * d > maximoPro )
          continue;
        if( ( x + d ) * k == y * d )
          printf("%.2lf %.2lf %.2lf %.2lf\n", a / 100.0 , b / 100.0 , c / 100.0 , d / 100.0 );
      }
    }
  }
  return 0;
}
