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

int memo[10201][100] , prices[100] , flavour[100] , m , n ;

int knapsack( int remainingMoney , int i )
{
  if( i == n || remainingMoney == 0 ) return 0; // End of items or not money enough to continue
  if( memo[remainingMoney][i] != -1 ) return memo[remainingMoney][i]; // Done before
  if( remainingMoney < prices[i] )  return memo[remainingMoney][i] = knapsack( remainingMoney , i + 1 ); // Ignore this item
  return memo[remainingMoney][i] = max( flavour[i] + knapsack( remainingMoney - prices[i] , i + 1 ) , knapsack( remainingMoney , i + 1 ) );
}

int knap( int i , int left )
{
  if( left == 0 )
    return 0;
  if( i == n )
  {
    if( m + 200 - left > 2000 || left > 200 )
      return 0;
    else
      return -5000;
  }
  if( memo[left][i] != -1 ) return memo[left][i];
  if( prices[i] > left ) return knap( i + 1 , left );
  return memo[left][i] = max( flavour[i] + knap( i + 1 , left - prices[i] ) , knap( i + 1 , left ) );
}

int main()
{
  while( scanf("%d %d", &m , &n ) != EOF )
  {
    memset( memo , -1 , sizeof memo );
    foi( i , 0 , n )  scanf("%d %d", &prices[i] , &flavour[i] );
    printf("%d\n", m > 1800 ? knap( 0 , m + 200 ) : knapsack( m , 0 ) );
  }
  return 0;
}
