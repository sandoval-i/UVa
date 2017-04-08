#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
typedef unsigned long ul;
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

vector < ul > comienzos;

string itoa( int number )
{
  ostringstream oss;
  oss<< number;
  return oss.str();
}

int main()
{
  ul voy = 0 , buscando , pos , queries ;
  string cadena = "" , aux;
  comienzos.pb(0);
  for( int i = 0 ; i <= 35000 ; i++ )
  {
    cadena += itoa( i + 1 );
    comienzos.pb( comienzos[last(comienzos)] + cadena.length() );
  }
  scanf("%lu", &queries );
  while( queries-- )
  {
    scanf("%lu", &buscando );
    buscando--;
    pos = lower_bound( comienzos.begin() , comienzos.end() , buscando ) - comienzos.begin();
    if( buscando == comienzos[pos--] )
    {
      printf("1\n");
      continue;
    }
    pos = buscando - comienzos[pos];
    printf("%c\n", cadena[pos] );
  }
  return 0;
}
