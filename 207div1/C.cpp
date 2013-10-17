#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c[5], n, t, ans, sum = 0;
int main() {
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &t);
        c[t]++;
        sum += t;
    }
    bool ok = 0;
    for(i = 0; i <= n; i++) {
        t = sum - i*3;
        if(t < 0) break;
        if(t%4==0 && t/4 <= n-i) {
            ok = 1;
            break;
        }
    }
    if(!ok) {
        puts("-1");
        return 0;
    }
    int d = min(c[1], c[2]);
    c[3] += d, c[1] -= d, c[2] -= d, ans += d;
    c[0] += d;
    if(c[2]) {
        ans += c[2]/3*2;
        c[3] += 2*c[2]/3;
        t = c[2]%3;
        if(t == 2) {
            ans += 2;
        }
        if(t == 1) {
            if(c[4] >= 1) ans += 1;
            else ans += 2;
        }
    }
    else if(c[1]) {
        ans += c[1]/3*2;
        c[3] += c[1]/3;
        t = c[1]%3;
        if(t == 1) {
            if(c[3] >= 1) ans++;
            else ans+=2;
        }
        if(t == 2) {
            ans += 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}