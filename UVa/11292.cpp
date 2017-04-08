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

unsigned long suma;
bool solution;
int n , m , pos;
vi::iterator ans;
vi heads , knights;

int main()
{
  while( scanf("%d %d", &n , &m ) , n || m )
  {
    solution = true;
    heads.assign( n , 0 );
    knights.assign( m , 0 );
    suma = 0;
    foi( i , 0 , n ) scanf("%d", &heads[i] );
    foi( i , 0 , m ) scanf("%d", &knights[i] );
    if( n > m )
    {
      printf("Loowater is doomed!\n");
      continue;
    }
    sort( heads.begin() , heads.end() );
    sort( knights.begin() , knights.end() );
    for( int i = n - 1; i >= 0 ; --i )
    {
      ans = lower_bound( knights.begin() , knights.end() , heads[i] );
      if( ans == knights.end() )
        { solution = false , i = -2 ; continue; }
      pos = ans - knights.begin();
      suma += knights[pos];
      knights.erase( ans );
    }
    if( !solution )
      printf("Loowater is doomed!\n");
    else
      printf("%lu\n", suma );
  }
  return 0;
}
