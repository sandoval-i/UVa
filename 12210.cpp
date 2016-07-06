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

int B , S , i , minDif , idx , dif, bachelors[10000] , spinsters[10000] , cant;
bitset < 10000 > used;
bool sol;
void solve( void )
{
  sol = true;
  for( int i = B - 1 ; i >= 0 && sol ; i-- )
  {
    minDif = 9999;
    sol = false;
    for( int j = 0 ; j < S ; j++ )
    {
      if( used[j] ) continue;
      sol = true;
      dif = abs( bachelors[i] - spinsters[j] );
      if( dif < minDif )
      {
        minDif = dif;
        idx = j;
        if( dif == 0 )
          break;
      }
    }
    used[idx] = true;
    cant = i+1;
  }
}


int main()
{
  int caso = 0;
  while( scanf("%d %d", &B , &S ) , B || S )
  {
    used.reset();
    foi( i , 0 , B ) scanf("%d", &bachelors[i] );
    foi( i , 0 , S ) scanf("%d", &spinsters[i] ) ;
    sort( bachelors , bachelors + B );
    solve();
    if( sol )
      printf("Case %d: 0\n", ++caso );
    else
      printf("Case %d: %d %d\n", ++caso , cant , bachelors[0] );
  }
  return 0;
}
