#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

#define MAX_N 2000010

int main()
{
    int n , frec[101] , cont , aux;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while( cin >> n , n )
    {
        memset( frec , 0 , sizeof frec );
        foi( i , 0 , n )
        {
            cin >> aux;
            ++frec[aux];
        }
        cont = 0;
        bool flag = false;
        for( int i = 0 ; i < 101 && !flag ; ++i )
            foi( j , 0 , frec[i] )
            {
                cout << i;
                if( cont == n - 1 )
                {
                    flag = true;
                    cout << '\n';
                    break;
                }
                cout << ' ';
                ++cont;
            }
    }
    return 0;
}
