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
  ll k , num , den , maximo , x;
  while( scanf("%lld", &k ) != EOF )
  {
    vector < pair < ll , ll > > ans;
    maximo = k << 1;
    for( ll y = k + 1 ; y <= maximo ; y++ )
    {
      num = k * y , den = y - k;
      if( num % den != 0 )  continue;
      x = num / den;
      if( x < y ) continue;
      ans.pb( make_pair( x , y ) );
    }
    printf("%lu\n", ans.size );
    foi( i , 0 , ans.size )
    printf("1/%lld = 1/%lld + 1/%lld\n", k , ans[i].first , ans[i].second );
  }
  return 0;
}
