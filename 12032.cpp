#include <vector>
#include <cstdio>
using namespace std;

vector < int > escalones;
int difActual , maxDif , test , rungs , need , comienzo , caso;

bool can( int k )
{
  for( int i = comienzo ; i < escalones.size() - 1 ; i++ )
  {
    need = escalones[i+1] - escalones[i];
    if( need > k )
    {
      return false;
    }
    if( need == k )
    {
      k--;
    }
    comienzo = i;
  }
  return true;
}

int main()
{
  caso = 0;
  scanf("%d", &test );
  while( test-- )
  {
    maxDif = comienzo = 0;
    scanf("%d", &rungs );
    escalones.assign( rungs + 1 , 0 );
    for( int i = 1 ; i < escalones.size() ; i++ )
    {
      scanf("%d", &escalones[i] ) ;
      maxDif = max( maxDif , escalones[i] - escalones[i-1] );
    }
    while( !can( maxDif ) )
    {
      maxDif++;
    }
    printf("Case %d: %d\n", ++caso ,  maxDif );
  }
  return 0;
}
