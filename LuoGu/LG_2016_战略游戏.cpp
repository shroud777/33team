
// Problem : P2016 战略游戏
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P2016
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1500;
int n;
vector<int> e[MAXN + 5];
int dp[MAXN+5][2];
void dfs(int u, int fa)
{
	dp[u][0]=0;
	dp[u][1]=1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][1]+=min(dp[v][0],dp[v][1]);
        dp[u][0]+=dp[v][1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, k, v;
        cin >> u >> k;
        u++;
        for (int i = 1; i <= k; i++)
        {
            cin >> v;
            v++;
            e[u].push_back(v);
        }
    }
    dfs(1, 0);
    cout<<min(dp[1][0],dp[1][1])<<endl;
    return 0;
}