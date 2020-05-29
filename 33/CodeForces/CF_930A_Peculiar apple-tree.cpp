#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
int n;
vector<int> e[MAXN + 5];
int dep[MAXN + 5];
bool cnt[MAXN + 5];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs(v, u);
    }
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
    }
    dep[0] = 0;
    dfs(1, 0);
    memset(cnt, false, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        cnt[dep[i]] ^= 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += cnt[i];
    cout << ans << endl;
    return 0;
}