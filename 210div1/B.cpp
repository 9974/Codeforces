#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int inf = 1e9;
typedef long long ll;
int n, k;
int a[2002], dp[2002];
int f(int x) {
    return x > 0 ? x : -x;
}
inline bool DP(ll m) {
    int i, j;
    for(i = 1; i <= n; i++)
        dp[i] = i - 1;
    for(i = 2; i <= n; i++) {
        for(j = 1; j < i; j++)
            if((f(a[i] - a[j])+(i-j-1))/(i-j) <= m)
                dp[i] = min(dp[i], dp[j] + (i - j - 1));
        dp[n] = min(dp[n], dp[i]+n-i);
    }
    return dp[n] <= k;
}
int main() {
    int i;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = -1;
    ll l = 0, r = 2*1e9;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(DP(m)) {
            ans = m;
            r = m-1;
        }
        else l = m + 1;
    }
    printf("%d\n", ans);
    return 0;
}
/*
4 1
-1000000000 -1000000000 1000000000 1000000000
 */