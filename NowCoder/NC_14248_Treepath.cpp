#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int n;
vector<int> e[MAXN + 5];
ll dep[MAXN + 5], odd, even, ans;
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
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
    dep[0] = 0;
    dfs(1, 0);
    odd = even = 0;
    for (int i = 1; i <= n; i++)
        if (dep[i] % 2 == 0)
            even++;
        else
            odd++;
    ans = even * (even - 1) / 2 + odd * (odd - 1) / 2;
    cout << ans << endl;
    return 0;
}