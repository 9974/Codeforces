#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1000006;
const int mod = 1e9+7;
ll f[maxn];
int n;

ll c[maxn];
void fix(ll &x, ll y) {
	x += y;
	if(x >= mod) x -= mod;
}
void add(int x) {
	while(x <= n) {
		c[x]++;
		x += x&-x;
	}
}
ll sum(int x) {
	ll ret = 0;
	while(x > 0) {
		fix(ret, c[x]);
		x -= x&-x;
	}
	return ret;
}
ll pre, ans;
ll inv4;
void get() {
	int n = mod-2;
	ll p = 4;
	inv4 = 1;
	while(n > 0) {
		if(n&1) inv4 = inv4*p%mod;
		p = p*p%mod;
		n >>=1;
	}
}
int main() {
	ios::sync_with_stdio(0);
	int i, j;
	f[0] = 1;
	for(i = 1; i < maxn; i++)
		f[i] = f[i-1]*i%mod;
	get();
	cin >> n;
	for(i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		ll val = a-1-sum(a-1);
		ll x = n-i;
		fix(ans, val*(val-1)/2%mod*f[x]%mod);
		fix(ans, f[x]*(x-1)%mod*x%mod*inv4%mod*val%mod);
		fix(ans, f[x]*val%mod*pre%mod);
		fix(pre, val);
		add(a);
	}
	fix(ans, pre);
	cout << ans << endl;
	return 0;
}