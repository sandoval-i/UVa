#include <bits/stdc++.h>

using namespace std;

int main()
{
  int casos , numeros[100] , num , maximo;
  string linea , tok;
  scanf("%d", &casos );
  cin.ignore( 10 , '\n' );
  while( casos-- )
  {
    getline( cin , linea );
    stringstream tokenizador( linea );
    num = -1;
    while( tokenizador >> tok )
      numeros[++num] = atoi( tok.c_str() );
    ++num;
    maximo = 1;
    for( int i = 0 ; i < num ; ++i )
      for( int j = i + 1 ; j < num ; ++j )
        maximo = max( maximo , __gcd( numeros[i] , numeros[j] ) );
    printf("%d\n", maximo );
  }
  return 0;
}
