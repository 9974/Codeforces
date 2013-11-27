#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int m, n, q;
ll sum;
ll w[100005];
int main() {
    ios::sync_with_stdio(false);
    int i;
    cin >> n >> m;
    for(i = 0; i < m; i++) cin >> q >> w[i];
    sort(w, w+m); reverse(w, w+m);
    for(i = 1; i <= m; i++) {
        if(i&1) sum = i*(i-1)/2+1;
        else sum = i*i/2;
        if(sum > n) break;
    }
    cout << accumulate(w, w+i-1, 0LL) << endl;
    return 0;
}
