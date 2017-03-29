#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii; // max , min

#define INF 1e8

int N;

struct st{

    vector < ii > tree;

    st(){}

    void create(vector < int >& arr){
        tree.resize(arr.size() << 2);
        build(arr);
    }

    void build(vector < int >& arr, int low = 0, int high = N - 1, int pos = 0){
        if(low == high){
            tree[pos].first = tree[pos].second = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        build(arr, low, mid, left);
        build(arr, 1 + mid, high, right);
        tree[pos].first = max(tree[left].first, tree[right].first);
        tree[pos].second = min(tree[left].second, tree[right].second);
    }

    void create(st& l, st &r){
        tree.resize(N << 2);
        mix(l, r);
    }

    void mix(st& l, st &r, int low = 0, int high = N - 1, int pos = 0){
        if(low == high){
            tree[pos].first = max(l.tree[pos].first, r.tree[pos].first);
            tree[pos].second = min(l.tree[pos].second, r.tree[pos].second);
            return;
        }
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        mix(l, r, low, mid, left);
        mix(l, r, 1 + mid, high, right);
        tree[pos].first = max(tree[left].first, tree[right].first);
        tree[pos].second = min(tree[left].second, tree[right].second);
    }

    void update(int& p, int& val, int low = 0, int high = N - 1, int pos = 0){
        if(p >= low && p <= high){
            if(low == high){
                tree[pos].first = tree[pos].second = val;
                return;
            }
            int mid = (low + high) >> 1;
            int left = (pos << 1) | 1;
            int right = 1 + left;
            update(p, val, low, mid, left);
            update(p, val, 1 + mid, high, right);
            tree[pos].first = max(tree[left].first, tree[right].first);
            tree[pos].second = min(tree[left].second, tree[right].second);
        }
    }

    void update2(int &p, ii l, ii r, int pos = 0, int low = 0, int high = N - 1){
        if(p >= low && p <= high){
            if(low == high){
                tree[pos].first = max(l.first, r.first);
                tree[pos].second = min(l.second, r.second);
                return;
            }
            int mid = (low + high) >> 1;
            int left = (pos << 1) | 1;
            int right = 1 + left;
            update2(p, l, r, left, low , mid);
            update2(p, l, r, right, 1 + mid , high);
            tree[pos].first = max(tree[left].first, tree[right].first);
            tree[pos].second = min(tree[left].second, tree[right].second);
        }
    }

    ii query(int& qlow, int& qhigh, int low = 0, int high = N - 1, int pos = 0){
        if(qhigh < low || qlow > high)  return ii(-INF, INF);
        if(low >= qlow && high <= qhigh)    return tree[pos];
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        ii l = query(qlow, qhigh, low, mid, left);
        ii r = query(qlow, qhigh, 1 + mid, high, right);
        return ii(max(l.first, r.first), min(l.second, r.second));
    }

};

struct st2d{
    vector < st > tree;

    st2d(vector < vector < int > >& arr){
        tree.resize(arr.size() << 2);
        build(arr);
    }

    void build(vector < vector < int > >& arr, int low = 0, int high = N - 1, int pos = 0){
        if(low == high){
            tree[pos].create(arr[low]);
            return;
        }
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        build(arr, low, mid, left);
        build(arr, 1 + mid, high, right);
        tree[pos].create(tree[left], tree[right]);
    }

    void update(int& x, int& y, int &val, int pos = 0, int low = 0, int high = N - 1){
        if(x >= low && x <= high){
            if(low == high){
                tree[pos].update(y, val);
                return;
            }
            int mid = (low + high) >> 1;
            int left = (pos << 1) | 1;
            int right = 1 + left;
            update(x, y, val, left, low, mid);
            update(x, y, val, right, 1 + mid, high);
            tree[pos].update2(y, tree[left].query(y, y), tree[right].query(y, y));
        }
    }

    ii query(int &x1, int &y1, int &x2, int &y2, int low = 0, int high = N - 1, int pos = 0){
        if(x2 < low || x1 > high)   return ii(-INF, INF);
        if(low >= x1 && high <= x2)
            return tree[pos].query(y1, y2);
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = 1 + left;
        ii l = query(x1, y1, x2, y2, low, mid, left), r = query(x1, y1, x2, y2, 1 + mid, high, right);
        return ii(max(l.first, r.first), min(l.second, r.second));
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q, a, b, c, d;
    char op;
    cin >> N;
    vector < vector < int > > mat(N, vector < int > (N, 0));
    for(int i = 0 ; i < N ; ++i)    for(int j = 0 ; j < N ; ++j)    cin >> mat[i][j];
    st2d t(mat);
    cin >> q;
    while(q--){
        cin >> op;
        if(op == 'q'){
            cin >> a >> b >> c >> d;
            ii ans = t.query(--a, --b, --c, --d);
            cout << ans.first << " " << ans.second << '\n';
        }
        else{
            cin >> a >> b >> c;
            t.update(--a, --b, c);
        }
    }
    return 0;
}
