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

int rows , columns , pasosTotal , recorrido[10][10] , pasosLoop;
char matriz[10][10];
bool loop , visited[10][10];

bool isIn( int x , int y )
{
  return x >= 0 && y >= 0 && x < rows && y < columns;
}

void dfs( int x , int y , int pasos )
{
  visited[x][y] = true;
  recorrido[x][y] = pasos;
  switch( matriz[x][y] )
  {
    case 'N':
    if( isIn( x - 1 , y ) )
    {
      if( visited[x - 1][y] )
      {
        pasosLoop = pasos - recorrido[x - 1][y] + 1;
        pasosTotal = recorrido[x - 1][y];
        loop = true;
        return;
      }
      else
        dfs( x - 1 , y , pasos + 1 );
    }
    else
    {
      pasosTotal = pasos + 1;
      return;
    }
    break;
    case 'E':
    if( isIn( x , y + 1 ) )
    {
      if( visited[x][y + 1] )
      {
        pasosLoop = pasos - recorrido[x][y + 1] + 1;
        pasosTotal = recorrido[x][y+1];
        loop = true;
        return;
      }
      else
        dfs( x , y + 1 , pasos + 1 );
    }
    else
    {
      pasosTotal = pasos + 1;
      return;
    }
    break;
    case 'S':
    if( isIn( x + 1 , y ) )
    {
      if( visited[x + 1][y] )
      {
        pasosLoop = pasos - recorrido[x + 1][y] + 1;
        pasosTotal = recorrido[x + 1][y];
        loop = true;
        return;
      }
      else
        dfs( x + 1 , y , pasos + 1 );
    }
    else
    {
      pasosTotal = pasos + 1;
      return;
    }
    break;
    case 'W':
    if( isIn( x , y - 1 ) )
    {
      if( visited[x][y - 1] )
      {
        pasosLoop = pasos - recorrido[x][y - 1] + 1;
        pasosTotal = recorrido[x][y - 1];
        loop = true;
        return;
      }
      else
        dfs( x , y - 1 , pasos + 1 );
    }
    else
    {
      pasosTotal = pasos + 1;
      return;
    }
    break;
  }
}

int main()
{
  int columnBegin;
  while( scanf("%d %d %d" , &rows , &columns , &columnBegin) , rows || columns || columnBegin )
  {
    loop = false;
    foi( i , 0 , rows ) foi( j , 0 , columns ) scanf(" %c", &matriz[i][j] ) , visited[i][j] = false;
    dfs( 0 , columnBegin - 1 , 0 );
    if( loop )  printf("%d step(s) before a loop of %d step(s)\n", pasosTotal , pasosLoop );
    else printf( "%d step(s) to exit\n" , pasosTotal );
  }
  return 0;
}
