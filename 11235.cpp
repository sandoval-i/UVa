#include <bits/stdc++.h>

using namespace std;

const int menosInfinito = -10000000;

struct Dato
{
  int inicio;
  int fin;
  int numApariciones;
};

struct SegmentTree
{
  vector < int > arbol;

  SegmentTree( vector < int > &base )
  {
    arbol.assign( 4 * base.size() , 0 );
    construir( base , 0 , base.size() - 1 , 0 );
  }

  void construir( vector< int > &base , int low , int high , int pos )
  {
    if( low == high )
    {
      arbol[pos] = base[low];
      return;
    }
    int mid = ( low + high ) / 2;
    construir( base , low , mid , 2 * pos + 1 );
    construir( base , mid + 1 , high  , 2 * pos + 2 );
    arbol[pos] = max( arbol[2*pos+1] , arbol[2*pos+2] );
  }

  int query( int low , int high , int qlow , int qhigh , int pos )
  {
    if( qlow <= low && qhigh >= high ) // Complete overlap
      return arbol[pos];
    if( qlow > high || qhigh < low ) // No overlap
      return menosInfinito;
    int mid = ( low + high ) / 2;
    return max( query( low , mid , qlow , qhigh , 2 * pos + 1 ) , query( mid+1 , high , qlow , qhigh , 2 * pos + 2 ) ); // Partial overlap
  }
};

map < int , Dato > mapaFrecuencias;
vector < int > frecuencias;
vector < int > datos;

int mayor( SegmentTree &arbol , int inicio , int fin , int size  )
{
  int maxInicio , maxQuery , maxFin;
  Dato datoInicio , datoFin;
  maxInicio = maxQuery = maxFin= -99999999;
  datoInicio = mapaFrecuencias[datos[inicio]];
  datoFin = mapaFrecuencias[datos[fin]];
  if( datoInicio.inicio < inicio && datoInicio.fin > fin )
    return fin - inicio +1;
  if( datoInicio.inicio < inicio )
  {
    maxInicio = abs( datoInicio.fin - inicio ) + 1;
    inicio = datoInicio.fin + 1;
  }
  if( datoFin.fin > fin )
  {
    maxFin = abs( datoFin.inicio - fin ) + 1;
    fin = datoFin.inicio - 1;
  }
  maxQuery = arbol.query( 0 , size , inicio , fin , 0 );
  return max( maxInicio , max( maxQuery , maxFin ) );
}

int main()
{
  int n, q , inicio , fin , actual;
  scanf("%d %d", &n , &q );
  while( true )
  {
    mapaFrecuencias.clear();
    frecuencias.assign( n , 0 );
    datos.assign( n , 0 );
    for( int i = 0 ; i < n ; i++ )
    {
      scanf("%d", &actual );
      datos[i] = actual;
      if( !mapaFrecuencias[actual].numApariciones++ )
        mapaFrecuencias[actual].inicio = i;
      else
        mapaFrecuencias[actual].fin = i;
    }
    for( int t = 0 ; t < n ; t++ )
      frecuencias[t] = mapaFrecuencias[datos[t]].numApariciones;
    SegmentTree nuevo( frecuencias );
    while( q-- )
    {
      scanf("%d %d", &inicio , &fin );
      printf("%d\n", mayor( nuevo , inicio - 1 , fin - 1 , datos.size() - 1 ) );
    }
    scanf("%d", &n );
    if( n == 0 )
      break;
    scanf("%d", &q );
  }
  return 0;
}
