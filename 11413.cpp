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

int n , m , vessels[1001] , voy , low , mid , high , last , suma , contenedor , tam;
unsigned long long total;

bool probar( int &maxCapacidad )
{
  contenedor = 0;
  tam = 1;
  foi( i , 0 , n )
  {
    if( vessels[i] > maxCapacidad )
      return false;
    if( contenedor + vessels[i] > maxCapacidad )
      contenedor = 0 , tam++;
    contenedor += vessels[i];
    if( tam > m )
      return false;
  }
  return true;
}

int solve()
{
  low = 1;
  high = total;
  last = high;
  while( low <= high )
  {
    mid = ( low + high ) / 2;
    if( probar( mid ) )
      high = mid - 1 , last = mid;
    else
      low = mid + 1;
  }
  return last;
}

int main()
{
  while( scanf("%d %d", &n , &m ) != EOF )
  {
    total = 0;
    foi( i , 0 , n ) scanf("%d", &vessels[i] ) , total += vessels[i];
    printf("%d\n", solve() );
  }
  return 0;
}
