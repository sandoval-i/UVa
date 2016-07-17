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

int n , p , bars[21];

bool solve( int i , int llevo )
{
  if( llevo + bars[i] == n )
    return true;
  if( i == p )
    return false;
  if( llevo + bars[i] > n )
    return solve( i + 1 , llevo );
  return solve( i + 1 , llevo ) || solve( i + 1 , llevo + bars[i] );
}

int main()
{
  int test;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &n , &p );
    foi( i , 0 , p )
      scanf("%d", &bars[i] );
    if( !n )
      printf("YES\n" );
    else
      printf("%s\n", solve( 0 , 0 ) ? "YES" : "NO" );
  }
  return 0;
}
