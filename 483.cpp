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
  char a;
  string b , r;
  while( getline( cin , b ) )
  {
    stringstream tok( b );
    vector < string > imprime;
    while( tok >> r )
      imprime.pb( r );
    foi( j , 0 , imprime.size )
    {
      for( int i = imprime[j].size - 1 ; i >= 0 ; i-- )
        printf("%c", imprime[j][i] );
      if( j < imprime.size - 1 )
        printf(" ");
    }
    printf("\n");
  }
  return 0;
}
