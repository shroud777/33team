#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int n, root;
int p[MAXN + 5];
int c[MAXN + 5];
vector<int> e[MAXN + 5];
priority_queue<int> ans;
void dfs(int x, bool flag)
{
    bool now = true;
    for (int i = 0; i < e[x].size(); i++)
    {
        now = now && c[e[x][i]];
        dfs(e[x][i], flag && c[x]);
    }
    if (!flag && now && c[x])
        ans.push(-x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int v = 1; v <= n; v++)
    {
        cin >> p[v] >> c[v];
        if (p[v] == -1)
            root = p[v];
        e[p[v]].push_back(v);
    }
    dfs(root, true);
    if (ans.empty())
    {
        cout << -1 << endl;
        return 0;
    }
    while (ans.size())
    {
        cout << -ans.top() << " ";
        ans.pop();
    }
    return 0;
}