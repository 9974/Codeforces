#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n;
int a[500005];
bool ok(int m) {
    int x = 0, y = n-m;
    for(int i = 0; i < m; i++) {
        if(a[x]*2 > a[y]) return 0;
        x++; y++;
    }
    return 1;
}
int main() {
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int l = 0, r = n/2;
    int ans = 0;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(ok(m)) {
            l = m+1;
            ans = m;
        }
        else  r = m-1;
    }
    printf("%d\n", n-ans);
    return 0;
}
