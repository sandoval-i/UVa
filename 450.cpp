#include <bits/stdc++.h>

using namespace std;

#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define pb push_back
#define last data.size()-1

vector < vector < string > > data;
string info , dep;

void agregar( string &a , int &indice )
{
    data.pb( vector < string >() );
    data[last].pb( dep );
    char *pch = new char[10000];
    char *cadena =  new char[a.size() + 1];
    strcpy( cadena , a.c_str() );
    pch = strtok( cadena , "," );
    while( pch != NULL )
        data[last].pb( string( pch ) ) , pch = strtok( NULL , "," );
}

bool comp( vector < string > &data1 , vector < string > &data2 )
{
    return data1[3] < data2[3];
}

int main()
{
    int test;
    scanf( "%d" , &test );
    cin.ignore();
    foi( i , 0 , test )
    {
        getline( cin , dep );
        while( getline( cin , info ) , info != "" )
            agregar( info , i );
        sort( data.begin() , data.end() , comp );
    }
    foi( i , 0 , data.size() )
        printf( "----------------------------------------\n%s %s %s\n%s\nDepartment: %s\nHome Phone: %s\nWork Phone: %s\nCampus Box: %s\n" , data[i][1].c_str() , data[i][2].c_str() , data[i][3].c_str()
               , data[i][4].c_str() , data[i][0].c_str() , data[i][5].c_str() , data[i][6].c_str() , data[i][7].c_str() );
    return 0;
}
