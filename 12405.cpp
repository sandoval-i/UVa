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

char field[101];
bitset <101> covered;

int N , total , k;

void cover( int i )
{
  i--;
  k = 3;
  while( k-- )
  {
    if( i >= 0 && i < N  )
      covered[i] = true;
    i++;
  }
}

int main()
{
  int test , caso = 0;
  scanf("%d", &test );
  while( test-- )
  {
    total = 0;
    scanf("%d", &N );
    scanf("%s", field );
    covered.reset();
      if( field[i] != '#' )
        if( !covered[i] )
          cover( i + 1 ) , total++;
    printf("Case %d: %d\n", ++caso , total );
  }
  return 0;
}
