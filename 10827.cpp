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

int N;

int maxSumTorus( vector < vi > &torus )
{
  int maximo = 1 << 31 , partialSum;
  foi( i , 0 , N )  foi( j , 0 , N )  torus[i].pb( torus[i][j] );
  foi( i , 0 , N )  torus.pb( torus[i] );
  foi( i , 0 , N << 1 ) foi( j , 0 , N << 1 )
  {
    if( i > 0 ) torus[i][j] += torus[i-1][j];
    if( j > 0 ) torus[i][j] += torus[i][j-1];
    if( i > 0 && j > 0 )  torus[i][j] -= torus[i-1][j-1];
  }
  foi( i , 0 , N ) foi( j , 0 , N ) foi( k , i , i + N ) foi( l , j , j + N )
  {
    partialSum = torus[k][l];
    if( i > 0 ) partialSum -= torus[i-1][l];
    if( j > 0 ) partialSum -= torus[k][j-1];
    if( i > 0 && j > 0 ) partialSum += torus[i-1][j-1];
    maximo = max( maximo , partialSum );
  }
  return maximo;
}

int main()
{
  int casos;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d", &N );
    vector < vi > torus( N , vi( N , 0 ) );
    foi( i , 0 , N ) foi( j , 0 , N ) scanf("%d", &torus[i][j] );
    printf("%d", maxSumTorus( torus ) );
    puts("");
  }
  return 0;
}
