#include <bits/stdc++.h>

using namespace std;

int main()
{
    int casos , tam , arr[15] , c = 0;
    scanf("%d" , &casos);
    while(casos--)
    {
        scanf("%d" , &tam);
        for( int i = 0 ; i < tam ; ++i )
            scanf("%d" , &arr[i]);
        printf("Case %d: %d\n" , ++c , arr[tam >> 1]);
    }
    return 0;
}
