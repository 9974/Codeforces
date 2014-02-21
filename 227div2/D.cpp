#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
bool mp[505][505];
vector <int> g[505];
int pre[505];
bool vis[505];
bool dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        if(pre[v] == -1 || dfs(pre[v])) {
            pre[v] = u;
            return 1;
        }
    }
    return 0;
}
int ans, tp;
int main() {
    int i, j, k;
    scanf("%d%d", &n, &m);
    int x, y;
    for(i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        mp[x][y] = 1;
    }
    ans = 1e9;
    for(i = 1; i <= n; i++) {
        tp = 0;
        int tot = 0;
        for(j = 1; j <= n; j++)
            g[j].clear();
        for(j = 1; j <= n; j++)
            for(k = 1; k <= n; k++)
                if(j==i||k==i) {
                    if(!mp[j][k]) tp++;
                    else tot++;
                }
                else if(mp[j][k])
                    g[j].push_back(k);
        int cnt = 0;
        memset(pre, -1, sizeof(pre));
        for(j = 1; j <= n; j++) {
            memset(vis, false, sizeof(vis));
            cnt += dfs(j);
        }
        ans = min(ans, tp+m+n-2*cnt-tot-1);
    }
    printf("%d\n", ans);
    return 0;
}