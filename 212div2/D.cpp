#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair< int, int > pii;
#define mp make_pair
const int maxn = 100005;
struct Edge {
    int v, w, vis, next;
}edge[1000006];
int head[maxn], E;
void add(int s, int t, int w) {
    edge[E] = (Edge){t, w, 0, head[s]};
    head[s] = E++;
}
void init() {
    memset(head, -1, sizeof(head));
    E = 0;
}
int n, m, p, q;
bool vis[maxn];
ll dfs(int u) {
    vis[u] = true;
    ll ret = 0;
    for(int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(edge[i].vis) continue;
        edge[i].vis = edge[i^1].vis = true;
        ret += edge[i].w;
        if(!vis[v])ret += dfs(v);
    }
    return ret;
}
struct node {
    int v;
    ll sum;
    bool operator<(const node &t) const {
        return sum > t.sum;
    }
};
priority_queue< node > Q;
int main() {
    int i;
    init();
    scanf("%d%d%d%d", &n, &m, &p, &q);
    int xx = -1, yy = -1;
    for(i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        xx = x, yy = y;
    }
    for(i = 1; i <= n; i++)
        if(!vis[i])
            Q.push( (node){i, dfs(i)});
    int tot = Q.size();
    if(tot - p > q || tot < q) {
        puts("NO");
        return 0;
    }
    if(!m) {
        if(p > 0 && q == n) {
            puts("NO");
            return 0;
        }
    }
    tot -= q;
    puts("YES");
    int sum = 0;
    while(sum < tot) {
        node x = Q.top();
        Q.pop();
        node y = Q.top();
        Q.pop();
        printf("%d %d\n", x.v, y.v);
        xx = x.v, yy = y.v;
        node t;
        t.v = x.v;
        t.sum = x.sum + y.sum+min(1000000000ll, x.sum+y.sum+1);
        Q.push(t);
        sum++;
    }
    for(i = 0; i < p-tot; i++)
        printf("%d %d\n", xx, yy);
    return 0;
}