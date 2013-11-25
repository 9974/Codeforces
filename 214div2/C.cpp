#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, k;
const int d = 100000;
int dp[200005];
int a[105], b[105];
int main() {
    int i, j;
    cin >> n >> k;
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < n; i++) cin >> b[i], b[i]*=k;
    for(i = 0; i <= 2*d; i++) dp[i] = -1e9;
    dp[d] = 0;
    for(i = 0; i < n; i++) {
        int t = b[i]-a[i];
        //printf("t = %d\n", t);
        if(t > 0) {
            for(j = 2*d; j >= t; j--) if(dp[j-t] != -1e9) {
                dp[j] = max(dp[j], dp[j-t]+a[i]);
            }
        }
        else {
            for(j = 0; j <= 2*d+t; j++) if(dp[j-t] != -1e9) {
                dp[j] = max(dp[j], dp[j-t]+a[i]);
            }
        }
    }
    if(dp[d] == 0) dp[d] = -1;
    cout << dp[d] << endl;
    return 0;
}
