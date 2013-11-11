#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, x;
int dp[1 << 18];
int res[9][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 }, { 13,
        14, 15 }, { 16, 17, 18 }, { 3, 5, 7 }, { 6, 11, 13 }, { 9, 14, 16 } };
vector<int> v[22];
int main() {
    int i, j, k;
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 9; j++) {
            for (k = 0; k < 3; k++) {
                if (res[j][k] == i + 1) {
                    v[i].push_back(res[j][(k + 1) % 3]-1);
                    v[i].push_back(res[j][(k + 2) % 3]-1);
                }
            }
        }
    }

    for (i = (1 << 18) - 2; i >= 0; i--) {
        dp[i] = -1e9;
        for (j = 0; j < 18; j++)
            if (!(i & (1 << j))) {
                int inc = 0;

                for (k = 0; k < v[j].size(); k += 2)
                    if ((i & (1 << (v[j][k]))) && (i & (1 << (v[j][k + 1]))))
                        inc++;
                if (!inc)
                    dp[i] = max(dp[i], -dp[i | (1 << j)]);
                else
                    dp[i] = max(dp[i], inc + dp[i | (1 << j)]);
            }
    }
    while (cin >> n && n) {
        int st = 0;
        for (i = 0; i < n; i++) {
            cin >> x, x--;
            st |= (1 << x);
        }
        if (dp[st] == 0)
            puts("Draw");
        else if (dp[st] < 0)
            puts("Ralph wins");
        else
            puts("Andy wins");
    }
    return 0;
}