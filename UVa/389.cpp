#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll to_decimal( char *num , int com , int len , int base )
{
    ll ans = 0 , pot = 1;
    for( int i = len - 1 ; i >= com ; --i )
    {
        if( num[i] >= '0' && num[i] <= '9' )
            ans += pot * ( num[i] - '0' );
        else
            ans += pot * ( num[i] - 'A' + 10 );
        pot *= base;
    }
    return ans;
}

string to_base( ll number , int base_to )
{
    if( !number )   return "0";
    string ans;
    ll div;
    int add;
    while(number)
    {
        add = number % base_to;
        number /= base_to;
        if( add >= 10 )
            ans.push_back(char( add + 55) );
        else
            ans.push_back( char(add +'0'));
    }
    return ans;
}

int main()
{
    char number[40];
    int com , tam;
    ll base_from , base_to , number_decimal;
    string ans;
    while( scanf( "%s %d %d" , number , &base_from , &base_to ) != EOF )
    {
        tam = strlen(number);
        com = 0;
        for( int i = 0 ; i < tam ; ++i )
        {
            if( number[i] != '0' )
                break;
            com = i;
        }
        ans = to_base( to_decimal( number , com , tam , base_from ) , base_to );
        if( ans.size() > 7 )
            puts("  ERROR");
        else
        {
            for( int i = 0 ; i < 7 - ans.size() ; ++i ) printf(" ");
            for( int i = ans.size() - 1 ; i >= 0 ; --i )    printf("%c" , ans[i]);
            printf("\n");
        }
    }
    return 0;
}
