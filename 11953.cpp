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

int _x[] = { 1 , -1 , 0 , 0 };
int _y[] = { 0 , 0 , 1 , -1 } , n , sum_x , sum_y;
char board[100][100];

inline bool in( int x , int y )
{
  return x >= 0 && y >= 0 && x < n && y < n;
}

void dfs( int x , int y )
{
  board[x][y] = '.';
  foi( i , 0 , 4 )
  {
    sum_x = x + _x[i];
    sum_y = y + _y[i];
    if( in( sum_x , y + _y[i] ) ) if( board[sum_x][sum_y] == 'x' || board[sum_x][sum_y] == '@' )  dfs( sum_x , sum_y );
  }
}

int main()
{
  int casos , cont , caso = 0;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d", &n );
    foi( i , 0 , n )  foi( j , 0 , n )  scanf(" %c", &board[i][j] );
    cont = 0;
    foi( i , 0 , n )  foi( j , 0 , n )  if( board[i][j] == 'x' )
    {
      ++cont;
      dfs( i , j );
    }
    printf("Case %d: %d\n", ++caso , cont );
  }
  return 0;
}
