#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf =  1e9;
int n, m;
char s[1004][1004];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char idx[] = {"DIMA"};
int dp[1004][1004];
bool ins[1004][1004];
int dfs(int x, int y, int step) {
    if(~dp[x][y]) return dp[x][y];
    int ret = 0;
    ins[x][y] = true;
    step++; step%=4;
    for(int i = 0; i < 4; i++) {
        int fx = x + dir[i][0];
        int fy = y + dir[i][1];
        if(fx < 0 || fx >= n || fy < 0 || fy >= m)
            continue;
        if(idx[step] == s[fx][fy]) {
            if(ins[fx][fy] || dp[fx][fy] == inf)
                ret = dp[fx][fy] = inf;
            else
                ret = max(ret, dfs(fx, fy, step)+(step==3));
        }
    }
    ins[x][y] = false;
    if(ret >= inf) ret = inf;
    return  dp[x][y] = ret;
}
int ans;
int main() {
    memset(dp, -1, sizeof(dp));
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%s", s[i]);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++) if(s[i][j] == 'D')
            ans = max(ans, dfs(i, j, 0));
    if(ans == inf) puts("Poor Inna!");
    else if(ans == 0) puts("Poor Dima!");
    else printf("%d\n", ans);
    return 0;
}
