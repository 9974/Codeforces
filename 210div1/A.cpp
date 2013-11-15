#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 1e8;
int n, m;
struct Q {
    int op, l, r, v;
} q[5005];
int a[5005], b[5005];
int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++)
        scanf("%d%d%d%d", &q[i].op, &q[i].l, &q[i].r, &q[i].v);
    for(i = 1; i <= n; i++)
        a[i] = inf;
    for(i = m - 1; i >= 0; i--) {
        if(q[i].op == 1) {
            for(j = q[i].l; j <= q[i].r; j++)
                a[j] -= q[i].v;
        }
        else {
            for(j = q[i].l; j <= q[i].r; j++) {
                if(a[j] >= q[i].v) a[j] = q[i].v;
            }
        }
    }
    for(i = 1; i <= n; i++)
        b[i] = a[i];
    for(i = 0; i < m; i++) {
        if(q[i].op == 1) {
            for(j = q[i].l; j <= q[i].r; j++)
                b[j] += q[i].v;
        }
        else {
            bool flag = false;
            for(j = q[i].l; j <= q[i].r; j++) {
                if(b[j] == q[i].v) flag = true;
                else if(b[j] > q[i].v) flag = false;
            }
            if(!flag) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}