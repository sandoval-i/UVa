#include <bits/stdc++.h>

using namespace std;

int low , high , mid;

void ceilBinary( vector < int > &lis , vector < int > &sucesores , vector < int > &numeros , int &nuevoIndice )
{
  low = 0 ;
  high = lis.size() - 1;
  while( low + 1 != high )
  {
    mid = ( low + high ) / 2;
    if( numeros[lis[mid]] > numeros[nuevoIndice]  )
      high = mid;
    else
      low = mid;
  }
  lis[high] = nuevoIndice;
  sucesores[nuevoIndice] = lis[high-1];
}

int main()
{
  vector < int > numeros , sucesores , lis ;
  deque < int > camino;
  int aux , size , comienzo ;
  while( scanf("%d", &aux ) == 1 )
  {
    numeros.push_back( aux );
  }
  size = numeros.size();
  sucesores.assign( size , -1 );
  for( int i = 0 ; i < size ; i++ )
  {
    if( lis.empty() ) // Caso vacio
    {
      lis.push_back(i);
      continue;
    }
    if( numeros[i] > numeros[ lis[ lis.size() - 1 ] ] ) // Agregar al final
    {
      lis.push_back(i);
      sucesores[i] = lis[ lis.size() - 2 ];
    }
    else if( numeros[i] < numeros[ lis[ 0 ] ]  ) // Agregar al comienzo
      lis[0] = i;
    else // Agregar usando busqueda binaria
      ceilBinary( lis , sucesores , numeros , i );
  }
    comienzo = lis[lis.size() - 1];
    while( comienzo != -1 )
    {
      camino.push_front( numeros[comienzo] );
      comienzo = sucesores[comienzo];
    }
    printf("%lu\n-\n", lis.size() );
    for( int t = 0 ; t < camino.size() ; t++ )
      printf("%d\n", camino[t] );
  return 0;
}
