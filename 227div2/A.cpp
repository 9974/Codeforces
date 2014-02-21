#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int x, y, a, b, ans;
int main() {
    scanf("%d:%d", &x, &y); x = x*60+y;
    scanf("%d:%d", &a, &b); a = a*60+b;
    x -= a;
    if(x < 0) x += 24*60;
    printf("%.02d:%.02d\n",x/60, x%60);
}