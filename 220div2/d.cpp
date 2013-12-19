#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1000006;
int a[maxn];
int s[maxn<<2];
int n, m, tot, len;
int c[maxn];
void add(int x, int v) {
    while(x < maxn) {
        c[x] += v;
        x += x&-x;
    }
}
int sum(int x) {
    int ret = 0;
    while(x > 0) {
        ret += c[x];
        x -= x&-x;
    }
    return ret;
}
int cal(int k) {
    int cur = 0;
    for(int i = 19; i >= 0; i--)
        if(c[cur+(1<<i)] < k) {
            cur += 1<<i;
            k -= c[cur];
        }

    return cur+1;
}
int main() {
    int i;
    scanf("%d%d", &m, &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int t;
    while(m--) {
        scanf("%d", &t);
        if(t == -1) {
            int w = len;
            for(i = 1; i <= n && a[i] <= w; i++) {
                t = cal(a[i]-i+1);
                add(t, -1);
                s[t] = -1;
                len--;
            }
        }
        else {
            s[++tot] = t;
            len++;
            add(tot, 1);
        }
    }
    if(!len) puts("Poor stack!");
    else {
        for(int i = 1; i <= tot; i++)
            if(s[i] != -1) printf("%d", s[i]);
        puts("");
    }
    return 0;
}
