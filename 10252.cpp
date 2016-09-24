#include <bits/stdc++.h>

using namespace std;

#define MAX_LENGTH 1001
#define ALPHABET 26


int main()
{
    char cadena1[MAX_LENGTH] , cadena2[MAX_LENGTH];
    int tam1 , tam2 , frec1[MAX_LENGTH] , frec2[MAX_LENGTH] , num_char;
    while( cin.getline( cadena1 , MAX_LENGTH , '\n' ) && cin.getline( cadena2 , MAX_LENGTH , '\n' ) )
    {
        string ans;
        memset( frec1 , 0 , sizeof frec1 );
        memset( frec2 , 0 , sizeof frec2 );
        tam1 = strlen( cadena1 );
        tam2 = strlen( cadena2 );
        for( int i = 0 ; i < tam1 ; ++i )
            ++frec1[cadena1[i] - 'a'];
        for( int i = 0 ; i < tam2 ; ++i )
            ++frec2[cadena2[i] - 'a'];
        for( int i = 0 ; i < ALPHABET ; ++i )
        {
                num_char = min( frec1[i], frec2[i] );
                for( int j = 0 ; j < num_char ; ++j )
                    ans += (char)( i + 'a' );
        }
        sort( ans.begin() , ans.end() );
        printf("%s\n" , ans.c_str() );
    }
	return 0;
}
