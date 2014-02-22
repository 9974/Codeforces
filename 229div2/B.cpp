#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll a[maxn], b[maxn];
int main() {
    ios::sync_with_stdio(0);
    int i, j, n;
    cin >> n;
    ll ans = 0;
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < n; i++) cin >> b[i];
    for(i = 0; i < n; i++) {
        if(a[i]+a[i] >= b[i] && b[i] >= 2) {
            ll t = b[i]/2;
            ans += (b[i]-t)*t;
        }
        else ans--;
    }
    cout << ans << endl;
    return 0;
}