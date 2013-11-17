#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char Map[11][11];
int vis[11][11];
int dir[4][2] = {{-2, 2}, {-2, -2}, {2, 2}, {2, -2}};
struct node {
	int x, y, s;
};
void bfs(int x, int y) {
	queue <node> q;
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 2;
	q.push((node){x, y, 2});
	while(!q.empty()) {
		node u = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			node v = u;
			v.x += dir[i][0];
			v.y += dir[i][1];
			v.s++;
			if(v.x >= 0 && v.x < 8 && v.y >= 0 && v.y < 8  && (!vis[v.x][v.y])) {
				vis[v.x][v.y] = v.s;
				q.push(v);
			}
		}
	}
}
int main() {
    int i, j, cas;
    scanf("%d", &cas);
    while(cas--) {
        for(i = 0; i < 8; i++)
            scanf("%s", Map[i]);
        int cnt = 1;
        int x, y;
        for(i = 0; i < 8; i++)
            for(j = 0; j < 8; j++)
                if(Map[i][j] == 'K') {
                    if(cnt == 1) {
                    	cnt = 0;
                    	bfs(i, j);
                    }
                    else {
                    	x = i, y = j;
                    }
                }
       // printf("%d %d\n", x, y);
        if(vis[x][y]%2==0 && vis[x][y])
        	puts("YES");
        else puts("NO");
    }
    return 0;
}