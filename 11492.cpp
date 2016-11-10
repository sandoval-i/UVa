#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k )  for( int i = 0 ; i < k ; ++i )
#define INF 1e8
typedef pair < int , int > ii;

unordered_map < string , int > lang_id;
unordered_map < int , string > id_lang;
vector < string > words;
vector < vector < int > > word_langs;
vector < vector < int > > lang_words;
int cons_lang , M;

int getId( string &a )
{
  if( lang_id.find(a) == lang_id.end() ) return lang_id[a] = cons_lang++;
  else  return lang_id[a];
}

int dijkstra( int lang_from , int lang_to )
{
  priority_queue < ii , vector < ii > , greater < ii > > pq;
  vector < int > dist( M , INF );
  foi( i , 0 , lang_words[lang_from].size() )
  {
    int word_index = lang_words[lang_from][i];
    pq.push( ii( words[word_index].length() , word_index ) );
    dist[word_index] = words[word_index].length();
  }
  while( !pq.empty() )
  {
    ii aux = pq.top();
    pq.pop();
    int costo = aux.first;
    int word_estoy_index = aux.second;
    foi( i , 0 , word_langs[word_estoy_index].size() )
      if( word_langs[word_estoy_index][i] == lang_to )  return costo;
    foi( i , 0 , word_langs[word_estoy_index].size() )
    {
      int lang_estoy = word_langs[word_estoy_index][i];
      foi( j , 0 , lang_words[lang_estoy].size() )
      {
        int word_to_index = lang_words[lang_estoy][j];
        if( words[word_to_index][0] == words[word_estoy_index][0] ) continue;
        int costo_to = costo + words[word_to_index].size();
        if( costo_to < dist[word_to_index] )
        {
          pq.push( ii( costo_to , word_to_index ) );
          dist[word_to_index] = costo_to;
        }
      }
    }
  }
  return -1;
}


int main()
{
  int id1 , id2;
  string language_from , language_to , lang1 , lang2 , word;
  while( cin >> M , M )
  {
    lang_id.clear();
    id_lang.clear();
    words.clear();
    word_langs.assign( M , vector < int >() );
    lang_words.assign( ((M << 1) | 1) + 10 , vector < int >() );
    cin >> language_from >> language_to;
    lang_id[language_from] = 0;
    lang_id[language_to] = 1;
    id_lang[0] = language_from;
    id_lang[1] = language_to;
    cons_lang = 2;
    foi( i , 0 , M )
    {
      cin >> lang1 >> lang2 >> word;
      id1 = getId(lang1);
      id2 = getId(lang2);
      words.push_back(word);
      lang_words[id1].push_back(i);
      lang_words[id2].push_back(i);
      word_langs[i].push_back(id1);
      word_langs[i].push_back(id2);
    }
    int ans = dijkstra( 0 , 1 );
    if( ans == -1 ) cout << "impossivel";
    else  cout << ans;
    cout << '\n';
  }
  return 0;
}
