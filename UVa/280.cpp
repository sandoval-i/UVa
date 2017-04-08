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
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

int nodes , origen , llegada , numIntegers ;
vi grafo[101];
vi queries;
vi solution;
bitset < 101 > visitados;

void dfs( int node )
{
  foi( i , 0 , grafo[node].size )
    if( !visitados[grafo[node][i]] )
      { visitados[grafo[node][i]] = true ; dfs( grafo[node][i] ); }
}

int main()
{
  while( scanf("%d", &nodes ) , nodes )
  {
    foi( i , 1 , 102 )  grafo[i].clear();
    while( scanf("%d", &origen ) , origen ) while( scanf("%d" , &llegada ) , llegada )  grafo[origen].pb( llegada );
    scanf("%d", &numIntegers );
    while( numIntegers-- )
    {
      scanf("%d", &origen );
      dfs( origen );
      for( int i = 1 ; i <= nodes ; i++ )
        if( !visitados[i] ) solution.pb( i );
      printf("%lu", solution.size );
      foi( i , 0 , solution.size )
        printf(" %d", solution[i] );
      printf("\n");
      solution.clear();
      visitados.reset();
    }
  }
  return 0;
}
