#include <bits/stdc++.h>

using namespace std;

void add( string &ans , int resul , int &lleva )
{
        if( resul >= 10 )
        {
            ans.push_back( char( resul % 10  + '0' ) );
            lleva = resul / 10;
        }
        else
        {
            ans.push_back( char( resul + '0' ) );
            lleva = 0;
        }
}

void sum( string &ans , string &a , string &b )
{
    ans.clear();
    int i = a.size() - 1 , j = b.size() - 1 , resul;
    int lleva = 0;
    while( i >= 0 && j >= 0 )
    {
        add( ans , lleva + int( a[i] - '0' ) + int( b[j] - '0' ) , lleva );
        --i;
        --j;
    }
    while( i >= 0 )
        add( ans , lleva + int( a[i--] - '0' ) , lleva );
    while( j >= 0 )
        add( ans , lleva + int( b[j--] - '0' ) , lleva );
    if( lleva > 0 )
        ans.push_back( char( lleva + '0' ) );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int casos , com , i ;
    cin >> casos;
    string num1 , num2 , ans;
    while( casos-- )
    {
        cin >> num1 >> num2;
        while( !num1.empty() )
        {
            if( num1[num1.size() - 1] != '0' )  break;
            num1.pop_back();
        }
        while( !num2.empty() )
        {
            if( num2[num2.size() - 1] != '0' )  break;
            num2.pop_back();
        }
        reverse( num1.begin() , num1.end() );
        reverse( num2.begin() , num2.end() );
        sum( ans , num1 , num2 );
        i = com = 0;
        while( i < ans.size() )
        {
            if( ans[i++] != '0' )    break;
            ++com;
        }
        if( com == ans.size() ) cout << 0;
        else    for( int j = com ; j < ans.size() ; ++j )
            cout << ans[j];
        cout << '\n';
    }
    return 0;
}
