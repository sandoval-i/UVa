#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> ii;
vector<int> arr;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int inversions() {
    int ans = 0, t = 0;
    ordered_set s;
    for(auto x : arr) s.insert(ii(x, t++));
    for(auto x : arr) {
        s.erase(s.lower_bound(ii(x, 0)));
        ans += s.order_of_key(ii(x, 0));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while(cin >> N) {
        arr.resize(N);
        for(auto& x: arr) cin >> x;
        cout << "Minimum exchange operations : " << inversions() << '\n';
    }
    return 0;
}
