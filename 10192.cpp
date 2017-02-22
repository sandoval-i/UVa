#include <bits/stdc++.h>

using namespace std;

char f[101],s[101];
int memo[101][101],n,m;

int dp(int i , int j)
{
    if(i < 0 || j < 0)  return 0;
    if(memo[i][j] != -1)    return memo[i][j];
    if(f[i] == s[j])
        return memo[i][j] = 1 + dp(i - 1 , j - 1);
    return memo[i][j] = max(dp(i , j - 1) , dp(i - 1 , j));
}

int main()
{
    int c = 0;
    while(gets(f) , strcmp(f , "#") )
    {
        gets(s);
        n = strlen(f);
        m = strlen(s);
        memset(memo , -1 , sizeof memo);
        printf("Case #%d: you can visit at most %d cities.\n" , ++c , dp(n - 1 , m - 1));
    }
    return 0;
}
