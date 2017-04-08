#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )


int main()
{
  int N , actual , actual2 , costo , llevo , suma;
  while( true )
  {
    costo = llevo = 0;
    priority_queue < int , vi , greater < int > > cola;
    scanf("%d", &N );
    if( !N )
      break;
    while( N-- )
    {
      scanf("%d", &actual );
      cola.push( actual );
    }
    while( cola.size > 1 )
    {
      actual = cola.top() , cola.pop();
      actual2 = cola.top() , cola.pop();
      suma = actual + actual2;
      costo += suma;
      cola.push( suma );
    }
    printf("%d\n", costo );
  }
  return 0;
}
