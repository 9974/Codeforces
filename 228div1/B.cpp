#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n = 34, k;
bool ans[1003][1003];
void fix(int x, int y) {
    ans[x][y] = ans[y][x] = 1;
}
void work(int t) {
    if(!t) {
        fix(0, 32);
        return;
    }
    fix(0, n++), fix(0, n++);
    for(int i = 0; i < t-1; i++) {
        fix(n, n-2), fix(n, n-1);
        fix(n+1, n-2), fix(n+1, n-1);
        n += 2;
    }
    fix(n-1, 32-t), fix(n-2, 32-t);
}
int main() {
    int i, j;
    scanf("%d", &k);
    for(i = 1; i < 32; i++) fix(i, i+1);
    for(i = 0; i < 32; i++) if(k>>i&1)
        work(i);
    printf("%d\n", n);
    for(i = 0; i < n; i++,puts(""))
        for(j = 0; j < n; j++)
            printf("%c", ans[i][j] ? 'Y' : 'N');
    return 0;
}