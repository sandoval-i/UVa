#include <bits/stdc++.h>

using namespace std;
#define alph 28

int R , C , W , max_word , ans , num_palabras , comparar[alph];
vector < string > matriz;
unordered_set < string > inserted;


void pre_process( void )
{
    int x , y;
    inserted.clear();
    for( int i = 0 ; i < R ; ++i )
    {
        string inserting;
        x = i;
        y = 0;
        while( x >= 0 && y < C )
            inserting.push_back( matriz[x--][y++] );
        if( inserted.find( inserting ) == inserted.end() )  inserted.insert( inserting );
    }
    for( int i = 1 ; i < C ; ++i )
    {
        string inserting;
        y = i;
        x = R - 1;
        while( x >= 0 && y < C )
            inserting.push_back( matriz[x--][y++] );
        if( inserted.find( inserting ) == inserted.end() )  inserted.insert( inserting );
    }
    for( int i = C - 1 ; i >= 0 ; --i )
    {
        string inserting;
        y = i;
        x = 0;
        while( x < R && y < C )
            inserting.push_back( matriz[x++][y++] );
        if( inserted.find(inserting) == inserted.end() )    inserted.insert( inserting );
    }
    for( int i = 1 ; i < R ; ++i )
    {
      string inserting;
      x = i;
      y = 0;
      while( x < R && y < C )
        inserting.push_back( matriz[x++][y++] );
      if( inserted.find(inserting) == inserted.end() )    inserted.insert( inserting );
    }
    for( int i = 0 ; i < R ; ++i )
    {
      string inserting = matriz[i];
      if( inserted.find(inserting) == inserted.end() )    inserted.insert( inserting );
    }
    for( int i = 0 ; i < C ; ++i )
    {
      string inserting;
      for( int j = 0 ; j < R ; ++j )
        inserting += matriz[j][i];
      if( inserted.find(inserting) == inserted.end() )    inserted.insert( inserting );
    }
}

bool compare( unordered_set < string > :: iterator &text , string &pattern , int index )
{
  memset( comparar , 0 , sizeof comparar );
  for( int i = 0 ; i < pattern.size() ; ++i )
    ++comparar[pattern[i]-'a'];
  for( int i = 0 ; i < pattern.size() ; ++i )
    --comparar[(*text)[index+i]-'a'];
  for( int i = 0 ; i < alph ; ++i )
    if( comparar[i] != 0 )  return false;
  return true;
}

bool solve( string &buscando )
{
  int hash_pattern = 0 , hash_text;
  for( int i = 0 ; i < buscando.size() ; ++i ) hash_pattern += buscando[i];
  for( unordered_set < string > :: iterator it = inserted.begin() ; it != inserted.end() ; ++it )
  {
    if( buscando.size() > it->size() ) continue;
    hash_text = 0;
    for( int i = 0 ; i < buscando.size() ; ++i )
      hash_text += (*it)[i];
    if( hash_text == hash_pattern ) if( compare( it , buscando , 0 ) )
      return true;
    for( int i = buscando.size() ; i < it->size() ; ++i )
    {
      hash_text -= (*it)[i-buscando.size()];
      hash_text += (*it)[i];
      if( hash_text == hash_pattern ) if( compare( it , buscando , i-buscando.size()+1 ) )
        return true;
    }
  }
  return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string abc;
    while( cin >> R >> C >> W )
    {
        ans = 0;
        matriz.assign( R , "" );
        for( int i = 0 ; i < R ; ++i )
            cin >> matriz[i];
        pre_process();
        for( int i = 0 ; i < W ; ++i )
        {
            cin >> abc;
            ans += solve( abc );
        }
        cout << ans << '\n';
    }
	return 0;
}
