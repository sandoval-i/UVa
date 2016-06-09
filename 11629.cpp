#include <bits/stdc++.h>

using namespace std;

map < string , double > guess;
string tokenizado , c;
double total , supuestoTotal;
string operador;

bool evaluar( string &expresion )
{
  total = 0;
  vector < string > tokens;
  stringstream token( expresion );
  while( token >> tokenizado )
  if( tokenizado != "+" )
    tokens.push_back( tokenizado );
  for( int i = 0 ; i < tokens.size() - 2 ; i++ )
  {
    total += guess[tokens[i]];
    total = round( total * 10 );
    total = trunc( total );
    total /= 10;
  }
  operador = tokens[tokens.size() - 2];
  supuestoTotal = stod( tokens[tokens.size() - 1].c_str() );
  if( operador == "<" )
    return total < supuestoTotal;
  if( operador == ">" )
    return total > supuestoTotal;
  if( operador == "<=" )
    return total <= supuestoTotal;
  if( operador == ">=" )
    return total >= supuestoTotal;
  if( operador == "=" )
    return total == supuestoTotal;
}

int main()
{
  int p , g , contador = 0;
  string actual;
  double valor;
  scanf("%d %d", &p , &g );
  while( p-- )
  {
    cin >> actual;
    scanf("%lf", &valor );
    guess[actual] = valor;
  }
  cin.ignore();
  while( g-- )
  {
    getline( cin , actual );
    if( evaluar( actual ) )
      printf("Guess #%d was correct.\n", ++contador );
    else
      printf("Guess #%d was incorrect.\n", ++contador );
  }
  return 0;
}
