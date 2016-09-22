#include <bits/stdc++.h>

using namespace std;

unsigned long long factoriales[21];

unsigned long long rep( char *palabra )
{
  unsigned long long ans = 1;
  map < char , int > frec;
  int tam = strlen(palabra);
  for( int i = 0 ; i < tam ; ++i )
    ++frec[palabra[i]];
  for( map < char , int > :: iterator it = frec.begin() ; it != frec.end() ; ++it )
    ans *= factoriales[it->second];
  return ans;
}

int main()
{
  int casos , caso = 0;
  char palabra[22];
  factoriales[0] = 1;
  for( int i = 1 ; i < 21 ; ++i )
    factoriales[i] = factoriales[i-1] * i;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%s", palabra );
    printf("Data set %d: %llu\n", ++caso ,  factoriales[strlen(palabra)] / rep(palabra) );
  }
  return 0;
}
