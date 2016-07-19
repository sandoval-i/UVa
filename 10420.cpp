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

int main()
{
  int n ;
  char a;
  map < string , int > data;
  string linea;
  scanf("%d", &n );
  cin.ignore();
  while( n-- )
  {
    string nombre;
    while( true )
    {
      a = getchar();
      if( a == ' ' )
        break;
      nombre.pb( a );
    }
    data[nombre]++;
    cin.ignore( 76 , '\n' );
  }
  for( map < string , int > :: iterator itr = data.begin() ; itr != data.end() ; itr++ )
    printf("%s %d\n", itr->first.c_str() , itr->second );
  return 0;
}
