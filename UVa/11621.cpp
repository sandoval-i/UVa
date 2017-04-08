#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;

typedef long long ll;
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

int main()
{
  unsigned long max = 1L << 33 , resul;
  vector < unsigned long > dos , tres , todos;
  dos.pb(1);
  tres.pb(1);
  for( unsigned long i = 2 ; i < max ; i <<= 1 )
    dos.pb( i );
  for( unsigned long i = 3 ; i < max ; i = i + ( i << 1 )  )
    tres.pb( i );
  foi( i , dos.size )
    foi( j , tres.size )
    {
      resul = dos[i] * tres[j];
      if( resul > max )
        break;
      todos.pb( resul );
    }
  sort( todos.begin() , todos.end() );
  while( scanf("%lu", &resul ) , resul )
    printf("%lu\n", *lower_bound( todos.begin() , todos.end() , resul ) );
  return 0;
}
