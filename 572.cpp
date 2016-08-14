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
#define impar( i ) i & 1
#define par( i ) !( i & 1 )

char matriz[100][100];
bool visited[100][100];
int moveX[8] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 };
int moveY[8] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 };

int m , n , ans;

bool isIn( int x , int y )
{
  return x >= 0 && y >=0 && x < m && y < n;
}

void dfs( int i , int j )
{
  visited[i][j] = true;
  foi( k , 0 , 8 )
    if( matriz[ i + moveX[k] ][ j + moveY[k] ] == '@' && isIn( i + moveX[k] , j + moveY[k] ) && !visited[i + moveX[k]][j + moveY[k]] ) dfs( i + moveX[k] , j + moveY[k] );
}

int main()
{
  while( scanf("%d", &m ) , m )
  {
    ans = 0;
    scanf("%d", &n );
    foi( i , 0 , m )  foi( j , 0 , n )  scanf(" %c", &matriz[i][j] ) , visited[i][j] = false;
    foi( i , 0 , m )  foi( j , 0 , n )  if( matriz[i][j] == '@' && !visited[i][j] ) ++ans , dfs( i , j );
    printf( "%d\n" , ans );
  }
  return 0;
}
