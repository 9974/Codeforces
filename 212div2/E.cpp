#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 66;
struct MinCostMaxFlow {
    struct Edge {
        int u, v, c, w, next;
    }edge[100005];
    int head[maxn], E;
    void init() {
        memset(head, -1, sizeof(head));
        E = 0;
    }
    void add(int s, int t, int c, int w) {
        edge[E] = (Edge) {s, t, c, w, head[s]};
        head[s] = E++;
        edge[E] = (Edge) {t, s, 0, -w, head[t]};
        head[t] = E++;
    }
    bool vis[maxn];
    int dis[maxn], pre[maxn];
    int flow, cost;
    void mcmf(int s, int t, int n, int lim = inf) {
        int i, u, v, aug;
        flow = cost = 0;
        queue <int> q;
        while(true) {
            memset(vis, false, sizeof(vis));
            memset(dis, inf, sizeof(dis));
            memset(pre, -1, sizeof(pre));
            q.push(s), vis[s] = true, dis[s] = 0;
            while(!q.empty()) {
                u = q.front(), q.pop(); vis[u] = false;
                for(i = head[u]; ~i; i = edge[i].next) {
                    v = edge[i].v;
                    if(edge[i].c && dis[v] > edge[i].w + dis[u]) {
                        pre[v] = i;
                        dis[v] = edge[i].w + dis[u];
                        if(!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            if(dis[t] == inf) break;
            aug = (dis[t] == 0) ? inf : lim/dis[t];
            for(i = pre[t]; ~i; i = pre[edge[i].u])
                aug = min(aug, edge[i].c);
            if(!aug) break;
            for(i = pre[t]; ~i; i = pre[edge[i].u]) {
                edge[i].c -= aug;
                edge[i^1].c += aug;
            }
            lim -= aug * dis[t];
            cost += aug*dis[t];
            flow += aug;
        }
    }
} g;
int main() {
    int i, j, n, k;
    g.init();
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            int tp;
            scanf("%d", &tp);
            if(tp) {
                g.add(i, j, tp, 0);
                g.add(i, j, k, 1);
            }
        }
    g.mcmf(0, n-1, n, k);
    printf("%d\n", g.flow);
    return 0;
}