#include <bits/stdc++.h>

using namespace std;

struct Proposal
{
  string nombre;
  float precio;
  float numReq;
  float compliance;
  void setCompliance( float &num )
  {
    this->compliance = this->numReq / num ;
  }
};

int main()
{
  int p;
  float n;
  string trash;
  Proposal abc;
  int cont = 0;
  string seleccionado;
  float mayor;
  float menor;
  bool first = true;
  while( true )
  {
    scanf("%f %d", &n , &p );
    cin.ignore();
    if( n == 0 && p == 0 )
      break;
    else
      if( !first )
      printf("\n");
      else
      first = false;
    mayor = -99999;
    vector < Proposal > pro( p , abc );
    vector < Proposal > posibles;
    for( int i = 0 ; i < n ; i++ )
      getline( cin , trash );
    for( int i = 0 ; i < p ; i++ )
    {
      getline( cin , pro[i].nombre );
      scanf("%f %f" , &pro[i].precio , &pro[i].numReq );
      if( pro[i].numReq > 0 )
        cin.ignore();
      for( int t = 0 ; t < pro[i].numReq ; t++ )
        getline( cin , trash );
    }
    for( int i = 0 ; i < p ; i++ )
    {
      pro[i].setCompliance(n);
      if( mayor < pro[i].compliance  )
        mayor = pro[i].compliance;
    }
    for( int i = 0 ; i < p ; i++ )
      if( pro[i].compliance == mayor )
        posibles.push_back( pro[i] );
    if( posibles.size() == 1 )
      seleccionado = posibles[0].nombre;
    else
    {
      menor = posibles[0].precio;
      seleccionado = posibles[0].nombre;
      for( int i = 0 ; i < posibles.size() ; i++ )
        if( posibles[i].precio < menor )
        {
          menor = posibles[i].precio;
          seleccionado = posibles[i].nombre;
        }
    }
    printf("RFP #%d\n%s\n", ++cont , seleccionado.c_str() );
  }
  return 0;
}
