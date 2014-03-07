#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
const int maxn = 100005;
int n, m, k;
int u[maxn], v[maxn];
int f[maxn];
int d[505][505];
int sum[505];
int c[505];
int min(int x, int y) {
    if(x == -1) return y;
    if(y == -1) return x;
    return x < y ? x : y;
}
vector <int> g[maxn];
int val[maxn], belo[maxn];
int id;
void dfs(int u) {
    val[u] = id;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!val[v])
            dfs(v);
    }
}
int main() {
    int i, j;
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(i = 1; i <= k; i++)
        cin >> c[i], sum[i] = sum[i-1]+c[i];
    for(i = 1; i <= k; i++)
        for(j = sum[i-1]+1; j <= sum[i]; j++)
            belo[j] = i;

    for(i = 1; i <= k; i++) {
        for(j = 1; j <= k; j++)
            d[i][j] = -1;
        d[i][i] = 0;
    }
    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        int lx = belo[x];
        int ly = belo[y];
        d[lx][ly] = min(d[lx][ly], w);
        d[ly][lx] = d[lx][ly];
        if(!w) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    id = 1;
    for(i = 1; i <= n; i++) if(!val[i]) {
        dfs(i), id++;
    }
    for(i = 1; i <= k; i++) {
        int cur = val[sum[i-1]+1];
        for(j = sum[i-1]+2; j <= sum[i]; j++)
            if(cur != val[j]) {
                cout << "No\n";
                return 0;
            }
    }
    cout <<"Yes\n";
    int u;
    for(u = 1; u <= k; u++)
        for(i = 1; i <= k; i++) if(d[i][u] != -1)
            for(j = 1; j <= k; j++) if(d[u][j] != -1)
                d[i][j] = min(d[i][j], d[i][u]+d[u][j]);
    for(i = 1; i <= k; i++) d[i][i] = 0;
    for(i = 1; i <= k; i++,cout<<"\n")
        for(j = 1; j <= k; j++)
            cout << d[i][j] <<" ";
    return 0;
}
