#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int N = 1003;
const int mod = 1e9+7;
typedef long long ll;
ll dp[N][N], C[N][N], A[N];
ll ans[N][N];
int n, k;
void add(ll &a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
}
int main() {
    int i, j;
    A[0] = 1;
    for(i = 1; i < N; i++)
        A[i] = A[i-1]*i%mod;
    for(i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(j = 1; j < i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
    }
    dp[0][0] = 1;
    for(i = 1; i < N; i++)
        for(j = 50; j >= 0; j--)
            for(k = N-i-1; k >= 0; k--)
                add(dp[j+1][k+i], dp[j][k]);
    for(i = 1; i < N; i++)
        for(j = 1; j <= i && j <= 50; j++) {
            ll &val = ans[i][j];
            for(k = 1; k <= i; k++) {
                int t = i-k;
                add(val, dp[j][k]*C[j+t][t]%mod);
            }
            val = val*A[j]%mod;
        }
    int m; scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &n, &k);
        printf("%I64d\n", ans[n][k]);
    }
    return 0;
}
