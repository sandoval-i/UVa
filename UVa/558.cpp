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

const int INF = 99999;

struct Edge
{
  int inicio , fin , costo;
};

vector < Edge > lados;
vector < int > costos;
int n , m;

bool bellmanFord( int source )
{
  costos.assign( n , INF );
  costos[source] = 0;
  foi( k , n - 1 )
    foi( i , m )
      if( costos[lados[i].inicio] + lados[i].costo < costos[lados[i].fin] )
        costos[lados[i].fin] = costos[lados[i].inicio] + lados[i].costo;
  foi( i , lados.size )
    if( costos[lados[i].inicio] + lados[i].costo < costos[lados[i].fin] )
      return true;
  return false;
}

int main()
{
  int test;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d %d", &n , &m );
    lados.assign( m , Edge() );
    foi( i , m )
      scanf("%d %d %d", &lados[i].inicio , &lados[i].fin , &lados[i].costo );
    if( bellmanFord( 0 ) )
      printf("possible\n");
    else
      printf("not possible\n");
  }
  return 0;
}
