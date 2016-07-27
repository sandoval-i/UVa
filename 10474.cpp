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
  int N , Q , marbles[10001] , caso = 0 , ans , query;
  bitset < 10001 > existe;
  while( scanf("%d %d", &N , &Q ) , N || Q )
  {
    existe.reset();
    printf("CASE# %d:\n" , ++caso);
    foi( i , 0 , N )  scanf("%d", &marbles[i] ) , existe[marbles[i]] = true;
    sort( marbles , marbles + N );
    while( Q-- )
    {
      scanf("%d", &query );
      if( query > marbles[N-1] || query < marbles[0] || !existe[query] )
      {
        printf("%d not found\n" , query );
        continue;
      }
      ans = lower_bound( marbles , marbles + N , query ) - marbles;
      if( ans == N || marbles[ans] != query )
        printf("%d not found\n", query );
      else
        printf("%d found at %d\n", query , ans + 1   );
    }
  }
  return 0;
}
