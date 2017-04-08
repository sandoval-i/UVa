#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

typedef pair < int , int > ii;

int n , m;
vector < ii > pieces;

bool backtrack( int rm , int bitmask )
{
    if( __builtin_popcount(bitmask) == n )
    {
        if( rm == pieces[1].first )
            return true;
        return false;
    }
    for( int i = 2 ; i < pieces.size() ; ++i )
    {
        if( bitmask & ( 1 << i ) )  continue;
        if( pieces[i].first == rm && backtrack( pieces[i].second , bitmask | ( 1 << i ) ) )  return true;
        if( pieces[i].second == rm && backtrack( pieces[i].first , bitmask | ( 1 << i ) ) )   return true;
    }
    return false;
}

int main()
{
    while( scanf("%d" , &n) , n )
    {
        scanf("%d" , &m);
        pieces.resize(m + 2);
        foi( i , 0 , pieces.size() ) scanf( "%d %d" , &pieces[i].first , &pieces[i].second );
        puts( backtrack( pieces[0].second , 0 ) ? "YES" : "NO" );
    }
    return 0;
}
