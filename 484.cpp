#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long a;
  vector < long long > numeros;
  unordered_map < long long , long long > datos;
  unordered_map < long long , bool > visitados;
  while( scanf("%lld", &a ) != EOF )
  {
    datos[a]++;
    if( !visitados[a] )
    {
      visitados[a] = true;
      numeros.push_back( a );
    }
  }
  for( int i = 0 ; i < numeros.size() ; ++i )
    cout << numeros[i] << " " << datos[numeros[i]] << endl;
  return 0;
}
