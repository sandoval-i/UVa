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

int N , M;
unsigned long long matriz[1000][1000] , total , area , ans;

void query( int i , int j , int l , int k )
{
  ans = matriz[l][k];
  if( i > 0 )
    ans -= matriz[i-1][k];
  if( j > 0 )
    ans -= matriz[l][j-1];
  if( i > 0 && j > 0 )
    ans += matriz[i-1][j-1];
  printf("%llu\n", ans );
}

int main()
{
  bool first = true;
  while( scanf("%d %d" , &N , &M ) != EOF )
  {
    if( !first )
      puts("");
    else
      first = false;
    total = 0;
    foi( i , 0 , N ) foi( j , 0 , N )
    {
      scanf("%llu", &matriz[i][j] );
      if( i > 0 )
        matriz[i][j] += matriz[i-1][j];
      if( j > 0 )
        matriz[i][j] += matriz[i][j-1];
      if( i > 0 && j > 0 )
        matriz[i][j] -= matriz[i-1][j-1];
    }
    for( int i = 0 ; i < N && i + M - 1 < N ; ++i )
      for( int j = 0 ; j < N && j + M - 1 < N ; ++j )
      {
        query( i , j , i + M - 1 , j + M - 1 );
        total += ans;
      }
    printf("%llu\n", total );
  }
  return 0;
}
