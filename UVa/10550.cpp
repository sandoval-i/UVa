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
  int a , b , c , d , ans , aux;
  while( scanf("%d %d %d %d", &a , &b , &c , &d ) , a || b || c || d )
  {
    ans = 1080;
    aux = a - b;
    if( aux < 0 ) aux += 40;
    ans += aux * 9;
    aux = c - b;
    if( aux < 0 ) aux += 40;
    ans += aux * 9;
    aux = c - d;
    if( aux < 0 ) aux += 40;
    ans += aux * 9;
    printf("%d\n", ans );
  }
  return 0;
}
