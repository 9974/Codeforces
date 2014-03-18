#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int n, m;
const int N = 100005;
int a[5003], b;
bool vis[N];
int p[N], tot;
int g[5003];
set <int> st;
int main() {
	int i, j;
	for(i = 2; i*i < N; i++) if(!vis[i])
		for(j = i*i; j < N; j+=i)
			vis[j] = 1;
	for(i = 2; i < N; i++)
		if(!vis[i]) p[tot++] = i;
	scanf("%d%d", &n, &m);
	g[0] = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		g[i] = __gcd(g[i-1], a[i]);
	}
	while(m--) {
		scanf("%d", &b);
		st.insert(b);
	}
	int ans = 0;
	for(i = 1; i <= n; i++) {
		for(j = 0; j < tot && p[j]*p[j] <= a[i]; j++)
			if(a[i]%p[j] == 0) {
				int t = 0;
				while(a[i]%p[j] == 0) a[i] /= p[j], t++;
				if(st.count(p[j]))
					ans -= t;
				else 
					ans += t;
			}
		if(a[i] != 1) {
			if(st.count(a[i]))
				ans--;
			else ans++;
		}
	}
	for(i = n; i >= 1; i--) {
		int val = 0;
		int w = g[i];
		for(j = 0; j < tot && p[j]*p[j] <= g[i]; j++)
			if(g[i]%p[j] == 0) {
				int t = 0;
				while(g[i]%p[j] == 0) g[i]/=p[j], t++;
				if(st.count(p[j]))
					val -= t;
				else val += t;
			}
		if(g[i] != 1) {
			if(st.count(g[i]))
				val--;
			else 
				val++;
		}
		if(val <= 0) {
			ans -= val*i;
			for(j = i-1; j >= 1; j--)
				g[j] /= w;
		}
	}
	printf("%d\n", ans);
	return 0;
}