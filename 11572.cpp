#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

int main()
{
    int casos , n , aux , ans , l;
    scanf("%d" , &casos);
    while( casos-- )
    {
        scanf("%d" , &n );
        ans = l = 0;
        unordered_map < int , int > last_pos;
        foi( i , 0 , n )
        {
            scanf( "%d" ,&aux );
            if( last_pos.find(aux) == last_pos.end() )
                last_pos.insert(make_pair( aux , i ));
            else
            {
                l = max( l , last_pos[aux] + 1 );
                last_pos[aux] = i;
            }
            ans = max( ans , i - l + 1 );
        }
        printf("%d\n" , ans);
    }
    return 0;
}
