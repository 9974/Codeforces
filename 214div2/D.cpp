#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int u, v, l, r;
    void in() {
        scanf("%d%d%d%d", &u, &v, &l, &r);
    }
    void out() {
        cerr << u << " " << " " << v << " " << l << " " << r << "~~~~" <<endl;
    }
}p[3003];
int n, m;
bool cmp(node a, node b) {
    return a.r > b.r;
}
int f[3003];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++) p[i].in();
    int ans = 0;
    sort(p, p+m, cmp);
    for(i = 0; i < m; i++) {
        for(j = 1; j <= n; j++) f[j] = j;
        for(j = 0; j < m; j++) if(p[j].l <= p[i].l && p[j].r >= p[i].l) {
            int u = find(p[j].u), v = find(p[j].v);
            if(u != v) f[u] = v;
            if(find(1) == find(n)) {
                ans = max(ans, p[j].r-p[i].l+1);
                break;
            }
        }
    }
    if(!ans) puts("Nice work, Dima!");
    else printf("%d\n", ans);
    return 0;
}
