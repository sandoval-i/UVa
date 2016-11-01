#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )

int dx[] = { 0 , -1 , 0 , 1 };
int dy[] = { -1 , 0 , 1 , 0 };
int mov_x[] = { 0 , 1 , 1 };
int mov_y[] = { 1 , 0 , 1 };
bool graph[55][55];
int tiempo_transcurrido[55][55][4];
int M , N;

inline bool in( int x , int y )
{
  return x >= 0 && x <= M && y >= 0 && y <= N;
}

struct Point
{
  int x , y;

  bool operator == ( Point &other )
  {
    return this->x == other.x && this->y == other.y;
  }

  Point( int xx , int yy ) : x(xx) , y(yy) {}

  Point(void)
  {
    x = y = 0;
  }
};

struct State
{
  Point p;
  int direction;
  State( Point a , int dir ) : p(a) , direction(dir){}
};

void insertar( queue < State > &cola , Point p , int direccion , int tiempo_hasta_ahora )
{
  cola.push( State( p , direccion ) );
  tiempo_transcurrido[p.x][p.y][direccion] = tiempo_hasta_ahora + 1;
}

int bfs( Point from , Point to , int orientation )
{
  queue < State > cola;
  cola.push( State( from , orientation ) );
  memset( tiempo_transcurrido , -1 , sizeof tiempo_transcurrido );
  tiempo_transcurrido[from.x][from.y][orientation] = 0;
  while( !cola.empty() )
  {
    Point estoy = cola.front().p;
    int sentido = cola.front().direction;
    int tiempo_hasta_ahora = tiempo_transcurrido[estoy.x][estoy.y][sentido];
    if( estoy == to ) return tiempo_hasta_ahora;
    cola.pop();
    int left_s = sentido - 1;
    int right_s = sentido + 1;
    if( left_s < 0 )  left_s = 3;
    if( right_s > 3 ) right_s = 0;
    if( tiempo_transcurrido[estoy.x][estoy.y][left_s] == -1 )
      insertar( cola , estoy , left_s , tiempo_hasta_ahora );
    if( tiempo_transcurrido[estoy.x][estoy.y][right_s] == -1 )
      insertar( cola , estoy , right_s , tiempo_hasta_ahora );
    for( int i = 1 ; i < 4 ; ++i )
    {
      int x_to = estoy.x + dx[sentido]*i;
      int y_to = estoy.y + dy[sentido]*i;
      if( in( x_to , y_to ) )
      {
        if( graph[x_to][y_to] ) break;
        if( tiempo_transcurrido[x_to][y_to][sentido] == -1 )
          insertar( cola , Point(x_to,y_to) , sentido , tiempo_hasta_ahora );
      }
      else  break;
    }
  }
  return -1;
}


int main()
{
  map < string , int > mapa;
  mapa.insert( pair < string , int >( "west" , 0 ) );
  mapa.insert( pair < string , int >( "north" , 1 ) );
  mapa.insert( pair < string , int >( "east" , 2 ) );
  mapa.insert( pair < string , int >( "south" , 3 ) );
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while( cin >> M >> N , M || N )
  {
    int auxiliar;
    memset( graph , false , sizeof graph );
    foi( i , 0 , M )
      foi( j , 0 , N )
      {
        cin >> auxiliar;
        if( auxiliar == 1 )
        {
          graph[i][j] = true;
          foi( k , 0 , 3 )
            graph[i+mov_x[k]][j+mov_y[k]] = true;
        }
      }
    string initial_direction;
    int x_from , y_from , x_to , y_to;
    cin >>  x_from >> y_from >> x_to >> y_to >> initial_direction;
    cout << bfs( Point( x_from , y_from ) , Point( x_to , y_to ) , mapa[initial_direction] ) << '\n';
  }
  return 0;
}
