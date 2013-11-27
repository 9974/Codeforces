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
int n;
int c[100005][3];
int cal(char ch) {
    if(ch == 'z') return 2;
    if(ch == 'y') return 1;
    return 0;
}
string s;
int m;
int main() {
    int i, j;
    ios::sync_with_stdio(false);
    cin >> s;
    for(i = 1; i <= (int) s.size(); i++)
        c[i][cal(s[i - 1])]++;
    for(i = 1; i <= (int) s.size(); i++)
        for(j = 0; j < 3; j++) {
            c[i][j] += c[i - 1][j];
        }
    cin >> m;
    int l, r;
    while(m--) {
        cin >> l >> r;
        int sum = r-l+1;
        if(sum < 3) {
            puts("YES");
            continue;
        }
        int a[3];
        for(i = 0; i < 3; i++)
        	a[i] = c[r][i] - c[l - 1][i];
        sort(a, a+3);
        if(a[0] == a[1] && a[1]== a[2] ||
           a[0] == a[1]-1 && a[1] == a[2] ||
           a[0] == a[1] && a[1] == a[2]-1)
            puts("YES");
        else puts("NO");
    }
    return 0;
}

