#include <bits/stdc++.h>

using namespace std;

#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)

struct suffix_array {
    vector<vector<int> > mat;
    vector<int> order, suffix;
    struct data {
        int idx, tie, last;
        bool operator < (const data& o) const {
            if(this-> last == o.last)
                return this->tie < o.tie;
            return this->last < o.last;
        }
    };
    vector<data> temp;
    void build(const string s, int orig) {
        temp.resize(s.size());
        order.resize(s.size());
        suffix.resize(s.size());
        mat.assign(2 + floor(log2(s.size())), vector<int>(s.size()));
        foi(i,0,s.size())
            mat[0][i] = s[i];
        for(int k = 1, len = 1; len < (int)s.size(); ++k, len <<= 1) {
            foi(i,0,s.size()) {
                temp[i].last = mat[k - 1][i];
                temp[i].idx = i;
                temp[i].tie = i + len < (int)s.size() ? mat[k - 1][i + len] : LONG_MAX;
            }
            sort(temp.begin(), temp.end());
            foi(i,0,s.size()) {
                suffix[i] = mat[k][temp[i].idx] = i && temp[i].tie == temp[i - 1].tie && temp[i].last == temp[i - 1].last ? mat[k][temp[i - 1].idx] : i;
                order[i] = temp[i].idx;
            }
        }
    }
    int solve(int len) {
        foi(i,0,order.size())
            if(order[i] <= len) return order[i];
    }
};

int main() {
    suffix_array sa;
    char s[100010], o[100010];
    int len,tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%s", s);
        len = strlen(s);
        strcpy(o, s);
        strcat(s, o);
        sa.build(s, len);
        printf("%d\n", 1 + sa.solve(len));
    }
}
