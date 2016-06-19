#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii ;
typedef vector < int > vi;

const int INF = 999999;

struct Nodo
{
  vector < ii > adjList;
  void addEdge( int &fin , int &costo )
  {
    adjList.push_back( ii( fin , costo ) );
  }
};

struct Grafo
{
  vector < Nodo > nodos;
  Grafo( int &n )
  {
    Nodo a;
    nodos.assign( n , a );
  }

  void connect( int &inicio , int &fin , int &costo )
  {
    nodos[inicio].addEdge( fin , costo );
    nodos[fin].addEdge( inicio , costo );
  }


  int dijsktra( int &inicio , int &fin )
  {
    int size = nodos.size() , suma , idActual , costoActual , idVoy , costoVoy;
    vi costo( size , INF );
    costo[inicio] = 0;
    vector < bool > visitados( size , false );
    priority_queue < ii , vector < ii > , greater < ii > > sinVisitar;
    sinVisitar.push( ii( 0 , inicio ) );
    ii actual , visit;
    while( !sinVisitar.empty() )
    {
      actual = sinVisitar.top();
      idActual = actual.second;
      costoActual = actual.first;
      sinVisitar.pop();
      if( !visitados[idActual] )
      {
        visitados[idActual] = true;
        for( int t = 0 ; t < nodos[idActual].adjList.size() ; t++ )
        {
          visit = nodos[idActual].adjList[t];
          idVoy = visit.first;
          costoVoy = visit.second;
          suma = costoVoy + costoActual;
          if( suma < costo[idVoy] )
          {
            costo[idVoy] = suma;
            sinVisitar.push( ii( suma , idVoy ) );
          }
        }
      }
    }
    if( costo[fin] == INF )
    {
      return -1;
    }
    return costo[fin];
  }

};

int main()
{
  int N , n , m , s , t , inicio , fin , costo , x = 0 , resul;
  scanf("%d", &N );
  while( N-- )
  {
    scanf("%d %d %d %d", &n , &m , &s , &t );
    Grafo graph( n );
    while( m-- )
    {
      scanf("%d %d %d", &inicio , &fin , &costo );
      graph.connect( inicio , fin , costo );
    }
    resul = graph.dijsktra( s , t );
    if( resul == -1 )
      printf("Case #%d: unreachable\n" , ++x );
    else
      printf("Case #%d: %d\n", ++x , resul );
  }
  return 0;
}
