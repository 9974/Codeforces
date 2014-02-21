#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef __int64 ll;
int n, sx, sy, dx, dy;
ll t;
void mult(int a[6][6], int b[6][6]) {
	int c[6][6] = {0};
	int i, j, k;
	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			for(k = 0; k < 6; k++) {
				c[i][j] += (ll)a[i][k] * b[k][j] % n;
				c[i][j] %= n;
			}
	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			a[i][j] = c[i][j];
}
int tp[6];
int a[6][6] = {
	2, 1, 1, 1, 0, 0,
	1, 2, 1, 1, 0, 0,
	1, 0, 1, 0, 0, 0,
	0, 1, 0, 1, 0, 0,
	1, 1, 1, 1, 1, 0,
	2, 2, 2, 2, 1, 1
};
int e[6][6];
void work() {
	int i, j;
	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			e[i][j] = (i==j);
	while(t) {
		if(t&1) mult(e, a);
		mult(a, a);
		t >>= 1;
	}
	tp[0] = sx, tp[1] = sy;
	tp[2] = dx, tp[3] = dy;
	tp[4] = 0, tp[5] = 1;
	int x = 0, y = 0;
	for(int i = 0; i < 6; i++) {
		x += (ll)tp[i] * e[i][0]%n;
		x %= n;
		y += (ll)tp[i] * e[i][1]%n;
		y %= n;
	}
	x++, y++;
	printf("%d %d\n", x, y);
}
int main() {
	scanf("%d%d%d%d%d%I64d", &n, &sx, &sy, &dx, &dy, &t);
	dx %= n, dy %= n, dx = (dx+n)%n, dy = (dy+n)%n;
	if(!t) {
		printf("%d %d\n", sx, sy);
		return 0;
	}
	sx--, sy--;
	work();
	return 0;
}