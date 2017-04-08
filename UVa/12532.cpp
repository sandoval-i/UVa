#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = n ; i < k ; ++i )

struct Node
{

  int negative, zero;

  Node( void )
  {
    negative = zero = 0;
  }

  void update( int number )
  {
    negative = number < 0;
    zero = number == 0;
  }

};

struct SegmentTree
{

  vector < Node > tree;
  int tam;

  void construir( int pos , int l , int r , vector < int > &arr )
  {
    if( l == r )
    {
      tree[pos].update( arr[l] );
      return;
    }
    int mid = ( l + r ) >> 1;
    int left = ( pos << 1 ) | 1;
    int right = ( pos << 1 ) + 2;
    construir( left , l , mid , arr );
    construir( right , mid + 1 , r , arr );
    tree[pos].negative = tree[left].negative + tree[right].negative;
    tree[pos].zero = tree[left].zero + tree[right].zero;
  }

  SegmentTree( vector < int > &arr )
  {
    tam = arr.size();
    tree.assign( 4 * tam , Node() );
    construir( 0 , 0 , tam - 1 , arr );
  }

  void update( int &pos_update , int &data_udpate , int l , int r , int pos )
  {
    if( pos_update >= l && pos_update <= r )
    {
      if( l == r )
      {
        tree[pos].update( data_udpate );
        return;
      }
      int mid = ( l + r ) >> 1;
      int left = ( pos << 1 ) | 1;
      int right = ( pos << 1 ) + 2;
      update( pos_update , data_udpate , l , mid , left );
      update( pos_update , data_udpate , mid + 1 , r , right );
      tree[pos].negative = tree[left].negative + tree[right].negative;
      tree[pos].zero = tree[left].zero + tree[right].zero;
    }
  }

  void update( int pos_update , int data_update )
  {
    update( pos_update , data_update , 0 , tam - 1 , 0 );
  }

  Node query( int &lq , int &rq , int l , int r , int pos )
  {
    if( l > rq || r < lq )  return Node();
    if( l >= lq && r <= rq )
      return tree[pos];
    int mid = ( l + r ) >> 1;
    int left = ( pos << 1 ) | 1;
    int right = ( pos << 1 ) + 2;
    Node l_ans = query( lq , rq , l , mid , left );
    Node r_ans = query( lq , rq , mid + 1 , r , right );
    Node ans;
    ans.negative = l_ans.negative + r_ans.negative;
    ans.zero = l_ans.zero + r_ans.zero;
    return ans;
  }

  char query( int l , int r )
  {
    Node ans = query( l , r , 0 , tam - 1 , 0 );
    if( ans.zero > 0 )  return '0';
    if( ans.negative & 1 )  return '-';
    return '+';
  }

};

int main()
{
  int N , K;
  char comand;
  int l , r;
  while( scanf( "%d %d" , &N , &K ) != EOF )
  {
    vector < int > arreglo( N , 0 );
    foi( i , 0 , N )  scanf( "%d" , &arreglo[i] );
    SegmentTree seg( arreglo );
    while( K-- )
    {
      scanf( " %c %d %d" , &comand , &l , &r );
      if( comand == 'C' )
        seg.update( l - 1 , r );
      else
        printf( "%c" , seg.query( l - 1 , r - 1 ) );
    }
    puts("");
  }
  return 0;
}
