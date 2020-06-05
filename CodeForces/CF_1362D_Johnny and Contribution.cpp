
// Problem : D. Johnny and Contribution
// Contest : Codeforces - Codeforces Round #647 (Div. 2) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1362/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500000;
int n, m;
vector<int> e[MAXN + 5];
int t[MAXN + 5];
priority_queue<int> T[MAXN + 5];
bool vis[MAXN + 5];
int cnt[MAXN + 5];
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        T[t[i]].push(-i);
    }
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    bool flag = true;
    //t[i]从1~n一个个看过去
    for (int i = 1; i <= n; i++)
    {
        while (T[i].size())
        {
            int h = -T[i].top();
            T[i].pop();
            if (cnt[h] < i - 1)
            {
                flag = false;
                break;
            }
            vis[h] = true;
            ans.push_back(h);
            //不能有相同的
            for (auto v : e[h])
            {
                if (t[v] == i && vis[v])
                {
                    flag = false;
                    break;
                }
                if (t[v] > i)
                {
                    if (cnt[v] < i - 1)
                    {
                        flag = false;
                        break;
                    }
                    else
                        cnt[v] = i;
                }
            }
            if (!flag)
                break;
        }
        if (!flag)
            break;
    }
    if (flag)
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}