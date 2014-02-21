#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n;
double l, r, x[22], y[22], a[22];
double dp[1<<21];
const double pi = acos(-1.0);
double work(double p, int i) {
    double d = sqrt((x[i]-p)*(x[i]-p)+y[i]*y[i]);
    double ct = asin(y[i]/d);
    if(x[i] <= p) ct = pi - ct;
    if(ct+a[i] >= pi) return 1e9;
    return d*sin(a[i])/sin(pi-a[i]-ct)+p;
}
int main() {
    int i, j;
    cin >> n >> l >> r;
    for(i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> a[i], a[i] = a[i]*pi/180;
    fill(dp, dp+(1<<n), l);
    for(i = 0; i < (1<<n); i++)
        for(j = 0; j < n; j++) if(!(i>>j&1)) {
            double v = work(dp[i], j);
            if(v >= r) {
                printf("%.10f\n", r-l);
                return 0;
            }
            dp[i|(1<<j)] = max(dp[i|(1<<j)], v);
        }
    printf("%.10f\n", dp[(1<<n)-1]-l);
    return 0;
}