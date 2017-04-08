#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

int posX[4] = { 0 , 1 , 0 , -1 };
int posY[4] = { 1 , 0 , -1 , 0};

bool isIn( int &x , int &y , int &filas , int &columnas )
{
  if( x >= 0 && y >= 0)
    if( x < filas && y < columnas )
      return true;
  return false;
}

int BFSLaberinto( vector < vector < bool > > &laberinto , int &inicioX , int &inicioY , int &finX , int &finY )
{
  int filas = laberinto.size() , columnas = laberinto[0].size();
  vector < vector < bool > > visitados( filas , vector < bool >( columnas , false ) );
  queue < pair < ii , int > > colaBFS;
  pair < ii , int > actual;
  int x , y , distancia , viendoX , viendoY;
  visitados[inicioX][inicioY] = true;
  colaBFS.push( pair < ii , int >(  ii( inicioX , inicioY ) , 0) );
  while( !colaBFS.empty() )
  {
    actual = colaBFS.front();
    colaBFS.pop();
    x = actual.first.first;
    y = actual.first.second;
    distancia = actual.second;
    if( x == finX && y == finY )
      return distancia;
    for( int i = 0 ; i < 4 ; i++ )
    {
      viendoX = x + posX[i];
      viendoY = y + posY[i];
        if( isIn( viendoX , viendoY , filas , columnas )  )
          if( !visitados[viendoX][viendoY] && !laberinto[viendoX][viendoY] )
          {
            visitados[viendoX][viendoY] = true;
            colaBFS.push( pair < ii , int >(  ii( viendoX , viendoY ) , distancia + 1) );
          }
    }
  }
  return -1;
}

int main()
{
  int R , C , numBombas , row , numBombasRow , column , inicioX , inicioY , finX , finY;
  while( scanf("%d %d", &R , &C ) && ( R != 0 || C != 0 ) )
  {
    vector < vector < bool > > laberinto( R , vector < bool > ( C , false ) );
    scanf("%d", &numBombas );
    while( numBombas-- )
    {
      scanf("%d %d", &row , &numBombasRow );
      while( numBombasRow-- )
      {
        scanf( "%d", &column );
        laberinto[row][column] = true;
      }
    }
    scanf("%d %d %d %d" , &inicioX , &inicioY , &finX , &finY );
    printf("%d\n",BFSLaberinto( laberinto , inicioX , inicioY , finX , finY ));
  }
  return 0;
}
