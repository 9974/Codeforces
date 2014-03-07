#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
typedef __int64 ll;
int n, m;

ll lsum[22][maxn << 2], rsum[22][maxn << 2];
bool sum[22][maxn << 2];
ll val[22][maxn << 2];
void up(int rt) {
	int i;
	for(i = 0; i < 20; i++) {
		val[i][rt] = val[i][rt<<1] + val[i][rt<<1|1] + lsum[i][rt<<1]*rsum[i][rt<<1|1];
		sum[i][rt] = sum[i][rt<<1]&sum[i][rt<<1|1];
		lsum[i][rt] = lsum[i][rt<<1|1] + sum[i][rt<<1|1] * lsum[i][rt<<1];
		rsum[i][rt] = rsum[i][rt<<1] + sum[i][rt<<1] * rsum[i][rt<<1|1];
	}
}
void build(int l, int r, int rt) {
	int i;
	if(l == r) {
		int v;
		scanf("%d", &v);
		for(i = 0; i < 20; i++)
			lsum[i][rt] = rsum[i][rt] = val[i][rt] = sum[i][rt] = v >> i & 1;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	up(rt);
}
void update(int p, int v, int l, int r, int rt) {
	int i;
	if(l == r) {
		for(i = 0; i < 20; i++)
			lsum[i][rt] = rsum[i][rt] = val[i][rt] = sum[i][rt] = v >> i & 1;
		return;
	}
	int m = (l + r) >> 1;
	if(p <= m) update(p, v, lson);
	else update(p, v, rson);
	up(rt);
}

ll getVal(int p, int v) {
	update(p, v, 1, n, 1);
	ll ret = 0;
	for(int i = 0; i < 20; i++)
		ret += (1ll << i) * val[i][1];
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	while(m--) {
		int p, v;
		scanf("%d%d", &p, &v);
		printf("%I64d\n", getVal(p, v));
	}
	return 0;
}

