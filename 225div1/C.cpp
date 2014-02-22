#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
typedef long long ll;
const int maxn = 200005;
vector<int> g[maxn];
int tot, lx[maxn], rx[maxn];
int col[maxn];
void dfs(int u, int fa) {
    col[u] = col[fa]^1;
    lx[u] = ++tot;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v, u);
    }
    rx[u] = tot;
    //printf("%d %d %d %d\n", u, col[u], lx[u], rx[u]);
}
int sum[maxn << 2], add[maxn << 2];
void down(int l, int r, int rt) {
    if(add[rt]) {
        int m = (l + r) >> 1;
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] +=  add[rt];
        sum[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}
void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        add[rt] += v;
        sum[rt] += v;
        return;
    }
    down(l, r, rt);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
}
int query(int p, int l, int r, int rt) {
    if(l == r) return sum[rt];
    down(l, r, rt);
    int m = (l + r) >> 1;
    if(p <= m) return query(p, lson);
    else return query(p, rson);
}
int n, m;
int val[maxn];
int main() {
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for(i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    while (m--) {
        int op, x, v;
        scanf("%d%d", &op, &x);
        if(op == 1) {
            scanf("%d", &v);
            if(!col[x]) v = -v;
            update(lx[x], rx[x], v, 1, n, 1);
        } else {
            int ans = query(lx[x], 1, n, 1);
            if(!col[x]) ans = -ans;
            printf("%d\n", ans+val[x]);
        }
    }
    return 0;
}
/*
 5 5
 1 2 1 1 2
 1 2
 1 3
 2 4
 2 5
 1 2 3
 1 1 2
 2 1
 2 2
 2 4
 */