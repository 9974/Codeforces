#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, q;
char s[55][55];
int r[55][55], pre[55][55][55]; 
// r[i][j]表示点(i,j)向上能延伸到最远的0的位置
// pre[i][j][k]表示以点(i,j)为右下角，高度为k   能向左延伸到的最远0的位置
int dp[55][55][55][55]; //dp[i][j][k][u] 答案
int main() {
    int i, j, k, u;
    memset(r, -1, sizeof(r));
    scanf("%d%d%d", &n, &m, &q);
    getchar();
    for(i = 1; i <= n; i++)
          gets(s[i]+1);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(s[i][j] == '0') {
                if(s[i-1][j] == '0') r[i][j] = r[i-1][j];
                else r[i][j] = i; 
            }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) if(r[i][j] != -1)
            for(k = 1; k <= i-r[i][j]+1; k++) {
                for(u = j; u >= 1; u--)
                    if(r[i][u] == -1 || i-r[i][u]+1 < k) break;
                u++;
                pre[i][j][k] = u;
            }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            for(k = i; k <= n; k++)
                for(u = j; u <= m; u++) {
                    dp[i][j][k][u] = dp[i][j][k-1][u] + dp[i][j][k][u-1]
                    - dp[i][j][k-1][u-1];
                    if(r[k][u]== -1) continue;
                    for(int w = 1; w <= k-r[k][u]+1 && w <= (k-i+1); w++) {
                        dp[i][j][k][u] += u-max(pre[k][u][w], j)+1;
                    }
                }
    while(q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x1][y1][x2][y2]);
    }
    return 0;
}
