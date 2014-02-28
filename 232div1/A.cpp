#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
typedef long long ll;
const ll mod = 1e9+7;
ll a;
const ll N = 505 * 33;
ll f[N];
map <ll, int> cnt;
map <ll, int>::iterator it;
ll Pow(ll p, ll n) {
    ll ret = 1;
    while(n > 0) {
        if(n&1) ret = ret*p%mod;
        p = p *p %mod;
        n >>= 1;
    }
    return ret;
}
ll C(ll n, ll m) {
    return f[n]*Pow(f[n-m]*f[m]%mod, mod-2)%mod;
}
int main() {
    ios::sync_with_stdio(0);
    int i, j;
    f[0] = 1;
    for(i = 1; i < N; i++)
        f[i] = f[i-1]*i%mod;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        for(j = 2; j*j <=a; j++) if(a%j==0) {
            int t = 0;
            while(a%j==0) a/= j, t++;
            cnt[j] += t;
        }
        if(a!= 1) cnt[a]++;
    }
    ll ans = 1;
    for(it = cnt.begin(); it != cnt.end(); it++)
        ans  = ans *C(n+it->second-1,it->second)%mod;
    cout << ans << endl;
    return 0;
}
