#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

int mat[1000][1000];
int N,M;
int dx[] = {0 , -1 , 0 , 1};
int dy[] = {-1 , 0 , 1 , 0};
int sy;
vector < pair < ii , ii > > solutions;

bool cmp2(ii a , ii b)
{
    return a.second < b.second;
}

bool cmp(pair < ii , ii > a , pair < ii , ii > b)
{
    if(a.first == b.first)
        return cmp2(a.second , b.second);
    return cmp2(a.first , b.first);
}

void solved(int ey)
{
    solutions.push_back(pair < ii , ii >(ii(0,sy) , ii(N - 1 , ey)));
}

inline bool in(int x , int y)
{
    return x >= 0 && y >= 0 && x < N && y < M;
}

void go(int x , int y , int seq)
{
    int x_to , y_to , next;
    if(x == N - 1)
    {
        solved(y);
        return;
    }
    if(mat[x][y] == seq)
    {
        next = 1;
        ++seq;
    }
    else
        next = 1 + mat[x][y];
    for(int i = 0 ; i < 4 ; ++i)
    {
        x_to = x + dx[i];
        y_to = y + dy[i];
        if(in(x_to , y_to) && mat[x_to][y_to] == next)
            go(x_to , y_to , seq);
    }
}

int main()
{
    int c;
    scanf("%d" , &c);
    while(c--)
    {
        solutions.clear();
        scanf("%d %d" , &N , &M);
        for(int i = 0 ; i < N ; ++i)
            for(int j = 0 ; j < M ; ++j)
                scanf("%d" , &mat[i][j]);
        for(int i = 0 ; i < M ; ++i)
            if(mat[0][i] == 1)
            {
                sy = i;
                go(0 , sy , 1);
            }
        pair < ii , ii > solution = *min_element(solutions.begin() , solutions.end() , cmp);
        printf("%d %d\n%d %d\n" , 1 + solution.first.first , 1 + solution.first.second , 1 + solution.second.first , 1 + solution.second.second);
        if(c)
            puts("");
    }
    return 0;
}
