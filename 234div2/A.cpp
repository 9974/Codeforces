#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int a[] = {1, 2, 3, 4, 6, 12};
int c[14];
int main() {
	ios::sync_with_stdio(0);
	int i, j, cas;
	cin >> cas;
	while(cas--) {
		cin >> s;
		vector <pair<int, int> > ans;
		for(i = 0; i < 6; i++) {
			memset(c, 0, sizeof(c));
			int t = 12/a[i];
			for(j = 0; j < s.size(); j++) 
				c[j%t] += s[j] == 'X';
			for(j = 0; j < t; j++) if(c[j]==a[i]) {
				ans.push_back(make_pair(a[i], t));
				break;
			}
		}
		cout << ans.size() << " ";
		for(i = 0; i < ans.size(); i++)
			cout << ans[i].first <<"x" << ans[i].second << " ";
		cout << "\n";
	}
	return 0;
}
