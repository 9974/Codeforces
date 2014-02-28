#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool ok(int n) {
    if(n == 1) return 0;
    for(int i = 2; i*i <= n; i++)
        if(n%i==0) return 0;
    return 1;
}
int n;
typedef long long ll;
int main() {
    int i, j, cas;
    ios::sync_with_stdio(0);
    cin >> cas;
    while(cas--) {
        cin >> n;
        ll l, r;
        for(r = n+1;;r++)
            if(ok(r)) break;
        for(l = n;; l--)
            if(ok(l)) break;
       // cout << "l = " << l <<" r = " << r << endl;
        ll a = l*r-2*r+2*(n-l+1);
        ll b = 2*l*r;
        ll t = __gcd(a, b);
        a /= t, b /= t;
        cout << a << "/" << b << endl;
    }
}