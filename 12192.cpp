#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
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

int N , M , Q , L , U , llevo , maximo , posLower;
vi::iterator ans;
vector < vi > matriz;

int solve( void )
{
  maximo = 0;
  foi( i , 0 , N )
  {
    ans = lower_bound( matriz[i].begin() , matriz[i].end() , L );
    if( ans == matriz[i].end() )
      continue;
    if( *ans > U )
      continue;
    maximo = max( maximo , 1 );
    posLower = ans - matriz[i].begin();
    llevo = 1;
    foi( j , i + 1 , N )
    {
      if( posLower + llevo >= M )
        break;
      if( matriz[j][posLower + llevo] <= U )
        maximo = max( maximo , llevo + 1 );
      else
        break;
      llevo++;
    }
  }
  return maximo;
}

int main()
{
    while( scanf( "%d %d " , &N , &M ) , N || M )
    {
        matriz.assign( N , vi(  M , 0 ) );
        foi( i , 0 , N )
            foi( j , 0 , M )
                scanf( "%d" , &matriz[i][j] );
        scanf("%d" , &Q );
        while( Q-- )
        {
            scanf("%d %d" , &L , &U );
            printf( "%d\n" , solve() );
        }
        printf("-\n");
    }
    return 0;
}
