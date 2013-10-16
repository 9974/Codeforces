#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
set <int> st;
set <int>:: iterator l, r;
vector <int> v;
int ans[300005];
int n, m;
int main() {
    int i, j, x, y, c;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        st.insert(i);
    while(m--) {
        scanf("%d%d%d", &x, &y, &c);
        l = st.lower_bound(x);
        r = st.upper_bound(y);
        v.clear();
        for(;l != r; l++) {
            if(*l!=c && !ans[*l]) {
                v.push_back(*l);
                ans[*l] = c;
            }
        }
        for(i = 0; i < v.size(); i++)
            st.erase(v[i]);
    }
    for(i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
