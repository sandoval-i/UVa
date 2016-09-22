#include <bits/stdc++.h>

using namespace std;

#define MAX_NODOS 26

vector < vector < int > > grafo;
int costos[MAX_NODOS] , memo[MAX_NODOS];

int dp( int from )
{
  if( memo[from] != -1 )  return memo[from];
  int maximo = costos[from];
  for( int i = 0 ; i < grafo[from].size() ; ++i )
  {
    int to = grafo[from][i];
    maximo = max( maximo , costos[from] + dp( to ) );
  }
  return memo[from] = maximo;
}

int main()
{
  int casos , part , origen , destino , maximo;
  string linea , token;
  scanf("%d", &casos );
  cin.ignore( 100000 , '\n' );
  cin.ignore( 100000 , '\n' );
  while( casos-- )
  {
    grafo.assign( MAX_NODOS , vector < int > () );
    memset( memo , -1 , sizeof memo );
    while( getline( cin , linea ) , linea.size() > 0 )
    {
      stringstream tokenizador( linea );
      part = 0;
      while( tokenizador >> token )
      {
        if( !part )
          destino = token[0] - 'A';
        else if( part == 1 )
          costos[destino] = atoi( token.c_str() );
        else if( part == 2 )
        {
          for( int i = 0 ; i < token.size() ; ++i )
            grafo[(int)(token[i]-'A')].push_back(destino);
        }
        ++part;
      }
    }
    maximo = -1;
    for( int i = 0 ; i < grafo.size() ; ++i )
      if( grafo[i].size() ) maximo = max( maximo , dp(i) );
    printf("%d\n", maximo );
    if( casos )
      puts("");
  }
  return 0;
}
