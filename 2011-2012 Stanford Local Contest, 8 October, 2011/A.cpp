#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
char str[] = {"RPS"};
ll n;
int main() {
    while(cin >> n && n) {
        ll val = 1;
        while(val <= n) val *= 3;
        val /= 3;
        int cnt = 0;
        while(n > 3) {
            while(val < n) n -= val, cnt++;
            val /=3;
        }
        cout << str[(n+cnt)%3] << endl;
    }
    return 0;
}