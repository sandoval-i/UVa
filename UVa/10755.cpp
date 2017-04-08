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

int A , B , C;
vector < ll > llevo;
vector < vector < ll > > llevo3D;

ll kadane( vector < ll > &array )
{
  ll max_so_far , max_current;
  max_so_far = max_current = array[0];
  foi( i , 1 , array.size )
  {
    max_current = max( array[i] , array[i] + max_current );
    if( max_current > max_so_far )
      max_so_far = max_current;
  }
  return max_so_far;
}

ll max2DSum( vector < vector < ll > > &array )
{
  ll maximo = ( 1LL << 63 );
  foi( i , 0 , array[0].size )
  {
    llevo.assign( array.size , 0 );
    foi( j , i , array[0].size )
    {
      foi( k , 0 , array.size ) llevo[k] += array[k][j];
      maximo = max( maximo , kadane( llevo ) );
    }
  }
  return maximo;
}

ll maxGarbage( vector < vector < vector < ll > > > &garbage )
{
  ll maximo = ( 1LL << 63 );
  foi( j , 0 , B )
  {
    llevo3D.assign( A , vector < ll > ( C , 0 ) );
    foi( i , j , B )
    {
       foi( a , 0 , llevo3D.size )
        foi( b , 0 , llevo3D[a].size )
          llevo3D[a][b] += garbage[a][i][b];
      maximo = max( maximo , max2DSum( llevo3D ) );
    }
  }
  return maximo;
}

int main()
{
  int casos;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d %d", &A , &B , &C );
    vector < vector < vector < ll > > > garbage( A , vector < vector < ll > >( B , vector < ll >( C , 0 ) ) );
    foi( i , 0 , A )  foi( j , 0 , B )  foi( k , 0 , C )  scanf("%lld", &garbage[i][j][k] );
    printf("%lld\n", maxGarbage( garbage ) );
    if( casos )
      puts("");
  }
  return 0;
}
