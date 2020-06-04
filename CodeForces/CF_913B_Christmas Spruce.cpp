#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int n;
bool flag;
vector<int> e[MAXN + 5];
int sz[MAXN + 5];
int szl[MAXN + 5];
bool leaf[MAXN + 5];
void dfs(int u, int fa)
{
    if (!flag)
        return;
    sz[u] = 1;
    szl[u] = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        szl[u] += leaf[v];
    }
    if (sz[u] == 1)
        leaf[u] = 1;
    if (!leaf[u] && szl[u] < 3)
        flag = false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int v = 2; v <= n; v++)
    {
        int u;
        cin >> u;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    flag = true;
    memset(leaf, false, sizeof(leaf));
    dfs(1, 0);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}