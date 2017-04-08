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
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

int main()
{
  char aux;
  string parentesis;
  int n;
  bool correct;
  scanf("%d", &n );
  ignore;
  while( n-- )
  {
    correct = true;
    getline( cin , parentesis );
    stack < char > pila;
    foi( i , 0 , parentesis.size )
    {
      if( parentesis[i] == '(' || parentesis[i] == '[' )
        pila.push( parentesis[i] );
      else
      {
        if( pila.empty() )
        {
          correct = false;
          break;
        }
        aux = pila.top();
        if( parentesis[i] == ')' )
        {
          if( aux != '(' )
          {
            correct = false;
            break;
          }
        }
        else if( parentesis[i] == ']' )
        {
          if( aux != '[' )
          {
            correct = false;
            break;
          }
        }
        pila.pop();
      }
      if( !correct )
        break;
    }
    if( !pila.empty() )
      correct = false;
    printf("%s\n", correct ? "Yes" : "No" );
  }
  return 0;
}
