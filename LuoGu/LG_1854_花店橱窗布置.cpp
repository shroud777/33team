
// Problem : P1854 花店橱窗布置
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1854
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int F, V;
int a[105][105];
int dp[105][105];
int pre[105][105];
vector<int> d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> F >> V;
    for (int i = 1; i <= F; i++)
        for (int j = 1; j <= V; j++)
            cin >> a[i][j];
    //第i朵花放在第j个瓶子里，前i朵花的最大美学值
    int ans = 0xffffffff;
    int ansi = -1;
    for (int i = 1; i <= F; i++)
    {
        for (int j = i; j <= V; j++)
        {
            if (i == 1)
            {
                dp[i][j] = a[i][j];
                pre[i][j] = -1;
                continue;
            }
            dp[i][j] = 0xffffffff;
            for (int k = i - 1; k < j; k++)
            {
                if (dp[i - 1][k] + a[i][j] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][k] + a[i][j];
                    pre[i][j] = k;
                }
            }
            if (i == F)
            {
                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    ansi = j;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = F, j = ansi; i >= 1; i--)
    {
        d.push_back(j);
        j = pre[i][j];
    }
    for (auto it = d.end() - 1;; it--)
    {
        cout << *it << " ";
        if (it == d.begin())
            break;
    }
    cout << endl;
    return 0;
}