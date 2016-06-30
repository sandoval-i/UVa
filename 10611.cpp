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

int main()
{
  int N , Q , act , menor , mayor;
  bool men , may;
  scanf("%d", &N );
  vi chimps( N , 0 );
  foi( i , N )
    scanf("%d", &chimps[i] );
  scanf("%d", &Q );
  while( Q-- )
  {
    scanf("%d", &act );
    men = may = true;
    mayor = upper_bound( chimps.begin() , chimps.end() , act ) - chimps.begin();
    menor = lower_bound( chimps.begin() , chimps.end() , act ) - chimps.begin();
    if( mayor == chimps.size )
      may = false;
    if( menor == chimps.size )
      men = false;
    else if( chimps[menor] >= act )
      menor--;
    if( menor < 0 )
      men = false;
    if( chimps[last(chimps)] < act )
      menor = last( chimps ) , men = true;
    if( men )
      printf("%d ", chimps[menor] );
    else
      printf("X ");
    if( may )
      printf("%d\n" , chimps[mayor] );
    else
      printf("X\n");
  }
  return 0;
}
