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
  int f , r ;
  double ans , rearC[11] , frontC[11];
  while( true )
  {
    scanf("%d", &f );
    if( !f )
      break;
    scanf("%d", &r );
    foi( i , 0 , f )  scanf("%lf", &frontC[i] );
    foi( i , 0 , r )  scanf("%lf", &rearC[i] );
    ans = 0.00;
    vector < double > posibilidades;
    foi( i , 0 , r )
      foi( j , 0 , f )
        posibilidades.pb( rearC[i] / frontC[j] );
    sort( posibilidades.begin() , posibilidades.end() );
    foi( i , 0 , posibilidades.size - 1 )
      if( posibilidades[i+1] / posibilidades[i] > ans ) ans = posibilidades[i+1] / posibilidades[i];
    printf("%.2f\n", ans  );
  }
  return 0;
}
