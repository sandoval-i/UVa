#include <bits/stdc++.h>

using namespace std;

#define foi( i , n ) for( ; i < n ; i++ )

struct Carro
{
  int low , high;
  string nombre;
  Carro( string nom , int l , int h )
  {
    this->nombre = nom;
    this->low = l;
    this->high = h;
  }
};

int main()
{
  int test , D , L , H , i , Q , search;
  Carro a( "a" , 1 , 1 );
  string nombre;
  scanf("%d" , &test );
  while( test-- )
  {
    scanf("%d", &D );
    vector < Carro > carros( D , a );
    i = 0;
    foi( i , D )
    {
      cin >> nombre;
      scanf("%d %d", &L , &H );
      carros[i] =  Carro( nombre , L , H ) ;
    }
    scanf("%d", &Q );
    while( Q-- )
    {
      vector < string > posibles;
      scanf("%d" , &search );
      i = 0;
      foi( i , D )
        if( carros[i].low <= search && carros[i].high >= search )
        posibles.push_back( carros[i].nombre );
      if( posibles.size() > 1 || !posibles.size() )
        printf("UNDETERMINED\n");
      else
        printf("%s\n", posibles[0].c_str() );
    }
    if( test )
    printf("\n");
  }
  return 0;
}
