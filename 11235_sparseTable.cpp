#include <bits/stdc++.h>

using namespace std;

#define foi( i , k , n )  for( int i = k ; i < n ; ++i )

// RMQ Sparse table
vector < vector < int > > sparse_table;
unordered_map < int , pair < int , int > > data;

// Build sparse table using array arr, O( nlog(n) )
void build_sparse( vector < int > arr )
{
  int columns = floor( log2( arr.size() ) ) + 1;
  sparse_table.assign( arr.size() , vector < int > ( columns , - 2 ) );
  for( int i = 0 ; i < sparse_table.size() ; ++i )  sparse_table[i][0] = i;
  for( int j = 1 ; j < columns ; ++j )
    for( int i = 0 ; i + ( 1 << j ) <= sparse_table.size() ; ++i )
    {
      sparse_table[i][j] = sparse_table[i][j-1];
      if( arr[ sparse_table[ i + ( 1 << ( j - 1 ) ) ][j-1] ] > arr[ sparse_table[i][j] ] )
        sparse_table[i][j] = sparse_table[ i + ( 1 << ( j - 1 ) ) ][j-1];
    }
}

// Make queries on sparse table from i to j, inclusive , O(1)
// Use only once you build sparse_table
int query_sparse( vector < int > &arr , int i , int j )
{
  if( i > j ) return 1;
  int len = j - i + 1;
  int k = floor( log2(len) );
  int max1 = sparse_table[i][k];
  int max2 = sparse_table[i + len - ( 1 << k )][k];
  return max( arr[max1] , arr[max2] );
}

int query( int i , int j , vector < int > &arreglo , vector < int > &frecuencias )
{
  if( arreglo[i] == arreglo[j] )  return j - i + 1;
  int inicio_query = data[arreglo[i]].second + 1 , fin_query = data[arreglo[j]].first - 1;
  return max( query_sparse( frecuencias , inicio_query , fin_query ) , max( inicio_query - i , j - fin_query ) );
}

int main()
{
  int n , q , ini , fin , number , anterior;
  while( scanf( "%d" , &n ) , n )
  {
    scanf( "%d" , &q );
    vector < int > arreglo( n , -1 );
    vector < int > frecuencias( n , 0 );
    data.clear();
    foi( i , 0 , n )
    {
      scanf( "%d" , &number );
      arreglo[i] = number;
      if( data.find( number ) == data.end() )
        data[number].first = data[number].second = i;
      else
        data[number].second = i;
    }
    foi( i , 0 , n )
      frecuencias[i] = data[arreglo[i]].second - data[arreglo[i]].first + 1;
    build_sparse( frecuencias );
    while( q-- )
    {
      scanf( "%d %d" , &ini , &fin );
      printf("%d\n" , query( ini - 1 , fin - 1 , arreglo , frecuencias ) );
    }
  }
  return 0;
}
