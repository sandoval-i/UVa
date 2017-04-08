#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )

int main()
{
    int adjMat_young[26][26], adjMat_old[26][26];
    int conexiones;
    while( scanf( "%d" , &conexiones ) , conexiones )
    {
        char para , directional, from , to , from_young , from_old;
        int costo;
        foi( i , 0 , 26 )
            foi( j , 0 , 26 )
                adjMat_young[i][j] = adjMat_old[i][j] = ( i == j ) ? 0 : 1e8;
        while( conexiones-- )
        {
            scanf( " %c %c %c %c %d" , &para , &directional , &from , &to , &costo );
            from -= 'A';
            to -= 'A';
            if( para == 'Y' )
            {
                adjMat_young[from][to] = min( adjMat_young[from][to] , costo );
                if( directional == 'B' )
                    adjMat_young[to][from] = min( adjMat_young[to][from] , costo );
            }
            else
            {
                adjMat_old[from][to] = min( adjMat_old[from][to] , costo );
                if( directional == 'B' )
                    adjMat_old[to][from] = min( costo , adjMat_old[to][from] );
            }
        }
        scanf( " %c %c" , &from_young , &from_old );
        from_young -= 'A';
        from_old -= 'A';
        foi( k , 0 , 26 )
            foi( i , 0 , 26 )
                foi( j , 0 , 26 )
                {
                    adjMat_old[i][j] = min( adjMat_old[i][j] , adjMat_old[i][k] + adjMat_old[k][j] );
                    adjMat_young[i][j] = min( adjMat_young[i][j] , adjMat_young[i][k] + adjMat_young[k][j] );
                }
        int ans = 1e8;
        foi( i , 0 , 26 )
            ans = min( ans , adjMat_young[from_young][i] + adjMat_old[from_old][i] );
        if( ans == 1e8 )
            puts("You will never meet.");
        else
        {
            printf( "%d" , ans );
            foi( i , 0 , 26 )
                if( adjMat_young[from_young][i] + adjMat_old[from_old][i] == ans )
                    printf( " %c" , i+'A' );
            printf("\n");
        }
    }
    return 0;
}
