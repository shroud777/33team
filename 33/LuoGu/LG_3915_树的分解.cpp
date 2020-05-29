#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int t, n, k, cnt;
vector<int> e[MAXN + 5];
int sz[MAXN + 5];
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        if (sz[v] == k)
            cnt++;
        else
            sz[u] += sz[v];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cnt = 0;
        dfs(1, 0);
        if (sz[1] == k)
            cnt++;
        if (cnt == n / k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}