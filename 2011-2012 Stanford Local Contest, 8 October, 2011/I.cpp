#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const double pi = acos(-1.0);
int n;
string str[303];
double st[10003];
int top;
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++)
            cin >> str[i];
        bool ok = true;
        for(double i = 1.00; i <= pi*2; i+=0.003) {
            for(double sign = -1.0; sign <= 1.0; sign += 2.0) {
            top = 0;
            for (int j = 0; j < n; j++) {
                if (str[j] == "x") {
                    st[++top] = i*sign;
                } else if (str[j] == "sin") {
                    st[top] = sin(st[top]);
                } else if (str[j] == "cos") {
                    st[top] = cos(st[top]);
                } else if(str[j] == "tan") {
                    st[top] = tan(st[top]);
                } else if (str[j] == "-") {
                    double x = st[top--];
                    double y = st[top--];
                    st[++top] = y - x;
                } else if (str[j] == "+") {
                    double x = st[top--];
                    double y = st[top--];
                    st[++top] = y + x;
                } else if (str[j] == "*") {
                    double x = st[top--];
                    double y = st[top--];
                    st[++top] = y * x;
                }
            }
            if(fabs(st[top]) >1e-7) {
                ok = false;
                break;
            }
            }
        }
        if(ok) puts("Identity");
        else puts("Not an identity");
    }
    return 0;
}