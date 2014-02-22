#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#define lson rt<<1, l, m
#define rson rt<<1|1, m+1, r

const int maxn = 4000000 + 10;
struct segTree {
    ll sum[maxn << 2], add[maxn << 2];

    void down(int rt, int l, int r) {
        if(add[rt]) {
            int m = l + r >> 1;
            add[rt << 1] += add[rt];
            add[rt << 1 | 1] += add[rt];
            sum[rt << 1] += add[rt] * (m - l + 1);
            sum[rt << 1 | 1] += add[rt] * (r - m);
            add[rt] = 0;
        }
    }

    void up(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void update(int rt, int l, int r, int L, int R, ll v) {
        if(L <= l && R >= r) {
            add[rt] += v;
            sum[rt] += v * (r - l + 1);
            return;
        }
        down(rt, l, r);
        int m = (l + r) / 2;
        if(L <= m) update(lson, L, R, v);
        if(R > m) update(rson, L, R, v);
        up(rt);
    }

    ll query(int rt, int l, int r, int L, int R) {
        if(L <= l && R >= r) return sum[rt];
        down(rt, l, r);
        int m = l+r>>1;
        ll ret = 0;
        if(L <= m) ret += query(lson, L, R);
        if(R > m) ret += query(rson, L, R);
        return ret;
    }
} row, col;
int main() {
    int n, m, w;
    int op, x1, y1, x2, y2, v;
    scanf("%d%d%d", &n, &m, &w);
    while (w--) {
        scanf("%d%d%d%d%d", &op, &x1, &y1, &x2, &y2);
        if(op == 0) {
            scanf("%d", &v);
            row.update(1, 1, n, x1, x2, (ll) (y2 - y1 + 1) * v);
            col.update(1, 1, m, y1, y2, (ll) (x2 - x1 + 1) * v);
        } else {
            ll q1 = row.query(1, 1, n, x1, x2);
            ll q2 = col.query(1, 1, m, y1, y2);
            ll q3 = row.query(1, 1, n, 1, x1 - 1) + row.query(1, 1, n, x2 + 1, n);
            ll q4 = col.query(1, 1, m, 1, y1 - 1) + col.query(1, 1, m, y2 + 1, m);
            printf("%lld\n", (q1 + q2 - q3 - q4) / 2);
        }
    }
    return 0;
}