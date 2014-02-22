#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, s, x;
int a[103];
vector <int> b;
int main() {
    int i, j;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &k);
        for(i = 0; i < k; i++)
            scanf("%d", &a[i]), s += a[i];
        for(i = 0; i < k/2; i++)
            x += a[i];
        if(k&1) b.push_back(a[k/2]);
    }
    sort(b.begin(), b.end());
    for(i = b.size()-1; i >= 0; i-=2)
        x += b[i];
    printf("%d %d\n", x, s-x);
    return 0;
}