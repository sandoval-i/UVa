#include <bits/stdc++.h>

using namespace std;

int mat[80][80];
int memo[80][80][10][3];
bool done[80][80][10][3];
int N;

int dp( int i , int j , int k_left , int last )
{
    if( done[i][j][k_left][last] )    return memo[i][j][k_left][last];
    int ans = -1e6;
    int k_left_dp = k_left;
    if(mat[i][j] < 0)
        --k_left_dp;
    if(k_left_dp < 0)  return memo[i][j][k_left][last] = -1e6;
    if( i == N - 1 && j == N - 1 )  return memo[i][j][k_left][last] = mat[i][j];
    if( j - 1 >= 0 && last != 1 ) // left
        ans = max( ans , dp(i , j - 1 , k_left_dp , 0 ));
    if( 1 + j < N && last != 0 ) // right
        ans = max( ans , dp(i , 1 + j , k_left_dp , 1 ) );
    if( 1 + i < N )
        ans = max( ans , dp(1 + i , j , k_left_dp , 2) );
    done[i][j][k_left][last] = true;
    return memo[i][j][k_left][last] = ans + mat[i][j];
}

int main()
{
    int k , c = 0;
    while( scanf("%d %d" , &N, &k) , N || k )
    {
        memset(done , false , sizeof done);
        for( int i = 0 ; i < N ; ++i )
            for( int j = 0 ; j < N ; ++j )
                scanf("%d" , &mat[i][j]);
        int ans = dp(0,0,k,2);
        printf("Case %d: " , ++c );
        if( ans <= -1e4 )
            puts("impossible");
        else
            printf("%d\n" , ans);
    }
	return 0;
}
