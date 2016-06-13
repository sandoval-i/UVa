#include <bits/stdc++.h>

using namespace std;

int main()
{
  string cadena , resultado;
  int tam , begin , masRepetido;
  while( cin >> tam >> cadena )
  {
    unordered_map< string , int > numApariciones;
    begin = masRepetido = 0;
    while( begin + tam <= cadena.length() )
      numApariciones[ cadena.substr( begin++ , tam ) ]++;
    for( unordered_map < string , int >::iterator it = numApariciones.begin() ; it != numApariciones.end() ; it++ )
      if( it->second > masRepetido )
      {
        masRepetido = it->second;
        resultado = it->first;
      }
    printf("%s\n", resultado.c_str() );
  }
  return 0;
}
