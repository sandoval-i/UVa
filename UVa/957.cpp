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

int numYears , numPopes , mejor , dif , beginYear , searching;
vi::iterator endYear , beginNow , endNow;
vi years;

int main()
{
  while( scanf("%d", &numYears ) != EOF )
  {
    mejor = 0;
    scanf("%d", &numPopes );
    years.assign( numPopes , 0 );
    foi( i , numPopes )
      scanf("%d", &years[i] );
    foi( i , numPopes )
    {
      searching = years[i] + numYears - 1 ;
      endNow = upper_bound( years.begin() , years.end() , searching ) - 1;
      dif = endNow - years.begin();
      dif -= i ;
      dif++;
      if( dif > mejor )
        mejor = dif , beginYear = i , endYear = endNow;
    }
    printf("%d %d %d\n", mejor , years[beginYear] , *endYear );
    ignore;
  }
  return 0;
}
