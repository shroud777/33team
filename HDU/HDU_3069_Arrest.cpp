
// Problem : Arrest
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=3069
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
int n;
vector<int> e[MAXN + 5];
int sz[MAXN + 5];
void dfs(int u, int fa)
{
    int maxSub = 0;
    int maxSubCnt = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        if (sz[v] > maxSub)
        {
            maxSub = sz[v];
            maxSubCnt = 1;
        }
        else if (sz[v] == maxSub)
        {
            maxSubCnt++;
        }
    }
    if (maxSub == 0)
        sz[u] = 1;
    else if (maxSubCnt > 1)
        sz[u] = maxSub + 1;
    else
        sz[u] = maxSub;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        cout << sz[1] << endl;
    }
    return 0;
}