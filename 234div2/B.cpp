#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long lld;

char s[1010];
int g[1010],n,m;
int main() {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i ++) {
                scanf("%s",s);
                int p,q;
                for (int j = 0; j < m; j ++) {
                        if (s[j]=='G') p = j;
                        else if (s[j]=='S') q = j;
                }
                if (q-p<0) {
                        puts("-1"); return 0;
                }
                if (q-p) g[i] = q-p;
        }
        sort(g,g+n);
        n = unique(g,g+n)-g;
        printf("%d\n",n);
        return 0;
}