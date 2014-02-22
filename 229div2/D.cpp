#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 55;
int n, m, k;
vector <pair<int, int> > a[maxn<<2];
void show(int x, int y) {
	int i = 0, j = 0;
	while(i < x) {
		printf("(%d,%d) ", i+1, j+1);
		i++;
	}
	while(j < y) {
		printf("(%d,%d) ", i+1, j+1);
		j++;
	}
	printf("(%d,%d)\n", x+1, y+1);
}
int main() {
	int i, j;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			a[i+j].push_back(make_pair(i, j));
	int ans = 0, c = 0;
	while(k > 0) {
		if(k > (int)a[c].size()) {
			k -= a[c].size();
			ans += (c+1)*a[c].size();
			c++;
		}
		else {
			ans += (c+1)*k;
			break;
		}
	}
	printf("%d\n", ans);
	for(i = c; i >= 0; i--) {
		if(i == c) {
			for(j = 0; j < k; j++)
				show(a[i][j].first, a[i][j].second);
		}
		else
			for(j = 0; j <(int)a[i].size(); j++)
				show(a[i][j].first, a[i][j].second);
	}
	return 0;
}