#include <bits/stdc++.h>

using namespace std;

unsigned long long res;

deque < int > mergesort( deque < int > arr )
{
    if(arr.size() == 1 )    return arr;
    deque < int > lv = mergesort(deque < int > (arr.begin(), arr.begin() + ( arr.size() >> 1) )) , rv = mergesort(deque < int > (arr.begin() + ( arr.size() >> 1 ) , arr.end()));
    deque < int > ans;
    while(lv.size() && rv.size())
    {
        if( lv.front() < rv.front() )
        {
            ans.push_back(rv.front());
            rv.pop_front();
        }
        else if( lv.front() > rv.front() )
        {
            res += rv.size();
            ans.push_back(lv.front());
            lv.pop_front();
        }
        else
        {
            ans.push_back(rv.front());
            rv.pop_front();
        }
    }
    while( lv.size() )
    {
        ans.push_back(lv.front());
        lv.pop_front();
    }
    while( rv.size() )
    {
        ans.push_back(rv.front());
        rv.pop_front();
    }
    return ans;
}

int main()
{
    int t , n , aux;
    scanf("%d" , &t);
    while(t--)
    {
        res = 0ULL;
        scanf("%d" , &n);
        deque < int > arr;
        for( int i = 0 ; i < n ; ++i )
        {
            scanf("%d" , &aux);
            arr.push_back(aux);
        }
        deque < int > sorted = mergesort(arr);
        printf("%llu\n" , res);
    }
    return 0;
}
