#include <bits/stdc++.h>

using namespace std;

// false = left
// right = true

int main()
{
  long n , t , m , num , tiempo;
  int casos;
  char side[10];
  bool ferry;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%ld %ld %ld", &n , &t , &m );
    ferry = tiempo = false;
    queue < long > queue_side[2] , output[2];
    bitset < 10000 > salida;
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%ld %s", &num , side );
      if( strcmp( side , "left" ) == 0 )
      {
        queue_side[0].push(num);
        salida[i] = false;
      }
      else
      {
        queue_side[1].push(num);
        salida[i] = true;
      }
    }
    while( !queue_side[0].empty() || !queue_side[1].empty() )
    {
      if( queue_side[ferry].empty() )
      {
        if( tiempo >= queue_side[!ferry].front() )
          tiempo += t;
        else
          tiempo = queue_side[!ferry].front() + t;
        ferry = !ferry;
        continue;
      }
      if( queue_side[ferry].front() <= tiempo )
      {
        int cont = 0;
        while( !queue_side[ferry].empty() && cont < n && queue_side[ferry].front() <= tiempo )
        {
          ++cont;
          output[ferry].push( tiempo + t );
          queue_side[ferry].pop();
        }
        tiempo += t;
        ferry = !ferry;
      }
      else if( !queue_side[!ferry].empty() && queue_side[!ferry].front() < queue_side[ferry].front() )
      {
        if( tiempo >= queue_side[!ferry].front() )
          tiempo += t;
        else
          tiempo = queue_side[!ferry].front() + t;
        ferry = !ferry;
      }
      else
        tiempo = queue_side[ferry].front();
    }
    for( int i = 0 ; i < m ; ++i )
    {
      if( salida[i] )
      {
        printf("%ld\n", output[1].front() );
        output[1].pop();
      }
      else
      {
        printf("%ld\n", output[0].front() );
        output[0].pop();
      }
    }
    if( casos )
      puts("");
  }
  return 0;
}
