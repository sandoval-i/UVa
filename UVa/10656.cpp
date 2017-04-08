#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,aux;
    while(scanf("%d" , &n) , n)
    {
        vector < int > ans;
        for(int i = 0 ; i < n ; ++i)
        {
            scanf("%d" , &aux);
            if(aux)
                ans.push_back(aux);
        }
        if(ans.size())
            for(int i = 0 ; i < ans.size() ; ++i)
            {
                if(i)
                    printf(" ");
                printf("%d" , ans[i]);
            }
        else
            printf("0");
        puts("");
    }
    return 0;
}
