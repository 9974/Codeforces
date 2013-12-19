#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = (int) 1e9;
int n, m, x, y, a, b;
int f(int x1, int y1) {
	if(x1 % a == 0 && y1 % b == 0 && ((x1 / a) % 2 == (y1 / b) % 2)) {
		int res = max(x1 / a, y1 / b);
		if((a >= n || b >= m) && res > 0) //注意特判
		return inf;
		else return res;
	}
	return inf;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> x >> y >> a >> b;
	int ans = f(x - 1, y - 1);
	ans = min(ans, f(x - 1, m - y));
	ans = min(ans, f(n - x, m - y));
	ans = min(ans, f(n - x, y - 1));
	if(ans == inf) cout << "Poor Inna and pony!" << endl;
	else cout << ans << endl;
}

