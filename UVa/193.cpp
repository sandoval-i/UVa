#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > g;
vector < int > bas;

struct cc
{
    vector < int > nodes;
    bitset < 101 > belongs;
    int best_ans;
    cc()
    {
        best_ans = 0;
    }

    void get_best(vector < int > &arr)
    {
        belongs.reset();
        go(0 , bas);
        for(int i = 0 ; i < nodes.size() ; ++i)
            if(belongs[nodes[i]])
                arr.push_back(1 + nodes[i]);
    }

    void go(int i , vector < int > c)
    {
        if(i == nodes.size())
        {
            int cont = 0;
            for(int k = 0 ; k < nodes.size() ; ++k)
                cont += c[nodes[k]] == 1;
            if(cont > best_ans)
            {
                best_ans = cont;
                for(int k = 0 ; k < nodes.size() ; ++k)
                    belongs[nodes[k]] = c[nodes[k]] == 1;
            }
            return;
        }
        int u = nodes[i] , v;
        bool any_black = false;
        for(int k = 0 ; k < g[u].size() && !any_black ; ++k)
            any_black = c[g[u][k]] == 1;
        if(any_black)
        {
            c[u] = 0;
            go(1 + i , c);
        }
        else
        {
            c[u] = 1;
            go(1 + i , c);
            c[u] = 0;
            go(1 + i , c);
        }
    }

};

vector < cc > ccs;

struct DSU
{
    vector < int > rank , parent;

    DSU(int n)
    {
        rank.assign(n , 1);
        parent.assign(n , 0);
        for(int i = 1 ; i < n ; ++i)
            parent[i] = i;
    }

    int root(int k)
    {
        return k == parent[k] ? k : parent[k] = root(parent[k]);
    }

    bool connected(int i , int j)
    {
        return root(i) == root(j);
    }

    void connect(int i , int j)
    {
        int p = root(i) , q = root(j);
        if(p == q)  return;
        if(rank[q] > rank[p])
            swap(p,q);
        rank[p] += rank[q];
        parent[q] = p;
    }

};

int main()
{
    bas.assign(101 , -1);
    int c;
    int n,e,u,v;
    scanf("%d" , &c);
    while(c--)
    {
        scanf("%d %d" , &n , &e);
        g.assign(n , vector < int >());
        DSU ds(n);
        ccs.assign(n , cc());
        while(e--)
        {
            scanf("%d %d" , &u , &v);
            g[--u].push_back(--v);
            g[v].push_back(u);
            ds.connect(u , v);
        }
        for(int i = 0 ; i < n ; ++i)
            ccs[ds.root(i)].nodes.push_back(i);
        vector < int > best;
        for(int i = 0 ; i < ccs.size() ; ++i)
            ccs[i].get_best(best);
        printf("%lu\n" , best.size());
        for(int i = 0 ; i < best.size() ; ++i)
        {
            if(i)
                printf(" ");
            printf("%d" , best[i] );
        }
        puts("");
    }
    return 0;
}
