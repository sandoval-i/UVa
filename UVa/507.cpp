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

int paradas[20002] , max_current , max_so_far , l , r , tam , L , R;

int kadane( void )
{
  max_so_far = max_current = paradas[0];
  l = L = r = R = 0;
  foi( i , 1 , tam )
  {
    if( max_so_far + paradas[i] >= paradas[i] )
      max_so_far += paradas[i] , r = i;
    else
      max_so_far = paradas[i] , l = i , r = i;
    if( max_so_far > max_current )
      max_current = max_so_far , L = l , R = r;
    else if ( max_so_far == max_current )
    {
      if( r - l > R - L )
        L = l , R = r;
      else if( l < L )
        L = l , R = r;
    }
  }
  return max_current;
}

int main()
{
  int test , maximo , caso = 0;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d", &tam );
    --tam;
    foi( i , 0 , tam )  scanf("%d", &paradas[i] );
    maximo = kadane();
    if( maximo <= 0 )
      printf("Route %d has no nice parts\n", ++caso );
    else
      printf("The nicest part of route %d is between stops %d and %d\n", ++caso , L + 1 , R + 2 );
  }
  return 0;
}
