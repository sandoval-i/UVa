#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c = 0 , ans;
    double R , N;
    while( scanf("%lf %lf" , &R , &N) , R || N )
    {
        ans = ceil( ( R - N ) / N );
        printf("Case %d: " , ++c );
        if( ans >= 27 ) puts("impossible");
        else if( ans < 0 )  printf("%d\n" , 0);
        else    printf("%d\n" , ans);
    }
    return 0;
}
