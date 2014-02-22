#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
int dp[1003][20004];
int a, ans;
int main() {
    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &a);
        dp[i][10000-a] += 1; dp[i][10000-a]%=mod;
        dp[i][10000+a] += 1; dp[i][10000+a]%=mod;
        for(j = 0; j <= 20000; j++) if(dp[i-1][j]){
            if(j+a <= 20000) {
                    dp[i][j+a] += dp[i-1][j];
                    dp[i][j+a] %= mod;
            }
            if(j-a >= 0) {
                dp[i][j-a] += dp[i-1][j];
                dp[i][j-a] %= mod;
            }
        }
        ans += dp[i][10000];
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}