#include <bits/stdc++.h>

using namespace std;

#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
int capacidad , ciudadFinal , numeroTickets;

struct Ticket
{
  int inicio , fin , pasajeros;
  Ticket( void ) : inicio( 0 ) , fin( 0 ) , pasajeros( 0 ) {}
};

bool comp( Ticket t1 , Ticket t2 )
{
  if( t1.inicio != t2.inicio )
    return t1.inicio < t2.inicio;
  return t1.fin < t2.fin;
}

vector < Ticket > tickets;

int costo( Ticket &t )
{
  return ( t.fin - t.inicio ) * t.pasajeros;
}

int backtrack( int pasajeros , int total , int indice , vector < Ticket > Bus )
{
  if( pasajeros > capacidad )
    return 0;
  if( indice == tickets.size )
    return total;
  int estacion = tickets[indice].inicio , i = 0;
  while( i < Bus.size )
    if( Bus[i].fin <= estacion )
    {
      pasajeros -= Bus[i].pasajeros;
      Bus.erase( Bus.begin() + i );
    }
    else
      i++;
  int max1 , max2;
  max1 = max2 = 0;
  max1 = backtrack( pasajeros , total , indice + 1 , Bus );
  Bus.push_back( tickets[indice] );
  max2 = backtrack( pasajeros + tickets[indice].pasajeros , total + costo( tickets[indice] ) , indice + 1 , Bus );
  return max( max1 , max2 );
}

int main()
{
  while( scanf("%d%d%d", &capacidad , &ciudadFinal , &numeroTickets ) )
  {
    vector < Ticket > Bus;
    if( capacidad == 0 && ciudadFinal == 0 && numeroTickets == 0 )
      break;
    tickets.assign( numeroTickets , Ticket() );
    foi( i , numeroTickets )
      scanf( "%d%d%d", &tickets[i].inicio , &tickets[i].fin , &tickets[i].pasajeros );
    sort( tickets.begin() , tickets.end() , comp );
    printf("%d\n", backtrack( 0 , 0 , 0 , Bus ) );
  }
  return 0;
}
