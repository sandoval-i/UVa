#include <bits/stdc++.h>

using namespace std;

struct Vertex
{
  string dato;
  int id;
  vector < int > vecinos;
  Vertex( string dato , int id )
  {
    this->dato = dato;
    this->id = id;
  }
  void addFriend( int t )
  {
    this->vecinos.push_back( t );
  }
};

bool sonSemejantes( string dato1 , string dato2 )
{
  int numChanges = 0;
  if( dato1.size() != dato2.size() )
    return false;
  for( int t = 0 ; t < dato1.size() ; t++ )
    if( dato1[t] != dato2[t] )
      if( ++numChanges > 1 )
        return false;
  if( numChanges != 1 )
    return false;
  return true;
}

int numCambios( string palabraInicio , string palabraDestino , vector < Vertex > &grafo )
{
  int size = grafo.size();
  int id , idVecino;
  pair < int , int > actual;
  for( int t = 0 ; t < size ; t++  )
    if( grafo[t].dato == palabraInicio )
    {
      id = t;
      break;
    }
  queue< pair < int , int > > colaBFS;
  vector< bool > visitados( size , false );
  visitados[id] = true;
  colaBFS.push( make_pair( id , 0 ) );
  while( !colaBFS.empty() )
  {
    actual = colaBFS.front();
    colaBFS.pop();
    if( grafo[actual.first].dato == palabraDestino )
    {
      return actual.second;
      break;
    }
    for( int t = 0 ; t < grafo[actual.first].vecinos.size() ; t++ )
    {
      idVecino = grafo[actual.first].vecinos[t];
      if( !visitados[idVecino] )
      {
        visitados[idVecino] = true;
        colaBFS.push( make_pair( idVecino , actual.second + 1 ) );
      }
    }
  }
  return -1;
}

int main()
{
  int test , size , cont , contTR;
  string prueba , palabra0 , palabra1 , palabra2 , tok;
  scanf("%d", &test );
  cin.ignore();
  while( test-- )
  {
   vector < Vertex > palabras;
   cont = 0;
   while( getline( cin , prueba ) && prueba != "*" )
     palabras.push_back( Vertex( prueba , cont++ ) );
   size = palabras.size();
   for( int i = 0 ; i < size ; i++ )
    for( int j = i + 1 ; j < size ; j++ )
    {
      if( sonSemejantes( palabras[i].dato , palabras[j].dato ) )
      {
        palabras[i].addFriend(j);
        palabras[j].addFriend(i);
      }
    }
    while( getline( cin , tok ) && tok != "" )
    {
      contTR = 0;
      stringstream token( tok );
      while( token >> palabra0 )
      {
        if( contTR == 0 )
          palabra1 = palabra0;
        else
          palabra2 = palabra0;
        contTR++;
      }
      printf("%s %s %d\n", palabra1.c_str() , palabra2.c_str() , numCambios( palabra1, palabra2 , palabras ) );
    }
    if( test != 0 )
      printf("\n" );
  }
  return 0;
}
