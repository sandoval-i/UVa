#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )

int total , numero , best , resultado;
vi songs ;

void backtrack( int llevo , int indice , int usados )
{
  if( llevo > total )
    return;
  if( indice == songs.size )
  {
    if( llevo >= best )
    {
      best = llevo;
      resultado = usados;
    }
    return;
  }
  backtrack( llevo , indice + 1 , usados);
  backtrack( llevo + songs[indice] , indice + 1 , usados | ( 1 << indice  ) );
}

int main()
{
  while( scanf("%d%d", &total , &numero ) != EOF )
  {
    best = 0;
    songs.assign( numero , 0 );
    foi( i , songs.size )
      scanf("%d", &songs[i] );
    backtrack( 0 , 0 , 0 );
    int i = 0 ;
    while( 1 << i <= resultado )
    {
      if( resultado & ( 1 << i ) )
      printf("%d ", songs[i] );
      i++;
    }
    printf("sum:%d\n", best );
  }
  return 0;
}
