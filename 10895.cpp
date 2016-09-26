#include <bits/stdc++.h>

using namespace std;

int main()
{
  int m , n , num;
  string linea , token , numeros;
  while( cin >> m >> n )
  {
    vector < vector < int > > matriz( m , vector < int >( n , 0 ) );
    for( int i = 0 ; i < m ; ++i )
    {
      cin >> num;
      vector < int > index( num , 0 );
      for( int j = 0 ; j < num ; ++j )
      {
        scanf("%d", &index[j] );
        --index[j];
      }
      cin.ignore( 100000 , '\n' );
      getline( cin , numeros );
      stringstream tokenizer( numeros );
      int k = 0;
      while( tokenizer >> token )
      {
        num = atoi( token.c_str() );
        matriz[i][index[k++]] = num;
      }
    }
    cout << n << " " << m << '\n';
    for( int i = 0 ; i < n ; ++i )
    {
        vector < int > indices;
        for( int k = 0 ; k < m ; ++k )
          if( matriz[k][i] != 0 ) indices.push_back( k + 1 );
        if( indices.empty() )
          cout << "0\n\n";
        else
        {
          cout << indices.size();
          for( int k = 0 ; k < indices.size() ; ++k )
              cout << " " << indices[k];
          cout << '\n';
          for( int k = 0 ; k < indices.size() ; ++k )
            if( k == 0 )
              cout << matriz[indices[k]-1][i];
            else
              cout << " " << matriz[indices[k]-1][i];
          cout << '\n';
        }
    }
  }
}
