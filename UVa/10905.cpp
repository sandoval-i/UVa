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

bool mayor( string num1 , string num2 )
{
  for( int i = 0 ; i < num1.size ; ++i )
    if( num1[i] > num2[i] ) return true;
    else if( num2[i] > num1[i] ) return false;
  return true;
}

bool comp( string num1 , string num2 )
{
  int i = 0 , j = 0;
  if( num1.size > num2.size )
  {
    while( i < num1.size )
    {
      if( num1[i] > num2[j] ) return true;
      else if( num2[j] > num1[i] )  return false;
      ++i , ++j;
      j %= num2.size;
    }
  }
  else
  {
    while( j < num2.size )
    {
      if( num1[i] > num2[j] ) return true;
      else if( num2[j] > num1[i] )  return false;
      ++i , ++j;
      i %= num1.size;
    }
  }
  return mayor( num1 + num2 , num2 + num1 );
}

int main()
{
  int N;
  string numeros[50];
  while( scanf("%d", &N ) , N )
  {
    foi( i , 0 , N ) cin >> numeros[i];
    sort( numeros , numeros + N , comp );
    foi( i , 0 , N )  printf("%s", numeros[i].c_str() );
    puts("");
  }
  return 0;
}
