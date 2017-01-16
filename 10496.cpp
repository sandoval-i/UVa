#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

int numb;
vector < ii > b;
ii s;
int dist[15][15];
int memo[15][1 << 15]; // index beepers , visited beepers

int manh( ii p1 , ii p2 )
{
    return abs( p1.first - p2.first ) + abs( p1.second - p2.second );
}

int dp( int idx , int btm )
{
    if( memo[idx][btm] != -1 )  return memo[idx][btm];
    if( btm == ( 1 << numb ) - 1 )  return manh( b[idx] , s );
    int ans = 1e7;
    for( int i = 0 ; i < b.size() ; ++i )
    {
        if( btm & ( 1 << i ) )  continue;
        ans = min( ans , dist[idx][i] + dp( i , btm | ( 1 << i ) ));
    }
    return memo[idx][btm] = ans;
}

int main()
{
	int R , C , tc;
	scanf("%d" , &tc);
	while(tc--)
    {
        scanf("%d %d" , &R , &C);
        scanf("%d %d" , &s.first , &s.second );
        scanf("%d" , &numb );
        int ans = 1e8;
        b.resize(numb);
        for( int i = 0 ; i < numb ; ++i )
            scanf("%d %d" , &b[i].first , &b[i].second );
        for( int i = 0 ; i < numb ; ++i )
            for( int j = i + 1 ; j < numb ; ++j )
                dist[i][j] = dist[j][i] = manh( b[i] , b[j] );
        memset( memo , -1 ,sizeof memo );
        for( int i = 0 ; i < numb ; ++i )
            ans = min( ans , manh( s , b[i] ) + dp(i , 1 << i) );
        printf("The shortest path has length %d\n" , ans );
    }
	return 0;
}
