#include <cstdio>
#include <iostream>

using namespace std;

int a[5555];
int dp[5555][5555];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = i - 1; j >= 0; j--)
			dp[i][j] = dp[i][j + 1] + (a[j] > a[i]);
		for(int j = i + 1; j < n; j++)
			dp[i][j] = dp[i][j - 1] + (a[j] > a[i]);
	}
	int x = 0, ans = 0, res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++)
			ans += (a[j] > a[i]);
	}
	x = ans;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			int tmp = x - 2 * dp[j][i + 1] + 2 * dp[i][j - 1];
			if(a[i] > a[j]) tmp--;
			else tmp++;
			if(ans == tmp) res++;
			else if(tmp < ans) ans = tmp, res = 1;
		}
	cout << ans << " " << res << endl;
}