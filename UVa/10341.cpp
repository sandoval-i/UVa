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
#define EPS 1e-9

int main()
{
  double p , q , r , s , t , u ;
  double low , mid , high;
  long double res;
  int a;
  while( scanf("%lf %lf %lf %lf %lf %lf", &p , &q , &r , &s , &t , &u ) != EOF )
  {
    low = 0.0;
    high = 1.0;
    while( fabs( high - low ) > EPS )
    {
      mid = ( low + high ) / 2.0;
      res = p * exp( -mid ) + q * sin( mid ) + r * cos( mid ) + s * tan( mid ) + t * mid * mid + u;
      if( res < 0.0 )
        high = mid;
      else
        low = mid;
    }
    if( fabs( res ) <= 0.0001 )
      printf("%.4lf\n", mid );
    else
      printf("No solution\n");
  }
  return 0;
}
