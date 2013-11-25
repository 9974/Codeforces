#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int ans, pos;
int a[100005];
int main() {
	int i;
	cin >> n >> k;
	ans = 1e9;
	for(i = 0; i < n; i++) cin >> a[i];
	for(i = 0; i < k; i++) {
		int sum = 0;
		int ct = n/k, j = i;
		while(ct--) {
			sum += a[j];
			j = (j+k)%n;
		}
		if(sum < ans) {
			ans = sum;
			pos = i;
		}
	}
	cout << pos+1 << endl;
	return 0;
}
