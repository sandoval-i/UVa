#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n , operacion , dato , actualP , actualC , actualCP;
  bool esPila , esCola , esColaPrioridad;
  while( scanf("%d", &n ) != EOF )
  {
    stack < int > pila;
    queue < int > cola;
    priority_queue < int > colaPrioridad;
    esPila = esCola = esColaPrioridad = true;
    while( n-- )
    {
      scanf("%d %d", &operacion , &dato );
      if( operacion == 1 )
      {
        pila.push( dato );
        cola.push( dato );
        colaPrioridad.push( dato );
      }
      else if( operacion == 2 )
      {
        if( !pila.empty() )
        {
          actualP = pila.top();
          pila.pop();
          if( actualP != dato )
            esPila = false;
        }
        else
          esPila = false;
        if( !cola.empty() )
        {
          actualC = cola.front();
          cola.pop();
          if( actualC != dato )
            esCola = false;
        }
        else
          esCola = false;
        if( !colaPrioridad.empty() )
        {
          actualCP = colaPrioridad.top();
          colaPrioridad.pop();
          if( actualCP != dato )
            esColaPrioridad = false;
        }
        else
          esColaPrioridad = false;
      }
    }
    if( ( esPila && esCola ) || ( esPila && esColaPrioridad ) || ( esCola && esColaPrioridad ) || ( esPila && esCola && esColaPrioridad ) )
    {
      printf("not sure\n" );
      continue;
    }
    if( !esPila && !esCola && !esColaPrioridad )
    {
      printf("impossible\n" );
      continue;
    }
    if( esPila )
    {
      printf("stack\n");
      continue;
    }
    if( esCola )
    {
      printf("queue\n" );
      continue;
    }
    if( esColaPrioridad )
    {
      printf("priority queue\n");
    }
  }
}
