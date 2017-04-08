#include <bits/stdc++.h>

using namespace std;

#define MAX_NUMERO_ELEVADORES 10
#define MAX_NUMERO_PISOS 100
#define foi( i , n , k )    for( int i = n ; i < k ; ++i )
#define INF 1e8

int num_elevadores;
int speed_elevator[MAX_NUMERO_ELEVADORES];
vector < vector < int > > graph;
bool can[MAX_NUMERO_ELEVADORES][MAX_NUMERO_PISOS]; // [elevator][floor]

struct State
{
    int piso , elevador , costo;

    State( int a , int b , int c ) : elevador(a) , piso(b) , costo(c) {}

    State( void )
    {
        piso = elevador = costo = -2;
    }

    bool operator > ( const State &other )  const
    {
        return this->costo > other.costo;
    }

};

int dijkstra( int source , int target )
{
    State aux;
    vector < vector < int > > dist( MAX_NUMERO_ELEVADORES , vector < int >( MAX_NUMERO_PISOS , INF ) );
    priority_queue < State , vector < State > , greater < State > > pq;
    foi( i , 0 , num_elevadores )
        if( can[i][0] )
        {
            pq.push( State( i , 0 , 0 ) );
            dist[i][0] = 0;
        }
    while( !pq.empty() )
    {
        aux = pq.top();
        pq.pop();
        int piso_estoy = aux.piso;
        int elevador_estoy = aux.elevador;
        int costo = aux.costo;
        if( piso_estoy == target )  return costo;
        if( costo > dist[elevador_estoy][piso_estoy] )  continue;
        foi( i , 0 , num_elevadores ) // cambiar de elevador
        {
            if( !can[i][piso_estoy] )   continue;
            int costo_to = costo + 60;
            if( costo_to < dist[i][piso_estoy] )
            {
                dist[i][piso_estoy] = costo_to;
                pq.push( State( i , piso_estoy , costo_to ) );
            }
        }
        foi( i , 0 , graph[elevador_estoy].size() ) // cambiar de piso usando este elevador
        {
            int piso_to = graph[elevador_estoy][i];
            int costo_to = costo + abs( piso_estoy - piso_to ) * speed_elevator[elevador_estoy];
            if( costo_to < dist[elevador_estoy][piso_to] )
            {
                dist[elevador_estoy][piso_to] = costo_to;
                pq.push( State( elevador_estoy , piso_to , costo_to ) );
            }
        }
    }
    return -1;
}

int main()
{
    int ans , k;
    string linea , token;
    while( cin >> num_elevadores >> k )
    {
        graph.assign( num_elevadores , vector < int >() );
        foi( i , 0 , num_elevadores )
            cin >> speed_elevator[i];
        cin.ignore( 1000 , '\n' );
        memset( can , false , sizeof can );
        foi( i , 0 , num_elevadores )
        {
            getline( cin , linea );
            stringstream tokenizador(linea);
            while( tokenizador >> token )
            {
                int to = atoi( token.c_str() );
                can[i][to] = true;
                graph[i].push_back( to );
            }
        }
        ans = dijkstra( 0 , k );
        if( ans == -1 )
            cout << "IMPOSSIBLE";
        else
            cout << ans;
        cout << '\n';
    }
    return 0;
}

