#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; ++i )
#define size size()
#define pb push_back
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

struct SegmentTree
{

  vi tree , lazyPropagation;

  int armar( int low , int high , int pos , vi &array )
  {
    if( low == high )
      return tree[pos] = array[low];
    if( low > high )  return 0;
    int mid = ( ( low + high ) >> 1 );
    return tree[pos] = armar( low , mid , ( pos << 1 ) + 1 , array ) + armar( mid + 1 , high , ( pos << 1 ) + 2 , array );
  }

  SegmentTree( vi &array )
  {
    tree.assign( 4 * array.size , 0 );
    armar( 0 , array.size - 1 , 0 , array );
  }

  void update( int &index , int low , int high , int pos , int &cantidad )
  {
    if( index < low || index > high )
      return;
    if( low == high )
    {
      tree[pos] = cantidad;
      return;
    }
    int mid = ( ( low + high ) >> 1 );
    update( index , low , mid , ( pos << 1 ) + 1 , cantidad );
    update( index , mid + 1 , high , ( pos << 1 ) + 2 , cantidad );
    tree[pos] = tree[ ( pos << 1 ) + 1 ] + tree[ ( pos << 1 ) + 2 ];
  }

  int sumRange( int qlow , int qhigh , int low , int high , int pos )
  {
    if( qlow > high || qhigh < low ) return 0; // No overlap
    if( qlow <= low && qhigh >= high )  return tree[pos]; // Complete overlap
    int mid = ( ( low + high ) >> 1 ); // Partial overlap
    return sumRange( qlow , qhigh , low , mid , ( pos << 1 ) + 1 ) + sumRange( qlow , qhigh , mid + 1 , high , ( pos << 1 ) + 2 );
  }

  int sumQuery( int qlow , int qhigh , vi &array )
  {
    return this -> sumRange( qlow , qhigh , 0 , array.size - 1 , 0 );
  }

  void updateQuery( int index , vi &array , int cantidad )
  {
    this -> update( index , 0 , array.size - 1 , 0 , cantidad );
  }

};

int main()
{
  bool first = true;
  int N , index , cantidad , caso = 0;
  string instruccion;
  char op;
  while( scanf("%d", &N ) , N )
  {
    if( !first ) puts("");
    else  first = false;
    printf("Case %d:\n", ++caso );
    vi arreglo( N , 0 );
    foi( i , 0 , N )  scanf("%d", &arreglo[i] );
    SegmentTree arbol( arreglo );
    cin.ignore( 1 , '\n' );
    while( getline( cin , instruccion ) , instruccion != "END" )
    {
      sscanf( instruccion.c_str() , "%c %d %d" , &op , &index , &cantidad );
      if( op == 'M' )
        printf("%d\n", arbol.sumQuery( index - 1 , cantidad - 1 , arreglo ) );
      else
        arbol.updateQuery( index - 1 , arreglo , cantidad );
    }
  }
  return 0;
}
