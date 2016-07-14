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


int n , m , k , v , actual;

int main()
{
  while( scanf("%d %d" , &n , &m ) != EOF )
  {
    unordered_map < int , vi > grafo;
    foi( i , 0 , n )  scanf("%d", &actual ) , grafo[actual].pb( i + 1 );
    while( m-- )
    {
      scanf("%d %d", &k , &v );
      --k;
      vi &vecinos = grafo[v];
      if( k < vecinos.size ) printf("%d\n", vecinos[k] );
      else printf("0\n");
    }
  }
  return 0;
}
