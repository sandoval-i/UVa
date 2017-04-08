#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
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

int D , I , l;

int recurr( int pos , int llevo , int depth )
{
  if( depth == D )
    return llevo;
  ++depth;
  if( par( pos ) )
    return recurr( pos / 2 , ( llevo << 1 ) + 1 , depth );
  return recurr( ( pos + 1 ) / 2 , llevo << 1 , depth );
}

int main()
{
  scanf("%d", &l );
  while( l-- )
  {
    scanf("%d %d", &D , &I );
    printf("%d\n", recurr( I , 1 , 1 ) );
  }
  return 0;
}
