#include <bits/stdc++.h>

using namespace std;

typedef double d;

#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()

const double maximo = 1e10;

struct Estacion
{
  d precioGalon , distanciaInicio;
  Estacion( d precio , d distancia ) : precioGalon( precio ) , distanciaInicio( distancia ) {}
};

d distanciaFinal , capacidadTanque , millasPorGalon , costoOrigen, medio;
vector < Estacion > estaciones;

d nuevoCosto( int &voy , d &gasolina )
{
  return floor( ( capacidadTanque - gasolina ) * estaciones[voy].precioGalon + 0.5 ) + 200.00;
}

d backtracking( int voy , d gasolina , d costo )
{
  if( gasolina < 0.0 )
    return maximo;
  int siguiente = voy + 1;
  d nuevoCost = costo + nuevoCosto( voy , gasolina ) , distanciaEst = estaciones[siguiente].distanciaInicio - estaciones[voy].distanciaInicio , gasolinaNecesaria = distanciaEst / millasPorGalon , nextGasolina , nextCargar;
  if( voy == estaciones.size - 1 )
    return costo;
  nextCargar = capacidadTanque - distanciaEst / millasPorGalon;
  nextGasolina = gasolina - gasolinaNecesaria;
  if( gasolina <= medio )
    return min( backtracking( siguiente , nextGasolina , costo ) , backtracking( siguiente , nextCargar , nuevoCost ) );
  if( nextGasolina > 0.0 )
    return backtracking( siguiente , nextGasolina , costo );
  return backtracking( siguiente , nextCargar , nuevoCost );
}
int main()

{
  int numEstaciones , caso = 0 , i;
  Estacion a( 0.0 , 0.0 );
  while( scanf("%lf", &distanciaFinal ) && distanciaFinal > 0.0 )
  {
    scanf("%lf %lf %lf %d", &capacidadTanque , &millasPorGalon , &costoOrigen , &numEstaciones );
    estaciones.assign( numEstaciones + 1 , a );
    foi( i , numEstaciones )
      scanf("%lf %lf", &estaciones[i].distanciaInicio , &estaciones[i].precioGalon );
    estaciones[estaciones.size - 1].distanciaInicio = distanciaFinal;
    medio = capacidadTanque / 2.0;
    printf("Data Set #%d\nminimum cost = $%.2lf\n", ++caso , costoOrigen + backtracking( 0 , capacidadTanque - estaciones[0].distanciaInicio / millasPorGalon , 0 ) / 100.00 );
  }
  return 0;
}
