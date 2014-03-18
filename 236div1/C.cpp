#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int N = 2003;
int g[N][N];
int dfn[N], low[N];
bool ins[N];
int n, tot, ctot;
int sta[N], top;
void dfs(int u) {
	ins[u] = 1;
	sta[top++] = u;
	low[u] = dfn[u] = ++tot;
	for(int i = 0; i < n; i++) if(u != i&& g[u][i]) {
		if(!dfn[i]) {
			dfs(i);
			low[u] = min(low[u], low[i]);
		}else if(ins[i])
			low[u] = min(low[u], dfn[i]);
	}
	int v;
	if(low[u] == dfn[u]) {
		do {
			v = sta[--top];
			ins[v] = false;
		}while(u != v);
		ctot++;
	}
}
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	for(i = 0; i < n; i++) if(!dfn[i]){
		dfs(i);
	}
	puts(ctot == 1 ? "YES" :"NO");
	return 0;
}
