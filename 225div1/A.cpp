#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200004;
typedef long long ll;
int c[maxn];
void add(int x) {
    while(x < maxn) {
        c[x]++;
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


ll ans;
int main() {
    int n, i, a;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &a);
        a++;
        ans += sum(maxn-1) - sum(a);
        add(a);
    }
    printf("%I64d\n", ans);
    return 0;
}