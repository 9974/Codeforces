#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, k, s;
int a;
int b[100005];
inline int f(int x) {
    return x > 0 ? x : -x;
}
int Map[2002][2002];
int l[2002][11], r[2002][11];
int mx[11], mi[11];
int main() {
    ios::sync_with_stdio(false);
    int i, j, u, v;
    cin >> n >> m >> k >> s;
    memset(l, inf, sizeof(l));
    memset(r, -1, sizeof(r));
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> a;a--;
            l[i][a] = min(l[i][a], j);
            r[i][a] = max(r[i][a], j);
        }
    }
    memset(mx, -1, sizeof(mx));
    memset(mi, inf, sizeof(mi));
    for(i = 0; i < n; i++) {
        for(j = 0; j < k; j++) {
            mx[j] = max(mx[j], -i+r[i][j]);
            mi[j] = min(mi[j], i+l[i][j]);
        }
        for(j = 0; j < k; j++)
            for(u = 0; u < k; u++) {
                Map[j][u] = Map[u][j] = max(Map[j][u], i-l[i][j]+mx[u]);
                Map[j][u] = Map[u][j] = max(Map[j][u], i+r[i][j]-mi[u]);
            }
    }
    for(i = 0; i < s; i++)
        cin >> b[i], b[i]--;
    int ans = 0;
    for(i = 1; i < s; i++)
        ans = max(ans, Map[b[i - 1]][b[i]]);
    cout << ans << endl;
    return 0;
}
