#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int n;
ll ans;
struct Edge
{
    int v;
    ll w;
};
vector<Edge> e[MAXN + 5];
ll sz[MAXN + 5];
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].v;
        ll w = e[u][i].w;
        if (v == fa)
            continue;
        dfs(v, u);
        ans += abs(n - sz[v] - sz[v]) * w;
        sz[u] += sz[v];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        e[u].push_back(Edge{v, w});
        e[v].push_back(Edge{u, w});
    }
    ans = 0;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}