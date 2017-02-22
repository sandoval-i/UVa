#include <bits/stdc++.h>

using namespace std;

int len, memo[1001][1001];
char line[1200];

int dp(int i , int j)
{
    if(memo[i][j] != -1)    return memo[i][j];
    if(i == j)  return memo[i][j] = 1;
    if(i == j - 1) return memo[i][j] = line[i] == line[j] ? 2 : 1;
    if(line[i] == line[j])  return memo[i][j] = 2 + dp(1 + i , j - 1);
    return memo[i][j] = max(dp(1 + i,j) , dp(i , j - 1));
}

int main()
{
    int c;
    scanf("%d" , &c);
    gets(line);
    while(c--)
    {
        gets(line);
        len = strlen(line);
        memset(memo , -1 , sizeof memo);
        printf("%d\n" , dp(0 , len - 1));
    }
    return 0;
}
