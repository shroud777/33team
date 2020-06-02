#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll n, ans, cnt[100005];
struct Edge
{
    ll to, w;
};
vector<Edge> e[100005];
void dfs(int u, int fa, int len)
{
    cnt[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        if (e[u][i].to == fa)
            continue;
        dfs(e[u][i].to, u, e[u][i].w);
        cnt[u] += cnt[e[u][i].to];
    }
    //cout << u << " " << fa << " " << cnt[u] << endl;
    if (cnt[u] % 2 == 1)
    {
        ans += len;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            e[u].push_back(Edge{v, w});
            e[v].push_back(Edge{u, w});
        }
        ans = 0;
        dfs(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}