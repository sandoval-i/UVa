
#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , n ) for( int i = 0 ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore();

unsigned long long gcd( unsigned long long a , unsigned long long b )
{
  return b == 0 ? a : gcd( b , a % b );
}

struct Fraccion
{
  unsigned long long numerador , denominador;


  Fraccion( void ){}

  void build( unsigned long long num , unsigned long long den )
  {
    this->numerador = num;
    this->denominador = den;
  }

  void simplificar( Fraccion &a )
  {
    unsigned long long gc = gcd( a.numerador , a.denominador );
    a.numerador /= gc;
    a.denominador /= gc;
  }

  Fraccion( unsigned long long num , unsigned long long den ) : numerador( num ) , denominador( den ) { simplificar( *this ); }

  Fraccion operator + ( Fraccion f1 )
  {
    Fraccion nuevo = Fraccion( f1.numerador + this->numerador , f1.denominador + this->denominador );
    simplificar( nuevo );
    return nuevo;
  }

  bool operator == ( Fraccion &f1 )
  {
    return this->numerador == f1.numerador && this->denominador == f1.denominador;
  }

  bool operator < ( Fraccion &f1 )
  {
    double num = this->numerador , den = this->denominador;
    double num2 = f1.numerador , den2 = f1.denominador;
    return ( num / den ) < ( num2 / den2 );
  }

};

Fraccion x , y , buscando , root , ans;
string linea;

Fraccion getFraccion( int indice , Fraccion limL , Fraccion limR , Fraccion voy )
{
  if( indice == linea.length() )
    return voy;
  if( linea[indice] == 'L' ) // Go left
    return getFraccion( indice + 1 , limL , voy , limL + voy );
  return getFraccion( indice + 1 , voy , limR , limR + voy );
}


int main()
{
  int test;
  x.build( 0 , 1 );
  y.build( 1 , 0 );
  root.build( 1 , 1 );
  scanf("%d", &test );
  ignore;
  while( test-- )
  {
    getline( cin , linea );
    ans = getFraccion( 0 , x , y , root );
    printf("%llu/%llu\n", ans.numerador , ans.denominador );
  }
  return 0;
}
