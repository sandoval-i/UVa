#include <bits/stdc++.h>

using namespace std;

vector<int> arr1, arr2;
int lis(vector<int>& arr) {
    vector<int> l;
    for(const auto& u: arr)
        if(l.empty()) l.push_back(u);
        else if(u < l[0]) l[0] = u;
        else if(u > l.back()) l.push_back(u);
        else l[lower_bound(l.begin(), l.end(), u) - l.begin()] = u;
    return l.size();
}


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int tc,n,p,q, caso = 0;
    cin >> tc;
    while(tc--) {
        cin >> n >> p >> q;
        arr1.resize(1 + p);
        arr2.resize(1 + q);
        vector<int> pos1(n*n, -1), pos2(n*n, -1);
        for(int i = 0; i < (int)arr1.size(); ++i) {
            cin >> arr1[i];
            --arr1[i];
            pos1[arr1[i]] = i;
        }
        for(int i = 0; i < (int)arr2.size(); ++i) {
            cin >> arr2[i];
            --arr2[i];
            pos2[arr2[i]] = i;
        }
        vector<int> newarr;
        for(const auto& v: arr2)
            if(pos1[v] != -1)
                newarr.push_back(pos1[v]);
        cout << "Case " << (++caso) << ": " << lis(newarr) << '\n';
    }
    return 0;
}
