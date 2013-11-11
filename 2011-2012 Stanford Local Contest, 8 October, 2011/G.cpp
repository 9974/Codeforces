#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1005;
typedef pair<int, int> pii;
#define mp make_pair
vector <pii> edge[maxn];
int n, m, q, dis[maxn];
char str[10];
bool mark[maxn], vis[maxn];
bool dfs(int u) {
	mark[u] = vis[u] = true;
	for(int i = 0; i < (int)edge[u].size(); i++) {
		int v = edge[u][i].first, w = edge[u][i].second;
		if(dis[v] > dis[u] + w) {
			dis[v] = dis[u] + w;
			if(mark[v] || !dfs(v)) return false;
		}

	}
	mark[u] = 0;
	return true;
}
bool judge() {
	int i;
	memset(vis, false, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	memset(mark, false, sizeof(mark));
	for(i = 1; i <= n + m; i++) {
		if(!vis[i]) {
			if(dfs(i) == false) return false;
		}
	}
	return true;
}
int main() {
	int i, a, b, c;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		if(!n && !m && !q) break;
		for(i = 1; i <= n+m; i++) edge[i].clear();
		for(i = 0; i < q; i++) {
			scanf("%d%d%s%d", &a, &b, str, &c);
			if(str[0] == '<') edge[n + b].push_back(mp(a, c));
			else edge[a].push_back(mp(n+b, -c));
		}
		if(!judge()) puts("Impossible");
		else puts("Possible");
	}
	return 0;
}
