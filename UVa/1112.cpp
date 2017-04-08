#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii ;
typedef vector < int > vi;

const int INF = 1e8;


struct Nodo
{
  vector < ii > adjList;
  void addEdge( int &fin , int &costo )
  {
    adjList.push_back( ii( fin , costo ) );
  }
};

Nodo a;

struct Grafo
{
  vector < Nodo > nodos;
  Grafo( int n )
  {
    nodos.assign( n , a );
  }

  void connect( int &inicio , int &fin , int &costo )
  {
    nodos[inicio].addEdge( fin , costo );
  }

  int dijsktra( int &inicio , int &tiempo )
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
    int total = 0;
    for( int i = 1 ; i < costo.size() ; i++ )
      if( costo[i] <= tiempo )
        total++;
    return total;
  }
};

int main()
{
  int N , E , T , M , test , salida , llegada , costo;
  scanf("%d", &test );
  while( test-- )
  {
    cin.ignore();
    scanf("%d %d %d %d", &N , &E , &T , &M );
    Grafo grafo( N + 1 );
    while( M-- )
    {
      scanf("%d %d %d", &salida , &llegada , &costo );
      grafo.connect( llegada , salida , costo );
    }
    printf("%d\n", grafo.dijsktra( E , T ) );
    if( test != 0 )
      printf("\n");
  }
  return 0;
}
