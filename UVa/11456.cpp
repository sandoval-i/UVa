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

int main()
{
  int test , numCarros , carros[2000] , lis[2000] , lds[2000] , maximo;
  scanf("%d", &test );
  while( test-- )
  {
    scanf("%d", &numCarros );
    foi( i , 0 , numCarros )  scanf("%d", &carros[i] );
    maximo = 0;
    for( int i = numCarros - 1 ; i >= 0 ; --i )
    {
      lis[i] = 1;
      foi( j , i + 1 , numCarros ) if( carros[i] < carros[j] && lis[j] + 1 > lis[i] )  lis[i] = lis[j] + 1 ;
    }
    for( int i = numCarros - 1 ; i >= 0 ; --i )
    {
      lds[i] = 1;
      foi( j , i + 1 , numCarros ) if( carros[i] > carros[j] && lds[j] + 1 > lds[i] )  lds[i] = lds[j] + 1 ;
    }
    foi( i , 0 , numCarros )
      maximo = max( maximo , lis[i] + lds[i] - 1 );
    printf("%d\n", maximo );
  }
  return 0;
}
