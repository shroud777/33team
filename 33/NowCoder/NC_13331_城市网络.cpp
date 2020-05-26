#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200005;
int n, q;
int head[MAXN];
struct Edge
{
    int u, v, next;
} e[MAXN];
int tot = 0;
int to[MAXN], a[MAXN];
int d[MAXN][25], dep[MAXN];
void dfs(int p, int fa)
{
    //d[p][0]
    int x = fa;
    for (int k = 20; k >= 0; k--)
        if (d[x][k] && a[d[x][k]] <= a[p])
            x = d[x][k];
    if (a[x] > a[p])
        d[p][0] = x;
    else
        d[p][0] = d[x][0];
    //more
    for (int i = 1; i <= 20; i++)
        d[p][i] = d[d[p][i - 1]][i - 1];
    //dfs
    dep[p] = dep[fa] + 1;
    for (int i = head[p]; ~i; i = e[i].next)
    {
        dfs(e[i].v, p);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[++tot].u = x;
        e[tot].v = y;
        e[tot].next = head[x];
        head[x] = tot;
    }
    for (int i = 1; i <= q; i++)
    {
        //第i个问题添加一个点 i+n->x
        int x, y, c;
        cin >> x >> y >> c;
        e[++tot].u = x;
        e[tot].v = i + n;
        e[tot].next = head[x];
        head[x] = tot;
        a[i + n] = c;
        to[i + n] = y;
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
    {
        int ans = 0;
        int x = i + n;
        for (int k = 20; k >= 0; k--)
        {
            if (dep[d[x][k]] >= dep[to[i + n]])
            {
                ans += (1 << k);
                x = d[x][k];
            }
        }
        cout << ans << endl;
    }
    return 0;
}