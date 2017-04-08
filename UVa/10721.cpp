#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[52][52][52][3];
int len , bars , maxl;

ll dp( int idx , int b , int l , bool t )
{
    if( l > maxl ) return 0LL;
    if( memo[idx][b][l][t] != -1 )  return memo[idx][b][l][t];
    if( idx >= len )
        return !b ? 1LL : 0LL;
    if( !b )
        return memo[idx][b][l][t] = dp( 1 + idx , b , 1 + l , t );
    return memo[idx][b][l][t] = dp( 1 + idx , b - 1 , 1 , !t ) + dp( 1 + idx , b , 1 + l , t );
}

int main()
{
    while( scanf("%d %d %d" , &len , &bars , &maxl) != EOF )
    {
        memset( memo , -1 , sizeof memo );
        printf("%lld\n" , dp( 1 , bars - 1 , 1 , false ) );
    }
	return 0;
}
