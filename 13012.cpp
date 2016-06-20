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
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )


int main()
{
  int answer , actual , cont;
  while( scanf("%d", &answer ) != EOF )
  {
    cont = 0;
    foi( i , 5 )
    {
      scanf("%d", &actual );
      if( actual == answer )
        cont++;
    }
    printf("%d\n", cont );
  }
  return 0;
}
