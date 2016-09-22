#include <bits/stdc++.h>

using namespace std;

inline bool is_word( char a )
{
  return ( a >= 65 && a <= 90 ) || ( a >= 97 && a <= 122 );
}

int main()
{
  string linea ;
  int ans;
  while( getline( cin , linea ) )
  {
    ans = 0;
    ans += is_word(linea[0]);
    for( int i = 1 ; i < linea.size() ; ++i ) ans += is_word( linea[i] ) && !is_word( linea[i-1] );
    printf("%d\n", ans );
  }
  return 0;
}
