#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int t, n;
ll G, B;
struct Edge
{
    int v;
    ll w;
};
vector<Edge> e[MAXN + 5];
int sz[MAXN + 5];
void dfsG(int u, int fa, ll w)
{
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].v;
        ll noww = e[u][i].w;
        if (v == fa)
            continue;
        dfsG(v, u, noww);
        sz[u] += sz[v];
    }
    if (sz[u] % 2 == 1)
        G += w;
}
void dfsB(int u, int fa, ll w)
{
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].v;
        ll noww = e[u][i].w;
        if (v == fa)
            continue;
        dfsB(v, u, noww);
    }
    B += min(sz[u], n - sz[u]) * w;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        G = B = 0;
        dfsG(1, 0, 0);
        dfsB(1, 0, 0);
        cout << G << " " << B << endl;
    }
    return 0;
}