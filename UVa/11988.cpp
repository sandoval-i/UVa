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

int main()
{
  string linea;
  list < char > resul;
  list < char >::iterator iter = resul.begin();
  while( getline( cin , linea ) )
  {
    resul.clear();
    iter = resul.begin();
    foi( i , 0 , linea.length() )
    {
      if( linea[i] == '[' )
      {
        iter = resul.begin();
        continue;
      }
      if( linea[i] == ']' )
      {
        iter = resul.end();
        continue;
      }
      resul.insert( iter , linea[i] );
    }
    for( iter = resul.begin() ; iter != resul.end() ; iter++ ) printf("%c", *iter );
    printf("\n");
  }
  return 0;
}
