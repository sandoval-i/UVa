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

int salida[1001];

int main()
{
  int n , actual , indiceSalida , num;
  bool can , in;
  while( true )
  {
    scanf("%d", &n );
    if( !n )  break;
    while( scanf("%d", &actual ) , actual )
    {
      can = true;
      stack < int > datos;
      vi salidaSimulacion;
      num = 1;
      indiceSalida = 0;
      salida[0] = actual;
      foi( i , 1 , n )  scanf("%d", &salida[i] );
      while( num <= n  && salidaSimulacion.size < n )
      {
        datos.push( num );
        while( !datos.empty() && datos.top() == salida[indiceSalida] )
        {
          salidaSimulacion.pb( datos.top() );
          datos.pop();
          indiceSalida++;
        }
        ++num;
      }
      while( !datos.empty() )
      {
        salidaSimulacion.pb( datos.top() );
        datos.pop();
      }
      foi( i , 0 , salidaSimulacion.size )
        if( salidaSimulacion[i] != salida[i] )
        {
          can = false;
          break;
        }
        printf("%s\n", can ? "Yes" : "No" );
    }
    printf("\n");
  }
  return 0;
}
