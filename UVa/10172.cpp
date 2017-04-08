#include <bits/stdc++.h>

using namespace std;

bool keep( vector < queue < int > > &a )
{
  for( int i = 0 ; i < a.size() ; ++i )
    if( !a[i].empty() ) return true;
  return false;
}

int main()
{
  int casos , N , S , Q , tam , num ,estacion , ans , vacio;
  bool flag;
  scanf("%d", &casos );
  while( casos-- )
  {
    scanf("%d %d %d", &N , &S , &Q );
    vector < queue < int > > stations( N , queue < int >() );
    for( int i = 0 ; i < N ; ++i )
    {
      scanf("%d", &tam );
      while( tam-- )
      {
        scanf("%d", &num );
        stations[i].push( --num );
      }
    }
    stack < int > cargo_carrier;
    estacion = vacio = ans = 0;
    while(keep(stations) || !cargo_carrier.empty())
    {
      while( !cargo_carrier.empty() ) // unload cargoes
      {
        if( cargo_carrier.top() == estacion )
        {
          cargo_carrier.pop();
          ++ans;
        }
        else if( stations[estacion].size() < Q )
        {
          stations[estacion].push(cargo_carrier.top());
          cargo_carrier.pop();
          ++ans;
        }
        else
          break;
      }
      while( !stations[estacion].empty() ) // load cargoes
      {
        if( cargo_carrier.size() == S )
          break;
        cargo_carrier.push(stations[estacion].front());
        stations[estacion].pop();
        ++ans;
      }
      estacion = ( estacion + 1 ) % N;
      ans += 2;
    }
    printf("%d\n", ans - 2 );
  }
  return 0;
}
