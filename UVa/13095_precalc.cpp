#include <bits/stdc++.h>

using namespace std;

int prec[10][100010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    short aux,cont;
    int n,a,b,q;
    for(int i = 0 ; i < 10 ; ++i)
        prec[i][0] = 0;
    while(cin >> n)
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> aux;
            for(int k = 0 ; k < 10 ; ++k)
                prec[k][i] = prec[k][i-1];
            ++prec[aux][i];
        }
        cin >> q;
        while(q--)
        {
            cin >> a >> b;
            cont = 0;
            for(int i = 0 ; i < 10 ; ++i)
                cont += prec[i][b] - prec[i][a-1] > 0;
            cout << cont << '\n';
        }
    }
    return 0;
}
