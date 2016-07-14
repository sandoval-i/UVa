#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef vector < ii > vii;
typedef long long ll;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )
#define size size()
#define pb( n ) push_back( n )
#define last( n ) n.size - 1
#define openR freopen( "in" , "r" , stdin )
#define openW freopen( "out" , "w" , stdout )
#define impar( i ) i & 1
#define par( i ) !( i & 1 )
#define testBit( n , i ) ( n & ( 1 << i ) )
#define turnOnBit( n , i ) ( n | ( 1 << i ) )
#define ignore cin.ignore()

char L;
int contestant , problem , tiempo;

struct Problem
{
  int timeR;
  bool solved;
};

struct Participante
{
  int solved , penalty , id;
  Problem problems[10];
  bool submit;
  bool operator < ( Participante &other )
  {
    if( !this->submit ) return false;
    if( !other.submit ) return true;
    if( this->solved == other.solved )
    {
      if( this->penalty == other.penalty ) return this->id < other.id;
      return this->penalty < other.penalty;
    }
    return this->solved > other.solved;
  }
};

Participante contest[101];

void agregar()
{
  Participante &k = contest[contestant];
  Problem &a = contest[contestant].problems[problem];
  k.submit = true;
  if( L == 'R' || L == 'U' || L == 'E' )  return;
  if( L == 'C' )
  {
    if( !a.solved ) a.solved = true , k.penalty += a.timeR + tiempo , k.solved++;
    return;
  }
  a.timeR += 20;
}

int main()
{
  int test;
  Problem p;
  p.solved = p.timeR = 0;
  string linea , trash;
  scanf("%d", &test );
  ignore;
  ignore;
  while( test-- )
  {
    foi( i , 0 , 101 )
    {
      contest[i].solved = contest[i].penalty = 0 , contest[i].submit = false , contest[i].id = i;
      foi(  j , 0 , 10 ) contest[i].problems[j] = p;
    }
    while( getline( cin , linea ) , linea != "" )
    {
      sscanf( linea.c_str() , "%d %d %d %c" , &contestant , &problem , &tiempo , &L );
      agregar();
    }
    sort( contest , contest + 101 );
    foi( i , 0 , 101 )
      if( !contest[i].submit ) break;
      else printf("%d %d %d\n", contest[i].id , contest[i].solved , contest[i].penalty );
    if( test )  printf("\n");
  }
  return 0;
}
