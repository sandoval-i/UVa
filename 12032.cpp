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

int maxDif , test , rungs , need , caso , escalones[100002];

bool can( int k )
{
  foi( i , 0 , rungs )
  {
    need = escalones[i+1] - escalones[i];
    if( need > k )
      return false;
    if( need == k )
      k--;
  }
  return true;
}

int main()
{
  caso = 0;
  scanf("%d", &test );
  while( test-- )
  {
    maxDif =  0;
    scanf("%d", &rungs );
    foi( i , 1 , rungs + 1 )
      scanf("%d", &escalones[i] ) , maxDif = max( maxDif , escalones[i] - escalones[i-1] );
    if( !can( maxDif ) )
      maxDif++;
    printf("Case %d: %d\n", ++caso ,  maxDif );
  }
  return 0;
}
