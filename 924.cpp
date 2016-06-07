#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;
typedef vector < bool > vb;
typedef queue < ii > qii;
typedef vector < int > vi;

struct Nodo
{
  vector < int > adjList;

  void addEdge( int &n )
  {
    this->adjList.push_back( n );
  }

};

struct Grafo
{
  vector < Nodo > vertices;
  Grafo( int &n )
  {
    Nodo a;
    this->vertices.assign( n , a );
  }

  ii BFS( int &inicio )
  {
    int mayor = -1;
    int dia = 0;
    int idActual , distancia , idViendo;
    qii colaBFS;
    ii actual;
    vb visitados( this->vertices.size() , false );
    vi nivel( this->vertices.size() , 0 );
    visitados[inicio] = true;
    colaBFS.push( ii( inicio , 0 ) );
    while( !colaBFS.empty() )
    {
      actual = colaBFS.front();
      idActual = actual.first;
      distancia = actual.second;
      colaBFS.pop();
      for( int i = 0 ; i < this->vertices[idActual].adjList.size() ; i++ )
      {
        idViendo = this->vertices[idActual].adjList[i];
        if( !visitados[idViendo] )
        {
          visitados[idViendo] = true;
          colaBFS.push( ii( idViendo , distancia + 1 ) );
          if( ++nivel[distancia+1] > mayor )
          {
            mayor = nivel[distancia+1];
            dia = distancia + 1;
          }
        }
      }
    }
    return ii( mayor , dia );
  }

};

int main()
{
  int E , numAmigos , nuevoAmigo , T , source;
  ii resultado;
  scanf("%d", &E );
  Grafo grafo( E );
  for( int i  = 0 ; i < E ; i++ )
  {
    scanf("%d", &numAmigos );
    while( numAmigos-- )
    {
      scanf( "%d" , &nuevoAmigo );
      grafo.vertices[i].addEdge( nuevoAmigo );
    }
  }
  scanf("%d", &T );
  while( T-- )
  {
    scanf("%d", &source );
    resultado = grafo.BFS( source );
    if( !resultado.second )
      printf("0\n");
    else
      printf("%d %d\n", resultado.first , resultado.second );
  }
  return 0;
}
