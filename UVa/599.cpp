#include <bits/stdc++.h>

using namespace std;

const int dif = 65;

struct Nodo
{
  vector < int > adjList ;
};

bitset< 26 > visitados , existe;
vector < Nodo > Grafo;
int numVisitados;

void total( int i )
{
  for( int j = 0 ; j < Grafo[i].adjList.size() ; j++ )
    if( !visitados[Grafo[i].adjList[j]] )
    {
      visitados[Grafo[i].adjList[j]] = true;
      numVisitados++;
      total( Grafo[i].adjList[j] );
    }
}

int main()
{
  char origen , salida;
  int test , entrada, llegada , acorns , trees;
  string linea;
  Nodo a;
  scanf("%d\n", &test );
  while( test-- )
  {
    acorns = trees = 0;
    Grafo.assign( 26 , a );
    visitados.reset();
    existe.reset();
    while( getline( cin , linea ) && linea[0] != '*' )
    {
      sscanf( linea.c_str() , "(%c,%c)", &origen , &salida );
      entrada = int( origen ) - dif;
      llegada = int( salida ) - dif;
      Grafo[ entrada ].adjList.push_back( llegada );
      Grafo[ llegada ].adjList.push_back( entrada );
    }
    getline( cin , linea );
    char *tokenizar = new char[linea.length() + 1];
    strcpy( tokenizar , linea.c_str() );
    char *pch = strtok( tokenizar , "," );
    while( pch )
    {
      existe[ int( pch[0] ) - dif ] = true;
      pch = strtok( NULL , "," );
    }
    for( int i = 0 ; i < 27 ; i++ )
      if( existe[i] && !visitados[i] )
      {
        numVisitados = 0;
        total( i );
        if( numVisitados == 0 )
          acorns++;
        else
          trees++;
      }
  printf("There are %d tree(s) and %d acorn(s).\n", trees , acorns );
  }
  return 0;
}
