
By 2011330300713, contest: Codeforces Round #210 (Div. 1), problem: (C) Levko and Strings, Accepted, #
 #include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
int n, m;
char s[2003];
int dp[2003][2003][2];
int main() {
    int i, j, t;
    scanf("%d%d%s", &n, &m, s+1);
    for(i = 1; i <= n; i++)
        s[i] ^= 0x60;
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1])%mod;
            dp[i][j][0] = (ll)(dp[i-1][j][0] + dp[i-1][j][1])%mod*(s[i]-1)%mod;
            //int r = n-i+1;
            int c = n-i+1, r = c;
            for(t = i-1; j-r >= 0 && t >= 0; t--, r+=c) {
                dp[i][j][0] += (ll)dp[t][j-r][0] *(26-s[i])%mod;
                dp[i][j][0] %= mod;
            }
        }
    }
    //for(i = 1; i <= n; i++)
    //  for(j = 0; j <= m; j++)
    //      printf("i = %d j = %d ~~~~%d %d\n" , i, j, dp[i][j][0], dp[i][j][1]);
    printf("%d\n", (dp[n][m][0] + dp[n][m][1])%mod);
    return 0;
}