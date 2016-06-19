#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii ;
typedef pair < int , ii > iii;
typedef vector < int > vi;
typedef queue < iii > qii;
typedef vector < bool > vb;

const int INF = 999999 ;

int posX[] = { 0 , 1 , 0 , -1 };
int posY[] = { 1 , 0 , -1 , 0 };

int filas , columnas , actualX , actualY , distancia , viendoX , viendoY , suma , costoVoy , costoActual;
iii actual;

bool isIn( int &x , int &y )
{
  if( x >= 0 && y >= 0 )
    if( x < filas && y < columnas )
      return true;
  return false;
}

int dijkstra( vector < vi > &grafo , int inicioX , int inicioY , int finX , int finY )
{
  qii colaDijkstra;
  vector < vb > visitados( filas , vb( columnas , false ) );
  vector < vi > costos( filas , vi ( columnas , INF ) );
  priority_queue < iii , vector < iii > , greater < iii > > colaPrioridad;
  colaPrioridad.push( iii( grafo[inicioX][inicioY] , ii( inicioX , inicioY ) ) );
  costos[inicioX][inicioY] = grafo[inicioX][inicioY];
  while( !colaPrioridad.empty() )
  {
    actual = colaPrioridad.top();
    colaPrioridad.pop();
    actualX = actual.second.first;
    actualY = actual.second.second;
    distancia = actual.first;
    if( !visitados[actualX][actualY] )
    {
      visitados[actualX][actualY] = true;
      costoActual = costos[actualX][actualY];
      for( int i = 0 ; i < 4 ; i++ )
      {
        viendoX = actualX + posX[i];
        viendoY = actualY + posY[i];
        if( isIn( viendoX , viendoY ) )
        {
          costoVoy = grafo[viendoX][viendoY];
          suma = costoActual + costoVoy;
          if( suma < costos[viendoX][viendoY] )
          {
            costos[viendoX][viendoY] = suma;
            colaPrioridad.push( iii( suma , ii( viendoX , viendoY ) ) );
          }
        }
      }
    }
  }
  return costos[finX][finY];
}

int main()
{
  int test ;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &filas , &columnas );
    vector < vi > puzzle( filas , vi( columnas , 0 ) );
    for( int i = 0 ; i < filas ; i++ )
      for( int j = 0 ; j < columnas ; j++ )
        scanf("%d", &puzzle[i][j] );
    printf("%d\n", dijkstra( puzzle , 0 , 0 , filas - 1 , columnas - 1 ) );
  }
  return 0;
}
