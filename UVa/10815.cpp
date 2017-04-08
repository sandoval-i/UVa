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

vector < string > palabras;
unordered_map < string , bool > agregada;

char g;
bool valid;

void agregar( string &palabra )
{
  valid = true;
  if( g >= 65  && g <= 90 ) palabra.pb( (char)(g + 32) );
  else palabra.pb( g );
}

int main()
{
  while( ( g = getchar() ) != EOF )
  {
    string palabra;
    valid = false;
    palabra.clear();
    if( ( g >= 97 && g <= 122 ) || ( g >= 65 && g <= 90 ) )
      agregar( palabra );
    while( g = getchar() , ( g >= 97 && g <= 122 ) || ( g >= 65 && g <= 90 ) )  agregar( palabra );
    if( !agregada[palabra] && valid )
    {
      agregada[palabra] = true;
      palabras.pb( palabra );
    }
  }
  sort( palabras.begin() , palabras.end() );
  for( int i = 0 ; i < palabras.size ; ++i )
    printf("%s\n", palabras[i].c_str() );
  return 0;
}
