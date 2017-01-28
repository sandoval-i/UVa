#include <bits/stdc++.h>

using namespace std;

int min_pasos , answer;

int bubblesort( vector < int > arr )
{
    int ans = 0;
    for( int i = 0 ; i < arr.size() ; ++i )
        for( int j = 0 ; j < arr.size() - 1 ; ++j )
            if(arr[j+1] < arr[j])
            {
                swap( arr[j+1] , arr[j]);
                ++ans;
            }
    return ans;
}

void solve( vector < int > arr , int number )
{
    if( number > min_pasos )    return;
    bool sorted = true;
    for( int i = 0 ; i < arr.size() - 1 ; ++i )
        if( arr[i] > arr[i+1] )
        {
            sorted = false;
            swap(arr[i] , arr[1 + i]);
            solve(arr , 1 + number );
            swap(arr[1 + i] , arr[i]);
        }
    answer += number == min_pasos && sorted && number > 0;
}

int main()
{
    int n , c = 0;
    while( scanf("%d" , &n) , n )
    {
        vector < int > arr;
        arr.resize(n);
        answer = 0;
        for( int i = 0 ; i < n ; ++i )  scanf("%d" , &arr[i]);
        min_pasos = bubblesort(arr);
        solve(arr,0);
        printf("There are %d swap maps for input data set %d.\n" , answer , ++c );
    }
    return 0;
}
