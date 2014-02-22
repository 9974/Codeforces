#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int a[maxn][11];
char s[maxn];
int main() {
    ios::sync_with_stdio(0);
    int i, j, n, m, k;
    cin >> n >> k >> m;
    cin >> s;
    int l = strlen(s);
    for(i = 0; i < l; i++)
        for(j = 0; j < k; j++)
            if((i-j+1)%k==0) {
                if(s[i] == '0')a[i][j]++;
            }
            else if(s[i] == '1') a[i][j]++;
    for(i = 1; i <= l; i++)
        for(j = 0; j < k; j++)
            a[i][j] += a[i-1][j];
    while(m--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int v = x%k;
        int ans = a[y][v];
        if(x > 0)
            ans -= a[x-1][v];
        cout << ans << endl;
    }
    return 0;
}
/*
12 3 10000
101110001100

*/