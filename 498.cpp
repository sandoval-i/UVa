#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll x , n , pot , ans;
    string linea , tok;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while( getline( cin , linea ) )
    {
        vector < ll > a;
        stringstream tokenizador( linea );
        while( tokenizador >> tok )
            a.push_back( atoll( tok.c_str() ) );
        getline( cin , linea );
        stringstream token( linea );
        bool first = true;
        while( token >> tok )
        {
            if( !first )
                cout << ' ';
            else first = false;
            ans = 0;
            x = atoll(tok.c_str());
            pot = 1;
            for( int i = a.size() - 1 ; i >= 0 ; --i )
            {
                ans += a[i] * pot;
                pot *= x;
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}

