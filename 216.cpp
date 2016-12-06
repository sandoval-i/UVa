#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

double dist[MAX_N][MAX_N];
double memo[MAX_N][1 << MAX_N];
pair < double , double > computers[MAX_N];
int n;

#define EPS 1e-9

double euclidean( pair < double , double > a , pair < double , double > b )
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    dx *= dx;
    dy *= dy;
    return sqrt( dx + dy );
}

double dp(int pos, int bitmask)
{
  if( bitmask == ( ( 1 << n ) - 1 ) )   return 0.0;
  if( memo[pos][bitmask] >= 0.00 )  return memo[pos][bitmask];
  double ans = 9999999.00;
  for( int i = 0; i < n ; i++ )
    if( !( bitmask & ( 1 << i ) ) )
      ans = min( ans, dist[pos][i] + dp( i , bitmask | ( 1 << i ) ) );
  return memo[pos][bitmask] = ans;
}

void print_sol( int pos , int visited )
{
    if( visited == ( ( 1 << n ) - 1 ) ) return;
    foi( i , 0 , n )
    {
        if( !( visited & ( 1 << i ) ) && fabs( ( dist[pos][i] + dp( i , visited | ( 1 << i ) ) ) - memo[pos][visited] ) <= EPS )
        {
            printf( "Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n" , computers[pos].first , computers[pos].second , computers[i].first , computers[i].second , dist[pos][i] );
            print_sol( i , visited | ( 1 << i ) );
            return;
        }
    }
}

int main()
{
    int caso = 0 , best_point;
    double best_len;
    while( scanf("%d" , &n ) , n )
    {
        foi( i , 0 , MAX_N )    foi( j , 0 , 1 << MAX_N )   memo[i][j] = -1.00;
        puts("**********************************************************");
        printf("Network #%d\n" , ++caso);
        foi( i , 0 , n )    scanf( "%lf %lf" , &computers[i].first , &computers[i].second );
        foi( i , 0 , n )    foi( j , i + 1 , n )
            dist[i][j] = dist[j][i] = 16.00 + euclidean( computers[i] , computers[j] );
        best_len = 99999999.00;
        foi( i , 0 , n )
            if( dp( i , 1 << i ) < best_len )
            {
                best_len = dp( i , 1 << i );
                best_point = i;
            }
        print_sol( best_point , 1 << best_point );
        printf( "Number of feet of cable required is %.2lf.\n" , best_len );
    }
    return 0;
}
