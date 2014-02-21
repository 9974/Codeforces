#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000001;
bool vis[maxn];
int a[maxn], ans[maxn];
int main() {
	int i, j, n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(i = 2; i < maxn; i++) if(!vis[i])
		for(j = i; j < maxn; j += i) {
			ans[i] += a[j];
			vis[j] = 1;
		}
	for(i = 1; i < maxn; i++)
		ans[i] += ans[i-1];
	scanf("%d", &n);
	while(n--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(l >= maxn) l = maxn-1;
		if(r >= maxn) r = maxn-1;
		printf("%d\n", ans[r]-ans[l-1]);
	}
	return 0;
}