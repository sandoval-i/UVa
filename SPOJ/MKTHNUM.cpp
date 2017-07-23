#include <bits/stdc++.h>
using namespace std;
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
typedef vector<int>::iterator it;

struct wt {
    struct node {
        int l,r;
        node* left, *right;
        vector<int> mapl;
        vector<int> mapr;
        node() {left = right = NULL;}
    };
    node* root;
    wt(vector<int> arr) {
        root = build(arr, *min_element(arr.begin(), arr.end()), *max_element(arr.begin(), arr.end()), arr.begin(), arr.end());
    }
    int kth(int i, int j, int k, node*& curr) {
        if(!curr->left) return curr->l;
        int c = curr->mapl[j] - (i ? curr->mapl[i - 1] : 0);
        return k <= c ? kth(i ? curr->mapl[i - 1] : 0, curr->mapl[j] - 1, k, curr->left) : kth(i ? curr->mapr[i - 1] : 0, curr->mapr[j] - 1, k - c, curr->right);
    }
    int kth(int i, int j, int k) {
        return kth(i, j, k, this->root);
    }
    node* build(vector<int>& arr, int mini, int maxi, it s, it e) {
        node *n = new node;
        int mid = (mini + maxi) >> 1;
        n->l = mini;
        n->r = maxi;
        n->mapl.resize(e - s);
        n->mapr.resize(e - s);
        if(mini != maxi) {
            int i = 0;
            for(it u = s; u != e; ++u) {
                if(*u <= mid) {
                    n->mapl[i] = i ? 1 + n->mapl[i - 1] : 1;
                    n->mapr[i] = i ? n->mapr[i - 1] : 0;
                } else {
                    n->mapr[i] = i ? 1 + n->mapr[i - 1] : 1;
                    n->mapl[i] = i ? n->mapl[i - 1] : 0;
                }
                ++i;
            }
            it m = stable_partition(s, e, [=](int k){return k<=mid;});
            n->left = build(arr, mini, mid, s, m);
            n->right = build(arr, 1 + mid, maxi, m, e);
        }
        return n;
    }
};

int main() {
    int n,m;
    int i,j,k;
    scanf("%d %d", &n, &m);
    vector<int> arr(n), arr2(n);
    unordered_map<int,int> to_id,to_num;
    int cons = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }
    sort(arr2.begin(), arr2.end());
    for(const auto& u: arr2)
        if(!to_id.count(u)) {
            to_id.insert(pair<int,int>(u, cons));
            to_num.insert(pair<int,int>(cons++, u));
        }
    for(int i = 0; i < (int)arr.size(); ++i)
        arr[i] = to_id[arr[i]];
    wt t(arr);
    while(m--) {
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", to_num[t.kth(i - 1, j - 1, k)]);
    }
    return 0;
}
