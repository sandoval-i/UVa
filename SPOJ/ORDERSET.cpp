#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;
    int Q, k;
    char c;
    scanf("%d", &Q);
    while(Q--) {
        scanf(" %c %d", &c, &k);
        if(c == 'I') s.insert(k);
        else if(c == 'D') s.erase(k);
        else if(c == 'C') printf("%d\n", s.order_of_key(k));
        else {
            if(k > (int)s.size()) puts("invalid");
            else printf("%d\n", *s.find_by_order(k - 1));
        }
    }
    return 0;
}
