#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair< int, int > pii;
#define mp make_pair
int n, m, p;
int a[200005], b[200005];
vector< int > v, ans;
int f[100005];
int sum[200005], s[200005];
int tot, cnt;
int main() {
    ios::sync_with_stdio(false);
    int i, j;
    cin >> n >> m >> p;
    for(i = 0; i < n; i++)
        cin >> a[i], v.push_back(a[i]);
    for(i = 0; i < m; i++)
        cin >> b[i], v.push_back(b[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 0; i < n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    for(i = 0; i < m; i++)
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();

    memset(s, 0, sizeof(s));
    for(i = 0; i < m; i++) s[b[i]]++;
    for(i = 0; i <= (int) v.size(); i++) if(s[i]) tot++;
    for(i = 0; i < p; i++) {
        if((n-i)/p+1 < m) continue; // length < m
        cnt = tot;
        memcpy(sum, s, sizeof(int)*(v.size()));
        for(j = 0; p * j + i < n; j++) {
            int t = a[p*j+i];
     	    if(!sum[t]) cnt++;
            sum[t]--;
            if(!sum[t]) cnt--;       
            if(j >= m) {
                t = a[p*(j-m)+i];
  		if(!sum[t]) cnt++;
                sum[t]++;
                if(!sum[t]) cnt--;
            }
            if(cnt == 0) ans.push_back(p*(j-m+1)+i+1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(i = 0; i < (int) ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
