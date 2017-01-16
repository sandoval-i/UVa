#include <bits/stdc++.h>

using namespace std;

#define MAX_K 10002

typedef pair < int , int > ii;

int price;
int memo1[MAX_K << 1][100] , memo2[MAX_K << 1][100];
vector < int > coins;

// use dp twice

int dp1( int llevo , int k ) // min value passed from the limit
{
    if( memo1[llevo][k] != -1 )    return memo1[llevo][k];
    if( llevo >= price )    return llevo - price;
    if( k == coins.size() ) return 1e6;
    return memo1[llevo][k] = min( dp1( llevo + coins[k] , 1 + k ) , dp1( llevo , 1 + k ) ) ;
}

int dp2( int left , int k ) // min number of coins used to represent a value
{
    if( left < 0 )  return 1e6;
    if( memo2[left][k] != -1 ) return memo2[left][k];
    if( !left ) return 0;
    if( k == coins.size() ) return 1e6;
    return memo2[left][k] =  min( 1 + dp2( left - coins[k] , 1 + k ) , dp2( left , 1 + k ) );
}

int main()
{
    int casos, n;
    scanf("%d" , &casos);
    while( casos-- )
    {
        scanf("%d %d" , &price , &n);
        coins.resize(n);
        for( int i = 0 ; i < n ; ++i )
                scanf("%d" , &coins[i]);
        memset( memo1 , -1 , sizeof memo1 );
        memset( memo2 , -1 , sizeof memo2 );
        printf("%d %d\n" , price + dp1(0,0) ,  dp2( price + dp1(0,0) , 0 ) );
    }
    return 0;
}
