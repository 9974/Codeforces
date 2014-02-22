#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
bool c[maxn], r[maxn];
int main() {
    int i, j, n;
    scanf("%d", &n);
    while(n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        c[x] = 1;
        r[y] = 1;
    }
    int a = 0, b = 0;
    for(i = 0; i <= 100; i++) {
        if(c[i]) a++;
        if(r[i]) b++;
    }
    printf("%d\n", min(a, b));
    return 0;
}