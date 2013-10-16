#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
char x[1000005], y[1000005];
int a[1000005][27], b[1000005][27];
int main() {
	int i, j;
	scanf("%I64d%I64d%s%s", &n, &m, x, y);
	int l1 = strlen(x), l2 = strlen(y);
	int d = __gcd(l1, l2);
	for(i = 0; i < l1; i++)
		a[i%d][x[i]-'a']++;
	for(i = 0; i < l2; i++)
		b[i%d][y[i]-'a']++;
	ll ans = 0;
	for(i = 0; i < d; i++)
		for(j = 0; j < 26; j++)
			ans += (ll) a[i][j] * b[i][j];
	printf("%I64d\n", n*l1-m/(l1/d)*ans);
	return 0;
}