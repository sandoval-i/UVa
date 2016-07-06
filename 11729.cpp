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


struct Soldier
{
  int B , J;
};

Soldier soldiers[1001];
int N;

bool compr( Soldier s1 , Soldier s2 )
{
  if( s1.J == s2.J )
    return s1.B < s2.B;
  return s1.J > s2.J;
}

int main()
{
  unsigned long long caso = 0 , voyJ , voyB , ans;
  while( scanf("%d", &N ) , N )
  {
    foi( i , 0 , N ) scanf("%d %d", &soldiers[i].B , &soldiers[i].J );
    sort( soldiers , soldiers + N , compr );
    voyJ = voyB = ans = 0;
    foi( i , 0 , N )
    {
      voyB += soldiers[i].B;
      voyJ = voyB + soldiers[i].J;
      ans = max( ans , max( voyJ , voyB ) );
    }
    printf("Case %llu: %llu\n", ++caso , ans );
  }
  return 0;
}
