#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; ++i )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define numDenominaciones 5

unsigned long long denominaciones[] = { 1 , 5 , 10 , 25 , 50 } , numWays[30001][5];

unsigned long long change( int value , int index )
{
  if( value == 0 )  return 1;
  if( value < 0 || index == numDenominaciones ) return 0;
  if( numWays[value][index] != -1 )  return numWays[value][index];
  return numWays[value][index] = change( value , index + 1 ) + change( value - denominaciones[index] , index );
}

int main()
{
  int moneda;
  unsigned long long ans;
  memset( numWays , -1 , sizeof numWays );
  while( scanf("%d", &moneda ) != EOF )
  {
    ans = change( moneda , 0 );
    if( ans > 1 )
      printf("There are %llu ways to produce %d cents change.\n", ans , moneda );
    else
      printf("There is only 1 way to produce %d cents change.\n" , moneda );
  }
  return 0;
}
