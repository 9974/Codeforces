#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Edge {
    int v, w, next;
} edge[maxn<<1];
int head[maxn], E;
void add(int s, int t, int w) {
    edge[E] = (Edge ) { t, w, head[s] };
    head[s] = E++;
}
void init() {
    memset(head, -1, sizeof(head));
    E = 0;
}
int pos;
bool vis[maxn];
int pre[maxn];
int dis[maxn];
bool mark[maxn];
int sum[maxn];
int all;
void dfs(int u, int fa) {
    vis[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa) continue;
        if (!vis[v]) {
            pre[v] = u;
            dis[v] = dis[u] + edge[i].w;
            dfs(v, u);
        } else if (pos == -1) {
            pos = v;
            mark[v] = true;
            sum[v] = 0;
            v = u;
            all = dis[v] - dis[pos] + edge[i].w;
            while (!mark[v]) {
                mark[v] = true;
                sum[v] = dis[v] - dis[pos];
                v = pre[v];
            }
        }
    }
}
int belo[maxn], rt;
int p[maxn][20], dep[maxn];
void cal(int u, int fa) {
    belo[u] = rt;
    dep[u] = dep[fa] + 1;
    p[u][0] = fa;
    for (int i = 1; i < 20; i++)
        p[u][i] = p[p[u][i - 1]][i - 1];
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa || mark[v])
            continue;
        dis[v] = min(dis[v], dis[u] + edge[i].w);
        cal(v, u);
    }
}
int lca(int a, int b) {
    if (dep[a] > dep[b])
        a ^= b, b ^= a, a ^= b;
    int i;
    if (dep[a] < dep[b]) {
        int k = dep[b] - dep[a];
        for (i = 0; i < 20; i++)
            if (k & (1 << i))
                b = p[b][i];
    }
    if (a != b) {
        for (i = 19; i >= 0; i--)
            if (p[a][i] != p[b][i])
                a = p[a][i], b = p[b][i];
        a = p[a][0], b = p[b][0];
    }
    return a;
}
int n;
inline int F(int x) {
    return x > 0 ? x : -x;
}
int main() {
    int i;
    while (~scanf("%d", &n) && n) {
        init();
        for (i = 1; i <= n; i++) {
            int x, y, w;

            scanf("%d%d%d", &x, &y, &w);x++; y++;
            add(x, y, w);
            add(y, x, w);
        }
        pos = -1;
        memset(vis, 0, sizeof(vis));
        memset(mark, 0, sizeof(mark));
        for(i = 1; i <= n; i++)
            dis[i] = 1e9;
        dfs(1, 0);
        for (i = 1; i <= n; i++)
            if (mark[i]) {
                dis[i] = 0;
                rt = i;
                cal(i, 0);
            }
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            x++; y++;
            if (~pos) {
                if (mark[x] && mark[y]) {
                    int t =  F(sum[belo[y]] - sum[belo[x]]);
                    printf("%d\n", min(t, all-t));
                }
                else if (belo[x] == belo[y]) {
                    int t = lca(x, y);
                    printf("%d\n", dis[y] + dis[x] - 2 * dis[t]);
                } else {
                    int t = F(sum[belo[x]] - sum[belo[y]]);
                    printf("%d\n", dis[x] + dis[y]+min(all-t, t));
                }
            } else {
                int t = lca(x, y);
                printf("%d\n", dis[y] + dis[x] - 2 * dis[t]);
            }
        }
    }
    return 0;
}
/*
 7
 0 1 2
 0 2 3
 1 3 2
 2 3 8
 2 4 3
 3 5 1
 1 6 7
 3
 4 5
 0 6
 1 2
 0
 */