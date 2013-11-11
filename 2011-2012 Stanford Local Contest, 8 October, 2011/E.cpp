#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
const double eps = 1e-8;
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}
struct Point {
    double x, y;
    int id;
    void in(int i=0) {
        scanf("%lf%lf", &x, &y);
        id = 0;
    }
    Point operator-(const Point &t) const {
        return (Point) {x-t.x, y-t.y};
    }
    Point operator+(const Point &t) const {
        return (Point) {x+t.x, y+t.y};
    }
    double operator*(const Point &t) const {
        return x*t.y-y*t.x;
    }
    Point operator*(const double &t) const {
        return (Point) {x*t, y*t};
    }
    bool operator<(const Point &t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
    bool operator==(const Point &t) const {
        return x==t.x && y==t.y;
    }
    void out() {
        printf("%lf %lf~~~~~~\n", x, y);
    }
};
struct Line {
    Point a, b;
    vector <Point> res;
    void in(){
        a.in();
        b.in();
        res.clear();
    }
}ln[505];
int n;
pii belo[505*505];
Point p[505*505];
bool intersect(Line &l1, Line &l2, Point &ret) {
    Point v1 = l1.b-l1.a, v2 = l2.b-l2.a;
    if(!dcmp(v1*v2)) return 0;
    double t = (l2.a-l1.a)*v2/(v1*v2);
    ret = l1.a+v1*t;
    return 1;
}
int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1,}, {1, 1}};
int main() {
    int i, j, k;
    while(~scanf("%d", &n) && n) {
        for(i = 0; i < n; i++) ln[i].in();
        int t = 0;
        for(i = 0; i < n; i++)
            for(j = i+1; j < n; j++) {
                if(!intersect(ln[i], ln[j], p[t])) continue;
                p[t].id = t;
                belo[t] = make_pair(i, j);
                ln[i].res.push_back(p[t]);
                ln[j].res.push_back(p[t]);
                t++;
            }
        for(i = 0; i < n; i++) 
            sort(ln[i].res.begin(), ln[i].res.end());
        int cnt = 0;
        for(i = 0; i < t; i++) {
            int x = belo[i].first;
            int y = belo[i].second;
            int u = lower_bound(ln[x].res.begin(), ln[x].res.end(), p[i])-ln[x].res.begin();
            int v = lower_bound(ln[y].res.begin(), ln[y].res.end(), p[i])-ln[y].res.begin();
            for(k = 0; k < 4; k++) {
                int xx = u + dir[k][0];
                int yy = v + dir[k][1];
                if(xx >= 0 && xx < ln[x].res.size() && yy >= 0 && yy < ln[y].res.size()) {
                    int l = ln[x].res[xx].id, r = ln[y].res[yy].id;
                    if(belo[l].first == belo[r].first || belo[l].first == belo[r].second ||
                       belo[l].second == belo[r].first || belo[l].second == belo[r].second) {
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n", cnt/3);
    }
    return 0;
}
/*
6
0 0 0 1
1 0 1 1
2 0 2 1
3 0 3 1
5 0 0 -5
0 0 5 0
0

3
0 0 0 1
5 0 0 -5
0 0 5 0
0
 */