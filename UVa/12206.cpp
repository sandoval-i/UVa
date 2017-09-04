#include <bits/stdc++.h>
using namespace std;

#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
#define left ((pos << 1) | 1)
#define right (1 + left)
#define mid ((low + high) >> 1)
struct stree {
    vector<int> tree;
    int sz;
    stree(vector<int>& arr) {
        tree.resize((sz = arr.size()) << 2);
        build(0, sz - 1, 0, arr);
    }
    int op(int a, int b){return max(a,b);}
    bool overlap(int qlow, int qhigh, int i, int j) {return !(qhigh < i || qlow > j);}
    int build(int low, int high, int pos, vector<int>& arr) {
        return tree[pos] = (low == high ? arr[low] : op(build(low, mid, left, arr), build(1 + mid, high, right, arr)));
    }
    int query(int& qlow, int& qhigh, int low, int high, int pos) {
        if(low >= qlow && high <= qhigh)  return tree[pos];
        if(overlap(qlow, qhigh, low, mid))
                return overlap(qlow, qhigh, 1 + mid, high) ? op(query(qlow, qhigh, low, mid, left), query(qlow, qhigh, 1 + mid, high, right)) : query(qlow, qhigh, low, mid, left);
        return query(qlow, qhigh, 1 + mid, high, right);
    }
    int query(int i, int j) {
        return query(i, j, 0, sz - 1, 0);
    }
    int update(int low, int high, int pos, int& x, int& val) {
        if(x >= low && x <= high) {
            if(low == high) return tree[pos] = val;
            return tree[pos] = op(update(low, mid, left, x, val), update(1 + mid, high, right, x, val));
        }
        return tree[pos];
    }
    void update(int pos, int val) {
        update(0, sz - 1, 0, pos, val);
    }};

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
    }
};

string print(string& s, int k) {
    string ans;
    for(; k < (int)s.size(); ++k)
        ans += s[k];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,ans,res,be;
    string s;
    while(cin >> m, m) {
        cin >> s;
        suffix_array sa(s);
        stree t(sa.order);
        ans = 0;
        foi(i,0,s.size()) {
            if(i + m - 1 >= (int)s.size()) break;
            res = sa.lcp(sa.order[i], sa.order[i + m - 1]);
            if(res > ans) {
                ans = res;
                be = t.query(i, i + m - 1);
            }
            else if(res == ans)
                be = max(be, t.query(i, i + m - 1));
        }
        if(!ans) cout << "none";
        else cout << ans << ' ' << be;
        cout << '\n';
    }
    return 0;
}
