#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, e_num, ans;
vector<int> e[505];
int back[505];
bool vis[505];
bool match(int x)
{
    for (int i = 0; i < e[x].size(); i++)
    {
        int &v = e[x][i];
        if (vis[v])
            continue;
        vis[v] = true;
        if (!back[v] || match(back[v]))
        {
            back[v] = x;
            return true;
        }
        //vis[v] = false; 如果这次没法通过v增广那么后面也不可能，所以不需要改回false
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> e_num;
    for (int i = 1; i <= e_num; i++)
    {
        int u, v;
        cin >> u >> v;
        if (v <= m)
            e[u].push_back(v);
    }
    ans = 0;
    for (int i = 1; i <= m; i++)
        back[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= m; i++)
            vis[i] = false;
        ans += match(i);
    }
    cout << ans << endl;
    return 0;
}