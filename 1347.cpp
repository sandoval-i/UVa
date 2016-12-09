#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define MAX_N 500
typedef pair < double , double > dd;

dd points[MAX_N];
double dist[MAX_N][MAX_N];
double memo[MAX_N][MAX_N];
int n;

double dp( int endLR , int beginRL )
{
    int v = 1 + max( endLR , beginRL );
    if( v == n - 1)
        return dist[n-1][endLR] + dist[n-1][beginRL];
    if( memo[endLR][beginRL] > -0.5 )   return memo[endLR][beginRL];
    return memo[endLR][beginRL] = min( dist[endLR][v] + dp( v , beginRL ) , dist[beginRL][v] + dp( endLR , v ) );
}

double euclidean( dd a , dd b )
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt( ( dx * dx ) + ( dy * dy ) );
}

int main()
{
    while(scanf( "%d" , &n ) != EOF )
    {
        foi( i , 0 , n )    foi( j , 0 , n )    memo[i][j] = -1.0;
        foi( i , 0 , n )
            scanf("%lf %lf" , &points[i].first , &points[i].second );
        foi( i , 0 , n )
            foi( j , i + 1 , n )
                dist[i][j] = dist[j][i] = euclidean(points[i] , points[j]);
        printf( "%.2lf\n" , dp( 0 , 0 ) );
    }
    return 0;
}
