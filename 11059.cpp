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

ll numeros[20];

int main()
{
  ll maxProduct , llevo;
  int tam , caso = 0;
  while( scanf("%d", &tam ) != EOF )
  {
    foi( i , 0 , tam )  scanf("%lld", &numeros[i] );
    maxProduct = numeros[0];
    foi( i , 0 , tam )
    {
      maxProduct = max( maxProduct , numeros[i] );
      llevo = numeros[i];
      foi( j , i + 1 , tam )
      {
        llevo *= numeros[j];
        maxProduct = max( maxProduct , llevo );
      }
    }
    if( maxProduct > 0 )
      printf("Case #%d: The maximum product is %lld.\n\n", ++caso , maxProduct );
    else
      printf("Case #%d: The maximum product is 0.\n\n", ++caso );
  }
  return 0;
}
