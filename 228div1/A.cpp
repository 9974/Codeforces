#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100005;
typedef long long ll;
int n;
int a[103];
bool vis[103];


int main() {
    int i, j;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int cnt = 0;
    while(1) {
        for(j = 0; j < n; j++) if(!vis[j]) break;
        if(j == n)
            break;
        cnt++;
        int w = 1;
        vis[j] = 1;
        for(j++; j < n; j++) if(!vis[j]) {
            if(a[j] >= w) {
                w ++;
                vis[j] = 1;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}