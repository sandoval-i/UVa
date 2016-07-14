#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define pb push_back
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

map < vi , int > frecuencias;
vi data;

int main()
{
  int n , actual , maximo , ans;
  data.assign( 5 , 0 );
  while( scanf("%d", &n ) , n )
  {
    frecuencias.clear();
    ans = maximo = 0;
    foi( i , 0 , n )
    {
      foi( j , 0 , 5 )  scanf("%d", &data[j] );
      sort( data.begin() , data.end() );
      maximo = max( ++frecuencias[data] , maximo );
    }
    for( map < vi , int > :: iterator itr = frecuencias.begin() ; itr != frecuencias.end() ; itr++ )
      if( itr->second == maximo )
        ans += maximo;
    printf("%d\n", ans );
  }
  return 0;
}
