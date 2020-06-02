#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
vector<int> e[MAXN];
int n, k[MAXN], f[MAXN], ans;
void dfs(int u, int fa)
{
    f[u] = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        dfs(e[u][i], u);
        f[u] = max(f[u], f[e[u][i]] - 1);
        k[u] = max(k[u], k[e[u][i]] - 1);
    }
    if (f[u] == 0)
    {
        ans++;
        f[u] = k[u];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        e[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    ans = 0;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}