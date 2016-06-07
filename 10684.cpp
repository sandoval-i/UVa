#include <bits/stdc++.h>

using namespace std;

int kadane( vector < int > &array )
{
  int current_max , max_so_far;
  current_max = max_so_far = array[0];
  for( int i = 1 ; i < array.size() ; i++ )
  {
    current_max = max( array[i] , current_max + array[i] );
    if( current_max > max_so_far )
      max_so_far = current_max;
  }
  return max_so_far;
}

int main()
{
  int N , maximum_sum;
  while( scanf("%d", &N ) && N != 0 )
  {
    vector < int > jackpot( N , 0 );
    for( int i = 0 ; i < N ; i++ )
      scanf("%d", &jackpot[i] );
    maximum_sum = kadane ( jackpot );
    if( maximum_sum > 0 )
      printf("The maximum winning streak is %d.\n", maximum_sum );
    else
      printf("Losing streak.\n" );
  }
  return 0;
}
