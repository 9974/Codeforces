#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int a[103];
int n, m, ans;
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	for(i = 0; i < n-1; i++)
		ans = max(ans, a[i]-a[i+1]-m);
	printf("%d\n", ans);
	return 0;
}