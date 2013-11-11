#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
const int maxn = 10004;
bool vis[maxn];
vector <pii > edge[maxn];
vector <int> st;
void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < (int)edge[u].size(); i++) {
        int v =  edge[u][i].first;
        if(!vis[v]) dfs(v);
    }
    st.push_back(u);
}
double sum[maxn], p[maxn], dp[maxn];
int n, m;
int main() {
    int i, j;
    while(~scanf("%d%d", &n, &m) && n && m) {
        for(i = 0; i < n; i++) {
            edge[i].clear();
            sum[i] = p[i] = dp[i] = 0;
        }
        while(m--) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            sum[x] += w;
            edge[x].push_back(mp(y, w));
        }
        st.clear();
        memset(vis, false, sizeof(vis));
        dfs(0);
        for(i = 0; i < (int)st.size(); i++)  {
            int u = st[i];
            for(j = 0; j < (int)edge[u].size(); j++) {
                int v = edge[u][j].first, w = edge[u][j].second;
                dp[u] += dp[v] * w/sum[u];
            }
            if(edge[u].size()) dp[u] += 1.0;
        }

        p[0] = 1.0;
        for(i = st.size()-1; i >= 0; i--) {
            int u = st[i];
            for(j = 0; j < (int)edge[u].size(); j++) {
                int v = edge[u][j].first, w = edge[u][j].second;
                p[v] += p[u] * w/sum[u];
            }
        }

        double ans = dp[0];
        for(int u = 0; u < n; u++) {
            if(edge[u].size() == 1) continue;
            for(j = 0; j < (int)edge[u].size(); j++) {
                int v = edge[u][j].first, w = edge[u][j].second;
                double aug = ((dp[u]-1.0)*sum[u]-w*dp[v])/(sum[u]-w)+1.0-dp[u];
                aug *= p[u];
                ans = max(ans, dp[0]+aug);
            }
        }
        printf("%.7f\n", ans);
    }
    return 0;
}
/*
 4 5
 0 1 2
 0 2 1
 0 3 3
 1 3 1
 2 3 4
 9 8
 0 1 1
 1 2 1
 2 3 1
 0 4 2
 4 5 10
 4 6 1
 6 7 1
 7 8 1
 0 0
 */