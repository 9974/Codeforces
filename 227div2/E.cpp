#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1000006;
set <int> s;
set <int>::iterator it;
int c[maxn];
int n, k;
void add(int x, int v) {
    while(x <= n) {
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
int pos[maxn];
bool vis[maxn];
int a;
long long ans;
int main() {
    int i, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%d", &a), pos[a] = i, add(i, 1);
    for(i = 1; i <= k; i++)
        scanf("%d", &a), vis[a] = 1;
    s.insert(0), s.insert(n+1);
    for(i = 1; i <= n; i++) {
        if(vis[i]) s.insert(pos[i]);
        else {
            //printf("i = %d\n", i);
            //for(it = s.begin(); it != s.end(); it++)
            //  printf("%d ", *it);
            //puts("");
            it = s.lower_bound(pos[i]);
            int r = (*it)-1;
            int l = (*(--it))+1;
            //printf("l = %d r = %d\n", l, r);
            ans += sum(r) - sum(l-1);
            add(pos[i], -1);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}