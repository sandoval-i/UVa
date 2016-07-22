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
  int round , llevoMal , llevoBien , tam;
  string respuesta , guesses;
  char aux;
  bool win , lose;
  while( scanf("%d", &round ) , round != - 1 )
  {
    unordered_map < char , int > apariciones;
    unordered_map < char , bool > didBad , didGood;
    llevoMal = llevoBien = tam = win = lose = 0;
    getchar();
    while( aux = getchar() , aux != '\n' ) apariciones[aux]++ , tam++;
    while( aux = getchar() , aux != '\n' && !win && !lose )
    {
      if( apariciones.find( aux ) != apariciones.end() )
      {
        if( didGood.find( aux ) == didGood.end() )
        {
          llevoBien += apariciones[aux];
          if( llevoBien == tam )
            win = true;
          didGood[aux] = true;
        }
      }
      else
      {
        if( didBad.find( aux ) == didBad.end() )
        {
          if( ++llevoMal == 7 )
            lose = true;
          didBad[aux] = true;
        }
      }
    }
    if( aux != '\n' )
      cin.ignore( 10000 , '\n' );
    printf("Round %d\n", round );
    if( win )
      printf("You win.\n");
    else if( lose )
      printf("You lose.\n");
    else
      printf("You chickened out.\n");
  }
  return 0;
}
