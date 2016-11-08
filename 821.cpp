#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ;  ++i )

int adjMat[100][100];

int main()
{
    int from , to , possible_paths , caso = 0;
    while( 1 )
    {
        scanf( "%d %d" , &from , &to );
        if( !from && !to )    break;
        foi( i , 0 , 100 )  foi( j , 0 , 100 )
        {
            if( i == j )    adjMat[i][j] = 0;
            else    adjMat[i][j] = 1e8;
        }
        adjMat[--from][--to] = 1;
        while( scanf( "%d %d" , &from , &to ) , from || to )
            adjMat[--from][--to] = 1;
        foi( k , 0 , 100 )
            foi( i , 0 , 100 )
                foi( j , 0 , 100 )
                    adjMat[i][j] = min( adjMat[i][j] , adjMat[i][k] + adjMat[k][j] );
        double total = 0.0;
        possible_paths = 0;
        foi( i , 0 , 100 )
        {
            foi( j , 0 , 100 )
            {
                if( i == j || adjMat[i][j] == 1e8 ) continue;
                ++possible_paths;
                total += adjMat[i][j];
            }
        }
        printf( "Case %d: average length between pages = %.3lf clicks\n" , ++caso , total / ( (double)possible_paths ) );
    }
    return 0;
}
