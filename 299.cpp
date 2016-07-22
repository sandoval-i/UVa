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

int arreglo[51];

int main()
{
  int test , tam , ans ,temp;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d", &tam );
    foi( i , 0 , tam )  scanf("%d", &arreglo[i] );
    ans = 0;
    for( int i = 1 ; i < tam ; i++ )
      for( int j = 0 ; j < tam - i ; j++ )
        if( arreglo[j] > arreglo[j+1] )
        {
          ans++;
          temp = arreglo[j];
          arreglo[j] = arreglo[j+1];
          arreglo[j+1] = temp;
        }
    printf("Optimal train swapping takes %d swaps.\n", ans );
  }
  return 0;
}
