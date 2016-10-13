#include <bits/stdc++.h>

using namespace std;

vector < int > in_degree;
vector < vector < int > > soluciones;
bitset < 30 > is_node;
vector < vector < int > > graph;
int counter;

void backtrack( int i , vector < int > grado_entrada , bitset < 30 > usado , vector < int > posible_sol )
{
  posible_sol.push_back(i);
  if( ((int)posible_sol.size()) == counter )
  {
    soluciones.push_back( posible_sol );
    return;
  }
  usado[i] = true;
  for( int j = 0 ; j < graph[i].size() ; ++j )
    --grado_entrada[graph[i][j]];
  for( int j = 0 ; j < 30 ; ++j )
  {
    if( grado_entrada[j] == 0 && is_node[j] && !usado[j] )
      backtrack( j , grado_entrada , usado , posible_sol );
  }
}

int main()
{
  bitset < 30 > used;
  used.reset();
  int casos;
  string linea , tok;
  cin >> casos;
  cin.ignore( 10000000 , '\n' );
  while( casos-- )
  {
    counter = 0;
    is_node.reset();
    soluciones.clear();
    in_degree.assign( 30 , 0 );
    cin.ignore( 1000000 , '\n' );
    graph.assign( 28 , vector < int >() );
    getline( cin , linea );
    stringstream a(linea);
    while( a >> tok )
    {
      is_node[tok[0]-'A'] = true;
      ++counter;
    }
    getline( cin , linea );
    stringstream b(linea);
    while( b >> tok )
    {
      graph[tok[0] - 'A'].push_back( tok[2] - 'A' );
      ++in_degree[tok[2] - 'A'];
    }
    for( int i = 0 ; i < 30 ; ++i )
      if( in_degree[i] == 0 && is_node[i] ) backtrack( i , in_degree , used , vector < int >() );
    if( soluciones.size() == 0 ) puts("NO");
    for( int i = 0 ; i < soluciones.size() ; ++i )
    {
      for( int j = 0 ; j < soluciones[i].size() ; ++j )
      {
        if( j != 0 )
          cout << " ";
        cout << (char)(soluciones[i][j] + 'A');
      }
      cout << '\n';
    }
    if( casos ) puts("");
  }
  return 0;
}
