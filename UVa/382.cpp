#include <bits/stdc++.h>

using namespace std;

int main()
{
    puts("PERFECTION OUTPUT");
    int n , ans;
    while( scanf("%d" , &n) , n )
    {
        ans = 0;
        for( int i = 1 ; i < n ; ++i )
            if( !( n % i ) )    ans += i;
        printf("%5d  " , n);
        puts( ans == n ? "PERFECT" : ans < n ? "DEFICIENT" : "ABUNDANT");
    }
    puts("END OF OUTPUT");
    return 0;
}
