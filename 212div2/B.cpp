#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int a[3003];
int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++)
        scanf("%d", &a[i]);
    sort(a, a + m);
    for(i = 1; i < m-1; i++)
        if(a[i-1] == a[i]-1 && a[i]+1 == a[i+1]) {
            puts("NO");
            return 0;
        }
    if(a[0] == 1 || a[m-1] == n) puts("NO");
    else puts("YES");
    return 0;
}