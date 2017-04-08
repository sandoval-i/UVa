#include <bits/stdc++.h>

using namespace std;

int memo[1000001];

int dp( int i )
{
    if( memo[i] != -1 ) return memo[i];
    if( i <= 100 )  return memo[i] = dp(dp(i+11));
    else if( i>= 101 )  return memo[i] = i - 10;
}

int main()
{
    int a ;
    memset( memo , -1 , sizeof memo );
    while( scanf("%d" , &a) , a )
        printf( "f91(%d) = %d\n" , a , dp(a) );
	return 0;
}
