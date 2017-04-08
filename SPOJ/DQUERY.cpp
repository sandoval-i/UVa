#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

int bs;
int freq[1000005];
pair < ii , int > queries[200005];
int res[200005];

void rem( int &ans , int a )
{
    if( !--freq[a] )
        --ans;
}

void add( int &ans , int a )
{
    if( ++freq[a] == 1 )
        ++ans;
}

bool mo( pair < ii , int > a , pair < ii , int > b )
{
    int fb = a.first.first / bs;
    int sb = b.first.first / bs;
    if( fb == sb )
        return a.first.second < b.first.second;
    return fb < sb;
}

int main()
{
    int arr[30005] , n , q;
    scanf("%d" , &n);
    bs = sqrt(n);
    for( int i = 0 ; i < n ; ++i )
        scanf("%d" , &arr[i]);
    scanf("%d" , &q);
    for( int i = 0 ; i < q ; ++i )
    {
        scanf("%d %d" , &queries[i].first.first , &queries[i].first.second );
        --queries[i].first.first;
        --queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries , queries + q , mo);
    memset( freq , 0 , sizeof freq );
    int l , r , cl , cr , ans = 0;
    cl = cr = ans = 0;
    add(ans , arr[0]);
    for( int i = 0 ; i < q ; ++i )
    {
        l = queries[i].first.first;
        r = queries[i].first.second;
        while( cl < l )
            rem( ans , arr[cl++] );
        while( cl > l )
            add( ans , arr[--cl] );
        while( cr < r )
            add( ans , arr[++cr] );
        while( cr > r )
            rem( ans , arr[cr--] );
        res[queries[i].second] = ans;
    }
    for( int i = 0 ; i < q ; ++i )
        printf("%d\n" , res[i]);
	return 0;
}
