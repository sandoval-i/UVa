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

bitset < 100 > esPrimo;
vi primes;
int n , caso , bitmask;

void sieve( int limite )
{
  esPrimo.set();
  esPrimo[0] = esPrimo[1] = false;
  foi( i , 2 , limite + 1 )
  {
    if( esPrimo[i] )
    {
      for( int j = i * i ; j <= limite ; j += i )
        esPrimo[j] = false;
      primes.pb( i );
    }
  }
}

void primeRing( int indice , vi voy , int bitmask )
{
  if( indice == n )
  {
    if( esPrimo[voy[n-1] + voy[0]] )
    {
      foi( i , 0 , n )
      {
        printf("%d", voy[i] );
        if( i < n - 1 ) printf(" ");
      }
      printf("\n");
    }
    return;
  }
  for( int i = 2 ; i <= n ; i++ )
    if( esPrimo[voy[indice-1]+i] && testBit( bitmask , i ) == 0 )
      voy[indice] = i , primeRing( indice + 1 , voy , turnOnBit( bitmask , i ) );
}

int main()
{
  sieve( 50 );
  vi a( 17 , 1 );
  caso = 0;
  while( scanf("%d", &n ) != EOF )
  {
    if( caso )printf("\n");
    printf("Case %d:\n", ++caso );
    primeRing( 1 , a , 1 );
  }
  return 0;
}
