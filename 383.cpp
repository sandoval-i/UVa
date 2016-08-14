#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

int M , N , P , numPasos[50] , estoy;
unordered_map < string , int > ids;
vector < vi > grafo;
bitset < 50 > visited;

int bfs( int source , int destino )
{
  memset( numPasos , 0 , sizeof numPasos );
  visited.reset();
  visited[source] = true;
  queue < int > colabfs;
  colabfs.push( source );
  while( !colabfs.empty() )
  {
    estoy = colabfs.front();
    colabfs.pop();
    if( estoy == destino )  return numPasos[estoy];
    foi( i , 0 , grafo[estoy].size )
      if( !visited[ grafo[estoy][i] ] )
      {
        visited[ grafo[estoy][i] ] = true;
        numPasos[ grafo[estoy][i] ] = numPasos[estoy] + 1;
        colabfs.push( grafo[estoy][i] );
      }
  }
  return -1;
}

int main()
{
  printf("SHIPPING ROUTES OUTPUT\n\n");
  int casos , consecutivo , caso = 0 , tam , pasos;
  string origen , destino , nodo;
  scanf("%d", &casos );
  while( casos-- )
  {
    ids.clear();
    printf("DATA SET  %d\n\n", ++caso );
    scanf("%d %d %d", &M , &N , &P );
    grafo.assign( M , vi() );
    consecutivo = 0;
    foi( i , 0 , M )
    {
      cin >> nodo;
      ids[nodo] = consecutivo++;
    }
    foi( i , 0 , N )
    {
      cin >> origen >> destino;
      grafo[ids[origen]].pb( ids[destino] );
      grafo[ids[destino]].pb( ids[origen] );
    }
    foi( i , 0 , P )
    {
      scanf("%d", &tam );
      cin >> origen >> destino;
      pasos = bfs( ids[origen] , ids[destino] );
      if( pasos == -1 )
        printf("NO SHIPMENT POSSIBLE\n");
      else
        printf("$%d\n", 100 * pasos * tam );
    }
    printf("\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
