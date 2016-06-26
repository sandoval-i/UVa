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

int N , Q , query ;
vi marbles;

int main()
{
  int caso = 0  , dif;
  vi::iterator ans;
  bool found;
  while( scanf("%d %d", &N , &Q ) , N || Q )
  {
    marbles.assign( N , 0 );
    foi( i , N )
      scanf("%d", &marbles[i] );
    sort( marbles.begin() , marbles.end() );
    printf("CASE# %d:\n" , ++caso );
    foi( i , Q )
    {
      found = false;
      scanf("%d", &query );
      ans = lower_bound( marbles.begin() , marbles.end() , query );
      if( *ans == query )
        dif = ans - marbles.begin() + 1 , found = true;
      else if( *( ans + 1 ) == query )
        dif = ans - marbles.begin() , found = true;
      if( found )
        printf( "%d found at %d\n" , query ,  dif );
      else
        printf("%d not found\n", query  );
    }
  }
  return 0;
}
