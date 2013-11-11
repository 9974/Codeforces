#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
ll dp[1004];
int n;
int main() {
    dp[1] = 2;
    for(int i = 2; i <= 1000; i++)
        dp[i] = dp[i-1]*4%mod*(2*i-1)%mod;
    while(cin >> n && n)
        cout << dp[n] << endl;
    return 0;
}