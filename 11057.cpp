#include <bits/stdc++.h>

using namespace std;

int main()
{
  int numLibros;
  while( scanf("%d", &numLibros ) != EOF )
  {
    int money;
    vector < int > precios( numLibros , 0 );
    vector < pair < int , int > > posiblesSoluciones;
    pair < int , int > mayor;
    mayor.first = ( 1 << 30 );
    mayor.second = -100000;
    for( int t = 0 ; t < numLibros ; t++ )
    {
      scanf("%d" , &precios[t]);
    }
    scanf("%d", &money );
    sort( precios.begin() , precios.end() );
    for( int t = 0 ; t < numLibros ; t++ )
      if( binary_search( precios.begin() , precios.end() , money - precios[t] ) )
        posiblesSoluciones.push_back( make_pair( precios[t] , money-precios[t] ) );
    for( int t = 0 ; t < posiblesSoluciones.size() ; t++ )
      if( abs( posiblesSoluciones[t].first - posiblesSoluciones[t].second ) < abs( mayor.first - mayor.second ) )
        mayor = posiblesSoluciones[t];
      printf("Peter should buy books whose prices are %d and %d.\n\n", mayor.first , mayor.second );
    cin.ignore();
  }
  return 0;
}
