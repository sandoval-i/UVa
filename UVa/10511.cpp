#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int name_sz;
map<string, int> name_to_id;
map<int, string> id_to_name;

int party_sz;
map<string, int> party_to_id;
map<int, string> id_to_party;

int club_sz;
map<string, int> club_to_id;
map<int, string> id_to_club;

vector<vector<int> >f, g;
vector<bool> visited;
vector<int> p;
int graph_sz, source, target, bottleneck, name_beg, party_beg, club_beg;


void add(string& s, map<string,int>& to_id, map<int,string>& to_string, int& cons) {
    if(!to_id.count(s)) {
        to_id[s] = cons;
        to_string[cons] = s;
        cons++;
    }
}

void create_graph() {
    graph_sz = name_sz + party_sz + club_sz + 2;
    g.assign(graph_sz, vector<int>());
    f.assign(graph_sz, vector<int>(graph_sz, 0));
    source = graph_sz - 1;
    target = graph_sz - 2;
    name_beg = 0;
    party_beg = name_sz;
    club_beg = party_beg + party_sz;
}

struct info {
    string name, party;
    vector<string> clubs;
    info(const string& k) {
        string tok;
        stringstream ss(k);
        ss >> name;
        ss >> party;
        while(ss >> tok)
            clubs.push_back(tok);
    }
};

void path(int v) {
    int u = p[v];
    if(~u) {
        bottleneck = min(bottleneck, f[u][v]);
        path(u);
        f[u][v] -= bottleneck;
        f[v][u] += bottleneck;
    }
}

bool dfs(int u, const int t) {
    visited[u] = true;
    if(u == t) return true;
    for(int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if(!visited[v] && f[u][v] > 0) {
            p[v] = u;
            if(dfs(v, t)) return true;
        }
    }
    return false;
}

int fordf(const int s, const int t) {
    int flow = 0;
    for(;;) {
        visited.assign(graph_sz, false);
        p.assign(graph_sz, -1);
        if(!dfs(s, t)) return flow;
        bottleneck = INF;
        path(t);
        flow += bottleneck;
    }
}

void add_edge(int u, int v, int fl) {
    g[u].push_back(v);
    g[v].push_back(u);
    f[u][v] = fl;
}

void print_solution(vector<info>& d) {
    for(auto a: d) {
        int v = name_beg + name_to_id[a.name];
        for(auto q: club_to_id) {
            int u = q.second + club_beg;
            for(auto o: g[u])
                if(o == v && !f[u][v]) {
                    cout << a.name << " " << id_to_club[q.second] << '\n';
                    goto nd;
                }
        }
        nd:;
    }
}

inline int half(int k) {
    return k & 1 ? (k >> 1) : ((k >> 1) - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool first = true;
    int c;
    string line;
    cin >> c;
    cin.ignore();
    cin.ignore();
    while(c--) {
        if(!first) cout << '\n';
        first = false;
        name_sz = party_sz = club_sz = 0;
        name_to_id.clear();
        party_to_id.clear();
        club_to_id.clear();
        id_to_name.clear();
        id_to_party.clear();
        id_to_club.clear();
        vector<info> data;
        while(getline(cin, line), line.size()) {
            info d(line);
            add(d.name, name_to_id, id_to_name, name_sz);
            add(d.party, party_to_id, id_to_party, party_sz);
            for(int i = 0; i < (int)d.clubs.size(); ++i)
                add(d.clubs[i], club_to_id, id_to_club, club_sz);
            data.push_back(d);
        }
        create_graph();
        for(const auto &a: club_to_id) {
            g[source].push_back(club_beg + a.second);
            f[source][club_beg + a.second] = 1;
        }
        for(const auto& a: data) {
            for(const auto& q: a.clubs)
                add_edge(club_beg + club_to_id[q], name_beg + name_to_id[a.name], 1);
            add_edge(name_beg + name_to_id[a.name], party_beg + party_to_id[a.party], 1);
        }
        for(auto a: party_to_id) {
            g[party_beg + a.second].push_back(target);
            f[party_beg + a.second][target] = half(club_sz);
        }
        int flow = fordf(source, target);
        if(flow == club_sz) print_solution(data);
        else cout << "Impossible." << '\n';
    }
    return 0;
}
