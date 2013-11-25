#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = min(a, b), y = min(c, d);
		if(x + y <= n) {
			cout << i << " " << x << " " << n - x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
