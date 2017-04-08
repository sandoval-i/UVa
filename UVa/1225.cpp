#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , casos , copia , arr[10];
    scanf("%d" , &casos);
    while(casos--)
    {
        scanf("%d" , &n);
        memset( arr , 0 , sizeof arr );
        for( int i = 1 ; i <= n ; ++i )
        {
            copia = i;
            while(copia)
            {
                ++arr[copia%10];
                copia /= 10;
            }
        }
        for( int i = 0 ; i < 10 ; ++i )
        {
            printf("%d" , arr[i]);
            if( i != 9 )    printf(" ");
        }
        puts("");
    }

    return 0;
}
