#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;

struct suffix_array {
    struct data {
        int idx, tie, last;
    };
    vector<vector<int> > mat, cnt_tie, cnt_last;
    vector<data> temp_sa, counting_ans;
    vector<int> suffix, order;
    int sz, lastk;
    void counting_tie(int max_tie) {
        foi(i,0,sz) cnt_tie[temp_sa[i].tie].push_back(i);
        for(int i = 0, idx = 0; i <= max_tie; ++i) {
            foi(j,0,cnt_tie[i].size())
                counting_ans[idx++] = temp_sa[cnt_tie[i][j]];
            cnt_tie[i].clear();
        }
        temp_sa.swap(counting_ans);
    }
    void counting_last(int max_last) {
        foi(i,0,sz) cnt_last[temp_sa[i].last].push_back(i);
        for(int i = 0, idx = 0; i <= max_last; ++i) {
            foi(j,0,cnt_last[i].size())
                counting_ans[idx++] = temp_sa[cnt_last[i][j]];
            cnt_last[i].clear();
        }
        temp_sa.swap(counting_ans);
    }

    void mem(int k) {
        k += 200;
        mat.assign(2 + floor(log2(k)), vector<int>(k));
        temp_sa.resize(k);
        counting_ans.resize(k);
        cnt_last.resize(k);
        cnt_tie.resize(k);
        suffix.resize(k);
        order.resize(k);
    }

    suffix_array(const string& s) { // O(nlgn)
        mem(sz = s.size());
        foi(i,0,sz)
            mat[0][i] = s[i];
        for(int k = 1, len = 1; len < sz; ++k, len <<= 1) {
            int max_last, max_tie;
            max_last = max_tie = LONG_MIN;
            foi(i,0,sz) {
                temp_sa[i].last = mat[k - 1][i];
                temp_sa[i].idx = i;
                temp_sa[i].tie = 1 + (i + len < sz ? mat[k - 1][i + len] : -1);
                max_last = max(max_last, temp_sa[i].last);
                max_tie = max(max_tie, temp_sa[i].tie);
            }
            counting_tie(max_tie);
            counting_last(max_last);
            foi(i,0,sz) {
                suffix[i] = mat[k][temp_sa[i].idx] = i && temp_sa[i].tie == temp_sa[i - 1].tie && temp_sa[i].last == temp_sa[i - 1].last ? mat[k][temp_sa[i - 1].idx] : i;
                order[i] = temp_sa[i].idx;
            }
            lastk = k;
        }
    }
    int lcp(int x, int y) {
        int ans = 0;
        if(x == y) return sz - x;
        for(int k = lastk - 1; k >= 0 && x < sz && y < sz; --k)
            if(mat[k][x] == mat[k][y])
                x += (1 << k), y += (1 << k), ans += (1 << k);
        return ans;
    }};


bool match(suffix_array& sa, int idx, int sz, int k) {
    int f = sa.lcp(0, idx);
    int s = sa.lcp(f + k, idx + f + k);
    return s >= (sz - k - f);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int tc,ans,i,k;
    cin >> tc;
    string t,p,o;
    while(tc--) {
        cin >> t >> p >> k;
        o = p + "$" + t;
        ans = 0;
        i = 1 + p.size();
        suffix_array sa(o);
        while(i + (int)p.size() - 1 < (int)o.size()) {
            ans += match(sa, i, p.size(), k);
            ++i;
        }
        cout << ans << '\n';
    }
    return 0;
}
