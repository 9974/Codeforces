#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
int n, m, x, y, z, p, a, b;
int main() {
    int i, j, k;
    ios::sync_with_stdio(0);
    cin >> n >> m >> x >> y >> z >> p;
    x%=4, y%=2, z%=4;
    while(p--) {
        cin >> a >> b;
        int _n = n, _m = m, _a, _b;
        for(i = 0; i < x; i++) {
            _a = b; _b = _n-a+1;
            swap(_n, _m);
            a = _a, b = _b;
        }
        for(i = 0; i < y; i++)
            b = _m-b+1;
        for(i = 0; i < z; i++) {
            _a = _m-b+1, _b = a;
            swap(_n, _m);
            a = _a, b = _b;
        }
        cout << a << " " << b << '\n';
    }
    return 0;
}
