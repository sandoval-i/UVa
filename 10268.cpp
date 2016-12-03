#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x , n , ans , pot;
    string linea , tok;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while( cin >> x )
    {
        cin.ignore();
        vector < int > a;
        getline( cin , linea );
        stringstream tokenizador( linea );
        n = 1;
        ans = 0;
        pot = 1;
        while( tokenizador >> tok )
            a.push_back( atoi( tok.c_str() ) );
        for( int i = a.size() - 2 ; i >= 0 ; --i )
        {
            ans += a[i] * n * pot;
            pot *= x;
            ++n;
        }
        cout << ans << '\n';
    }
    return 0;
}
