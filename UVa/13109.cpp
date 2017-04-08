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

int elephants[100001];

int main()
{
  int test , M , W , llevo , tam , suma;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &M , &W );
    llevo = tam = 0;
    foi( i , 0 , M )
      scanf("%d", &elephants[i] );
    sort( elephants , elephants + M );
    foi( i , 0 , M )
    {
      suma = llevo + elephants[i];
      if( suma > W )
        break;
      llevo = suma;
      tam++;
    }
    printf("%d\n", tam );
  }
  return 0;
}
