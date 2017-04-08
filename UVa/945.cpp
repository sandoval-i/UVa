#include <bits/stdc++.h>

using namespace std;



struct container
{
  int capacidad  , llevo , numero;
  deque< int > paquetes;
  container( int numero , int capacidad )
  {
    this->numero = numero;
    this->capacidad = capacidad;
    this->llevo = 0;
  }
};
vector< container > cargoShip ;
int menorNumPaquetes , p , maxCapacidadActual , menorNumero;
container aux( 0 , 0 );
vector< container > posiblesContainers , posiblesContainers2;

bool comparadorPaquetes( container contenedor1 , container contenedor2 )
{
  return contenedor1.paquetes.size() < contenedor2.paquetes.size();
}

bool comparadorCapacidad( container contenedor1 , container contenedor2 )
{
  return ( contenedor1.capacidad - contenedor1.llevo ) < (contenedor2.capacidad - contenedor2.llevo );
}

bool comparadorNumero( container contenedor1 , container contenedor2 )
{
  return contenedor1.numero < contenedor2.numero;
}


int cargar( int &paqueteACargar )
{
  posiblesContainers.clear();
  posiblesContainers2.clear();
  menorNumPaquetes = min_element( cargoShip.begin() , cargoShip.end() , comparadorPaquetes )->paquetes.size();
  for( p = 0 ; p < cargoShip.size() ; p++  )
  {
    if( cargoShip[p].paquetes.size() == menorNumPaquetes )
    {
      posiblesContainers.push_back( cargoShip[p] );
    }
  }
  aux = *max_element( posiblesContainers.begin() , posiblesContainers.end() , comparadorCapacidad );
  maxCapacidadActual = aux.capacidad - aux.llevo;
  for( p = 0 ; p < posiblesContainers.size() ; p++  )
  {
    if( ( posiblesContainers[p].capacidad - posiblesContainers[p].llevo ) == maxCapacidadActual )
    {
      posiblesContainers2.push_back( posiblesContainers[p] );
    }
  }
  menorNumero = 9999;
  for( p = 0 ; p < posiblesContainers2.size() ; p++ )
  {
    if( posiblesContainers2[p].numero < menorNumero )
    {
      menorNumero = posiblesContainers2[p].numero;
    }
  }
  if( ( cargoShip[menorNumero-1].capacidad - cargoShip[menorNumero-1].llevo ) >= paqueteACargar  )
  {
    cargoShip[menorNumero-1].paquetes.push_back( paqueteACargar );
    cargoShip[menorNumero-1].llevo += paqueteACargar;
  }
  else
  {
    return -1;
  }
  return 1;
}

void stringeando( int nivel )
{
  for( int k = 0 ; k < cargoShip.size() ; k++ )
  {
    if( nivel < cargoShip[k].paquetes.size() )
    {
      printf("%d", cargoShip[k].paquetes[nivel] );
    }
    else
    {
      printf("%c", ':' );
    }
    if( k != cargoShip.size() - 1)
    {
      printf(" ");
    }
  }
}

int main()
{
  int numContainers , cwi , numPackages , noSePudo , totalBarco, unused;
  bool caso = false;
  while( scanf("%d", &numContainers ) != EOF )
  {
    if( caso )
    {
      printf("\n");
    }
    else
    {
      caso = true;
    }
    cargoShip.clear();
    totalBarco = noSePudo = unused = 0;
    queue< int > paquetes;
    for( int t = 1 ; t <= numContainers ; t++ )
    {
      scanf("%d", &cwi );
      cargoShip.push_back( container( t , cwi ) );
    }
    cin.ignore();
    scanf("%d", &numPackages );
    while( numPackages-- )
    {
      scanf("%d", &cwi );
      paquetes.push( cwi );
    }
    while( !paquetes.empty() )
    {
      if( cargar( paquetes.front() ) == -1 )
      {
        break;
      }
      else
      {
        totalBarco += paquetes.front();
      }
      paquetes.pop();
    }
    while( !paquetes.empty() )
    {
      noSePudo += paquetes.front();
      paquetes.pop();
    }
    p = max_element( cargoShip.begin() , cargoShip.end() , comparadorPaquetes )->paquetes.size() - 1;
    for( ; p >= 0 ; p-- )
    {
        stringeando( p );
        printf("\n");
    }
    for( p = 0 ; p < ( ( cargoShip.size()*2 ) - 1 ) ; p++ )
    {
      printf("=" );
    }
    printf("\n" );
    for( p = 0 ; p < cargoShip.size() ; p++ )
    {
      printf("%d" , cargoShip[p].numero );
      if( p != cargoShip.size() - 1 )
      {
        printf(" ");
      }
    }
    printf("\n\n" );
    for( p = 0 ; p < cargoShip.size() ; p++ )
    {
      unused += ( cargoShip[p].capacidad - cargoShip[p].llevo );
    }
    printf("cargo weight: %d\nunused weight: %d\nunloaded weight: %d\n", totalBarco , unused , noSePudo );
  }
  return 0;
}
