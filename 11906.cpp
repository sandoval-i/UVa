#include <bits/stdc++.h>

using namespace std;

#define MAX_R 100
#define MAX_C 100

int R , C , M , N , W , even , odd , pos[] = { 1 , -1 };
bool water[MAX_R][MAX_C] , visited[MAX_R][MAX_C];

inline bool in( int x , int y )
{
  return x >= 0 && y >= 0 && x < R && y < C;
}

void dfs( int x , int y )
{
  int reach = 0 , x_to , y_to;
  pair < int , int > voy;
  visited[x][y] = true;
  map < pair < int , int > , bool > visit_now;
  pair < map < pair < int , int > , bool > :: iterator , bool > it;
  for( int i = 0 ; i < 2 ; ++i )
  {
    x_to = x + M * pos[i];
    for( int j = 0 ; j < 2 ; ++j )
    {
      y_to = y + N * pos[j];
      if( in( x_to , y_to ) && !water[x_to][y_to] )
      {
        voy.first = x_to;
        voy.second = y_to;
        it = visit_now.insert( pair < pair < int , int > , bool >( voy , true ) );
        if( it.second )
          ++reach;
        if( !visited[x_to][y_to] )
          dfs( x_to , y_to );
      }
    }
  }
  for( int i = 0 ; i < 2 ; ++i )
  {
    x_to = x + N * pos[i];
    for( int j = 0 ; j < 2 ; ++j )
    {
      y_to = y + M * pos[j];
      if( in( x_to , y_to ) && !water[x_to][y_to] )
      {
        voy.first = x_to;
        voy.second = y_to;
        it = visit_now.insert( pair < pair < int , int > , bool >( voy , true ) );
        if( it.second )
          ++reach;
        if( !visited[x_to][y_to] )
          dfs( x_to , y_to );
      }
    }
  }
  reach & 1 ? ++odd : ++even;
}

int main()
{
  int casos , caso = 0 , x , y;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d %d %d %d", &R , &C , &M , &N , &W );
    memset( water , false , sizeof water );
    memset( visited , false , sizeof visited );
    even = odd = 0;
    for( int i = 0 ; i < W ; ++i )
    {
      scanf("%d %d", &x , &y );
      water[x][y] = true;
    }
    dfs( 0 , 0 );
    printf("Case %d: %d %d\n", ++caso , even , odd );
  }
  return 0;
}
