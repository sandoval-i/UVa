#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )    for( int i = n ; i < k ; ++i )

vector < string > add;

inline int char_to_int( char &a )
{
    return int( a - '0' );
}

inline char int_to_char( int a )
{
    return char( a + '0' );
}

void op( string &ans , int &llevo , int &res )
{
    if( res >= 10 )
    {
        ans.push_back( int_to_char( res % 10 ) );
        llevo = res / 10;
    }
    else
    {
        llevo = 0;
        ans.push_back( int_to_char( res ) );
    }
}

string sum( string &a , string &b )
{
    string ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int llevo = 0 , res;
    while( i >= 0 && j >= 0 && ans.size() <= 3 )
    {
        res = llevo + char_to_int( a[i] ) + char_to_int( b[j] );
        op( ans , llevo , res );
        --i;
        --j;
    }
    while( i >= 0 && ans.size() <= 3 )
    {
        res = llevo + char_to_int( a[i] );
        op( ans , llevo , res );
        --i;
    }
    while( j >= 0 && ans.size() <= 3 )
    {
        res = llevo + char_to_int( b[i] );
        op( ans , llevo , res );
        --j;
    }
    reverse( ans.begin() , ans.end() );
    return ans;
}

int bfs( string source , string target )
{
    unordered_map < string , int > dist;
    string u , v;
    int pasos;
    queue < string > q;
    q.push( source );
    dist[source] = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        pasos = dist[u];
        if( u == target )   return pasos;
        foi( i , 0 , add.size() )
        {
            v = sum( add[i] , u );
            if( dist.find(v) == dist.end() )
            {
                dist[v] = 1 + pasos;
                q.push(v);
            }
        }

    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int R , ans , caso = 0;
    string L,U , aux;
    while( cin >> L >> U >> R , L != "0" || U != "0" || R )
    {
        add.clear();
        foi( i , 0 , R )
        {
            cin >> aux;
            add.push_back(aux);
        }
        ans = bfs(L,U);
        cout << "Case " << (++caso) << ": ";
        if( ans == -1 ) cout << "Permanently Locked";
        else    cout << ans;
        cout << '\n';
    }
}
