#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 300005;
const ll mod = 1e9+7;
int n;
vector <int> g[maxn];
int dfn[maxn], sz[maxn], tot;
int dep[maxn];
void dfs(int u, int fa) {
    sz[u] = 1, dfn[u] = ++tot;
    dep[u] = dep[fa] + 1;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int m;
inline void fix(int &x, int y) {
    x += y;
    if(x >= mod ) x-= mod;
}
struct bitTree {
    int c[maxn];
    void add(int x, int v) {
        if(!x) return;
        while(x <= n) {
            fix(c[x], v);
            x += x&-x;
        }
    }
    int sum(int x) {
        int ret = 0;
        while(x > 0) {
            fix(ret, c[x]);
            x -= x&-x;
        }
        return ret;
    }
}col, val;
int main() {
    int i, j;
    ios::sync_with_stdio(0);
    cin >> n;
    for(i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1, 0);
    cin >> m;
    int op;
    ll v, k, x;
    while(m--) {
        cin >> op >> v;
        if(op == 1) {
            cin >> x >> k;
            int l = dfn[v], r = dfn[v]+sz[v]-1;
            int tmp = (x+(ll)dep[v]*k%mod)%mod;
            val.add(l, tmp);
            val.add(r+1, (-tmp+mod)%mod);
            col.add(l, k);
            col.add(r+1, (-k+mod)%mod);

        } else {
            cout << (val.sum(dfn[v])-
                    (ll)dep[v]*col.sum(dfn[v])%mod+mod)%mod << endl;

        }
    }
    return 0;
}