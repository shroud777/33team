#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int n;
vector<int> e[MAXN + 5];
ll dep[MAXN + 5], sz[MAXN + 5], dp[MAXN + 5];
void dfs(int u, int fa)
{
    sz[u] = 1;
    dep[u] = dep[fa] + 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void dfsdfs(int u, int fa)
{
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dp[v] = dp[u] - sz[v] + (n - sz[v]);
        dfsdfs(v, u);
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
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[0] = -1;
    dfs(1, 0);
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
        dp[1] += dep[i];
    dfsdfs(1, 0);
    ll minX, minI;
    minX = dp[minI = 1];
    for (int i = 2; i <= n; i++)
        if (dp[i] < minX)
            minX = dp[minI = i];
    cout << minX << endl;
    return 0;
}