#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[20][20];
char cad[18];
int n;

int char_to_int( char a )
{
    return a >= '0' && a <= '9' ? a - '0' : 10 + a - 'A';
}

int conv( char a )
{
    return char_to_int(a) - 1;
}

ll dp( int row , int col )
{
    if(memo[row][col] != -1)    return memo[row][col];
    ll ans = 0LL;
    if( 1 + col == n )  return memo[row][col] = 1LL;
    if( cad[1 + col] == '?' )
    {
        for( int i = row - 2 ; i >= 0 ; --i )
            ans += dp(i , 1 + col);
        for( int i = row + 2 ; i < n ; ++i )
            ans += dp(i , 1 + col);
    }
    else
    {
        if( abs( conv( cad[1 + col] ) - row ) <= 1 )
            return memo[row][col] = 0LL;
        else
            return memo[row][col] = dp( conv( cad[1 + col] ) , 1 + col);
    }
    return memo[row][col] = ans;
}

int main()
{
    ll ans;
    while(scanf("%s" , cad) != EOF)
    {
        memset(memo , -1 , sizeof memo);
        n = strlen(cad);
        ans = 0LL;
        if( cad[0] == '?' )
            for( int i = 0 ; i < n ; ++i )
                ans += dp(i,0);
        else
            ans = dp(conv(cad[0]) , 0);
        printf("%lld\n" , ans );
    }
    return 0;
}
