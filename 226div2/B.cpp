#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
char s[5005];
int ans, pre = -1;
int main() {
	int i, j;
	scanf("%s", s);
	int l = strlen(s);
	for(i = 0; i < l-3; i++)
		if(s[i] =='b' && s[i+1] == 'e' &&
		  s[i+2] == 'a' && s[i+3] == 'r') { 
			ans += (i-pre)*(l-i-3);
			pre = i;
		}
	printf("%d\n", ans);
	return 0;
}