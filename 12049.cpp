#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;

int main()
{
  int T , tam1 , tam2 , actual , contador;
  scanf("%d", &T );
  while( T-- )
  {
    contador = 0;
    map < int , int > lista;
    scanf("%d %d", &tam1 , &tam2 );
    while( tam1-- )
    {
      scanf("%d", &actual );
      lista[actual]++;
    }
    while( tam2-- )
    {
      scanf("%d", &actual );
      lista[actual]--;
    }
    for( map < int , int >::iterator it = lista.begin() ; it != lista.end() ; it++ )
      if( it->second != 0 )
        contador += abs( it->second );
    printf("%d\n", contador );
  }
  return 0;
}
