#include <bits/stdc++.h>

using namespace std;

struct data {
    int num, period, i;

    data(int a, int b, int c) : num(a), period(b), i(c) {}

    bool operator >(const data& other) const {
        if(this->period == other.period)
            return this->num > other.num;
        return this->period > other.period;
    }
};

int main() {
    char op[15];
    int pp[10005];
    int q,p,k,cont = 0;
    priority_queue< data, vector < data >, greater < data > > pq;
    while(scanf("%s", op), strcmp(op, "#")) {
        scanf("%d %d", &q, &p);
        pq.push(data(q, p, cont));
        pp[cont++] = p;
    }
    scanf("%d", &k);
    cont = 0;
    while(cont++ < k) {
        printf("%d\n", pq.top().num);
        pq.push(data(pq.top().num, pq.top().period + pp[pq.top().i], pq.top().i));
        pq.pop();
    }
    return 0;
}
