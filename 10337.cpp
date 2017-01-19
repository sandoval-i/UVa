#include <bits/stdc++.h>

using namespace std;

int X , memo[1003][13] , w[13][1003];

int dp( int pos , int alt )
{
    if( memo[pos][alt] != -1 )
        return memo[pos][alt];
    if( pos == X )
        return !alt ? 0 : 1e5;
    int ans = 30 + dp(1 + pos , alt );
    if( alt + 1 <= 9 )
        ans = min(ans , 60 + dp(1 + pos , alt + 1) );
    if( alt - 1 >= 0 )
        ans = min(ans , 20 + dp(1 + pos , alt - 1) );
    return memo[pos][alt] = w[alt][pos] + ans;
}

int main()
{
	int casos;
	scanf("%d" , &casos);
	while(casos--)
    {
        scanf("%d" , &X);
        X /= 100;
        for( int i = 9 ; i >= 0 ; --i)
            for( int j = 0 ; j < X ; ++j )
            {
                scanf("%d" , &w[i][j] );
                w[i][j] *= -1;
            }
        memset(memo , -1 , sizeof memo);
        printf("%d\n\n" , dp(0,0));
    }
	return 0;
}
