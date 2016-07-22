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
  int n , contador ;
  while( scanf("%d", &n ) , n )
  {
    deque < int > baraja;
    for( ; n > 0 ; n-- )  baraja.pb( n );
    printf("Discarded cards:");
    contador = 0;
    while( baraja.size > 1 )
    {
      if( contador++ == 0 )
        printf(" %d", baraja[baraja.size - 1] );
      else
        printf(", %d", baraja[baraja.size - 1] );
      baraja.pop_back();
      baraja.push_front( baraja[baraja.size - 1] );
      baraja.pop_back();
    }
    printf("\nRemaining card: %d\n" , baraja[0] );
  }
  return 0;
}
