#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
const int maxn = 100005;
typedef pair<int, int> pii;
pii p[maxn];
#define x first
#define y second
vector <pii> cp, np;
void out(vector<pii> &t) {
	for(int i = 0; i < (int) t.size(); i++)
		printf("(%d, %d) ", t[i].x, t[i].y);
	puts("~~~~~~~~~");
}
int main() {
	int i, j, k;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p, p+m);
	cp.push_back(make_pair(1, 1));
	int px = 0; i = 0;
	while(i < m) {
		if(px + 1 != p[i].x && cp.size()) {
			int  x = cp[0].x;
			cp.clear();
			cp.push_back(make_pair(x, n));
		}
		j = i;
		while (i < m && p[i].x == p[j].x) i++;
		np.clear();
		int pre = 1, tp = 0, pos;
		for(k = j; k <= i; k++) {
			pos = ((k == i) ? n+1 : p[k].y);
			while(tp < cp.size() && cp[tp].y < pre) tp++;
			if(tp <  cp.size()) {
				int l = max(pre, cp[tp].x);
				if(l < pos)
					np.push_back(make_pair(l, pos-1));
			}
			pre = pos+1;
		}
		//out(np);
		cp = np;
		px = p[i-1].x;
	}
	if(cp.size() &&(px < n || cp.back().y == n)) 
		printf("%d\n", 2 * n - 2);
	else 
		puts("-1");
	return 0;
}