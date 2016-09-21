#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

int N , consecutivo , M , caso , id_origen , id_destino , grado_entrada[MAX_N] , actual , to;
string nombre , origen , destino;
vector < vector < int > > grafo;

int main()
{
  caso = 0;
  while( scanf("%d", &N ) != EOF )
  {
    memset( grado_entrada , 0 , sizeof grado_entrada );
    consecutivo = 0;
    map < string , int > ids;
    map < int , string > nombres;
    priority_queue < int , vector < int > , greater < int > > kahn;
    grafo.assign( N , vector < int >() );
    for( int i = 0 ; i < N ; ++i )
    {
      cin >> nombre;
      ids[nombre] = consecutivo;
      nombres[consecutivo] = nombre;
      ++consecutivo;
    }
    scanf("%d", &M );
    while( M-- )
    {
      cin >> origen >> destino;
      id_origen = ids[origen];
      id_destino = ids[destino];
      grafo[id_origen].push_back( id_destino );
      ++grado_entrada[id_destino];
    }
    printf("Case #%d: Dilbert should drink beverages in this order:" , ++caso );
    for( int i = 0 ; i < N ; ++i ) if( grado_entrada[i] == 0 ) kahn.push( i );
    while( !kahn.empty() )
    {
      actual = kahn.top();
      kahn.pop();
      printf(" %s", nombres[actual].c_str() );
      for( int i = 0 ; i < grafo[actual].size() ; ++i )
      {
        to = grafo[actual][i];
        --grado_entrada[to];
        if( !grado_entrada[to] ) kahn.push(to);
      }
    }
    printf(".\n\n");
  }
  return 0;
}
