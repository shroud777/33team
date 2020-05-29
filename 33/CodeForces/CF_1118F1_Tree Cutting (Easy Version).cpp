#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 300000;
int n, ans;
vector<int> e[MAXN + 5];
int col[MAXN + 5], col1, col2, sz[MAXN + 5][3];
//cnt subtree color
void dfs1(int u, int fa)
{
    sz[u][0] = sz[u][1] = sz[u][2] = 0;
    sz[u][col[u]] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs1(v, u);
        sz[u][0] += sz[v][0];
        sz[u][1] += sz[v][1];
        sz[u][2] += sz[v][2];
    }
}
//cacul ans
void dfs2(int u, int fa)
{
    if (u != 1)
    {
        int re1 = col1 - sz[u][1];
        int re2 = col2 - sz[u][2];
        if (!(re1 && re2))
            if (!(sz[u][1] && sz[u][2]))
                ans++;
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs2(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    col1 = col2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        if (col[i] == 1)
            col1++;
        if (col[i] == 2)
            col2++;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    ans = 0;
    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}