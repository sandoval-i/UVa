#include <bits/stdc++.h>

using namespace std;

#define MAX_S 305
#define INF 1e7

int memo[MAX_S][MAX_S] , m , s;

vector < pair < int , int > > ec;

int dp( int x , int y )
{
    if( memo[x][y] != -1 )  return memo[x][y];
    if( x * x + y * y == s * s )    return 0;
    int ans = INF;
    for( int i = 0 ; i < ec.size() ; ++i )
        if( x + ec[i].first < MAX_S && y + ec[i].second < MAX_S )
            ans = min( ans , 1 + dp( x + ec[i].first , y + ec[i].second ) );
    return memo[x][y] = ans;
}

int main()
{
    int casos , ans;
    scanf("%d" , &casos);
    while(casos--)
    {
        scanf("%d %d" , &m , &s);
        memset( memo , -1 , sizeof memo );
        ec.resize(m);
        for( int i = 0 ; i < m ; ++i )  scanf("%d %d" , &ec[i].first , &ec[i].second );
        ans = dp(0,0);
        if( ans >= INF )    puts("not possible");
        else printf("%d\n" , ans );
    }
    return 0;
}
