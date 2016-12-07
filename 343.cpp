#include <bits/stdc++.h>

using namespace std;

int baseConversion( char *num , int len , int base )
{
    int ans = 0 , pot = 1;
    for( int i = len - 1 ; i >= 0 ; --i )
    {
        if( num[i] >= '0' && num[i] <= '9' )
            ans += ( num[i] - '0' ) * pot;
        else
            ans += ( num[i] - 'A' + 10 ) * pot;
        pot *= base;
    }
    return ans;
}


int minBase( char* num , int tam )
{
    int base = -1;
    for( int i = 0 ; i < tam ; ++i )
    {
        if( num[i] >= '0' && num[i] <= '9' )
            base = max( base , num[i] - '0' + 1 );
        else
            base = max( base , num[i] - 'A' + 11 );
    }
    return max( base , 2 );
}

int main()
{
    char num1[100] , num2[100];
    int tam1 , tam2;
    int base1from , base2from , base1 , base2;
    while( scanf("%s %s" , &num1 , &num2) != EOF )
    {
        tam1 = strlen(num1);
        tam2 = strlen(num2);
        base1from = minBase(num1 , tam1);
        base2from = minBase(num2 , tam2);
        base1 = base2 = -1;
        for( int i = base1from ; i <= 36 ; ++i )
            for( int j = base2from ; j <= 36 ; ++j )
                if( baseConversion( num1 , tam1 , i ) == baseConversion( num2 , tam2 , j ) )
                {
                    base1 = i;
                    base2 = j;
                    i = j = 1e6;
                }
        if( base1 == -1 )
            printf( "%s is not equal to %s in any base 2..36\n" , num1 , num2 );
        else
            printf( "%s (base %d) = %s (base %d)\n" , num1 , base1 , num2 , base2 );
    }
    return 0;
}
