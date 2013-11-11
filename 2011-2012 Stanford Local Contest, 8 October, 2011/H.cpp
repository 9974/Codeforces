#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n;
string a[101], c[101], b[101];
int idx[256];
string str;
int sz, pos;
string sub(const string &c, const string &a) {
    int i;
    string ret;
    for(i = 0; i < (int)c.size(); i++) {
        char t = (c[i]-a[i]+'A');
        if(t < 'A' || t > 'Z') t += 26;
        ret += t;
    }
    return ret;
}
bool cal() {
    int i, j, k;
    for(i = 1; i <= sz; i++) {
        string tp;
        string t;
        for(j = 0; j < n; j++) {
            if(i > (int)b[j].size()) continue;
            tp = b[j].substr(i, b[j].size());
            t = c[j].substr(0, b[j].size()-i);
            if(tp != t) break;
        }
        if(j == n) {
            bool flag = true;
            for(j = 0 ;j < n; j++)
                for(k = j+1; k < n; k++) {
                    int len = min(b[j].size(), b[k].size());
                    len = min(i, len);
                    tp = b[j].substr(0, len);
                    t = b[k].substr(0, len);
                    if(t != tp) {
                        flag = false;
                        goto loop;
                    }
                }
            loop: if(flag) {
                str = b[pos].substr(0, i);
                return 1;
            }
        }

    }
    return 0;
}
int main() {
    int i;

    for(i = 'A'; i <= 'Z'; i++)
        idx[i] = i-'A';
    while(cin >> n && n) {
        sz = 0; pos = -1;
        for(i = 0; i < n; i++) {
            cin >> a[i] >> c[i];
            if(sz < (int)a[i].size()) {
                sz = a[i].size();
                pos = i;
            }
        }
        for(i = 0; i < n; i++) {
            b[i] = sub(c[i], a[i]);
            //cout << b[i] << endl;
        }
        if(cal()) cout << str << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}