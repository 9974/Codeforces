#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int a[3003], b[3003];
bool vis[3003];
int ans;
int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(b, b+m);
    sort(a, a+n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) if(!vis[j] && b[j] >= a[i]) break;
        if(j == m) ans++;
        else vis[j] = 1;
    }
    printf("%d\n", ans);
}