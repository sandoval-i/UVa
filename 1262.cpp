#include <bits/stdc++.h>

using namespace std;

char mat[6][5],mat2[6][5];
bool exist[5][30] , printed;
int k ,cont;

bool works(string &a)
{
    for(int i = 0 ; i < a.size() ; ++i)
        if(!exist[i][a[i]-'A'])
            return false;
    return true;
}

void go(int i , string a)
{
    if(i == 5)
    {
        if(works(a))
            if(++cont == k)
            {
                printf("%s\n" , a.c_str());
                printed = true;
            }
        return;
    }
    bitset < 28 > used;
    for(int k = 0 ; k < 6 && !printed ; ++k)
    {
        if(used[mat[k][i] - 'A'])   continue;
        go(1 + i , a + mat[k][i]);
        used[mat[k][i] - 'A'] = true;
    }
}

int main()
{
    int c;
    scanf("%d" , &c);
    while(c--)
    {
        printed = cont = false;
        memset(exist , false , sizeof exist);
        scanf("%d" , &k);
        vector < string > arr(5 , "");
        for(int i = 0 ; i < 6 ; ++i)
            for(int j = 0 ; j < 5 ; ++j)
            {
                scanf(" %c" , &mat[i][j]);
                arr[j] += mat[i][j];
            }
        for(int i = 0 ; i < 6 ; ++i)
            for(int j = 0 ; j < 5 ; ++j)
            {
                scanf(" %c" , &mat2[i][j]);
                exist[j][mat2[i][j] - 'A'] = true;
            }
        for(int i = 0 ; i < arr.size() ; ++i)
        {
            sort(arr[i].begin() , arr[i].end());
            for(int k = 0 ; k < arr[i].size() ; ++k)
                mat[k][i] = arr[i][k];
        }
        go(0,"");
        if(!printed)
            puts("NO");
    }
    return 0;
}
