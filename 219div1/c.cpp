#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int n, m, d;
ll F(ll a) {
    return a > 0 ? a : -a;
}
ll dp[2][150005], a[303], b[303], t[303];
ll val[150005];
int pos[150005];
int st, ed, now;
int main() {
    ios::sync_with_stdio(false);
    int i, j;
    cin >> n >> m >> d;
    for(i = 1; i <= m; i++)
        cin  >> a[i] >> b[i] >> t[i];
    for(i = 1; i <= n; i++)
        dp[1][i] = b[1]-F(a[1]-i);
    for(i = 2; i <= m; i++) {
        ll cur = (ll)(t[i]-t[i-1])*d;
        st = ed = 0;
        for(j = 1; j <= n && j <= cur; j++) {
            ll &v = dp[(i-1)&1][j];
            while(st != ed && v >= val[ed-1]) ed--;
            val[ed] = v;
            pos[ed++] = j;
        }
        for(j = 1; j <= n; j++) {
            ll p = j+cur; //int RE了好几次
            if(p <= n) {
                ll &v = dp[(i-1)&1][p];
                while(st != ed && v >= val[ed-1]) ed--;
                val[ed] = v;
                pos[ed++] = p;
            }
            while(st != ed && j-pos[st] > cur)
                st++;
            dp[i&1][j] = val[st]+b[i]-F(a[i]-j);
        }
    }
    ll ans = -1ll<<60;
    for(i = 1; i <= n; i++)
        ans = max(ans, dp[m&1][i]);
    cout << ans << endl;
    return 0;
}
