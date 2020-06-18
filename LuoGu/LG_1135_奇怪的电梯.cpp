
// Problem : P1135 奇怪的电梯
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1135
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, A, B, a[205], dis[205];
bool vis[205];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[i] = false;
    }
    q.push(A);
    vis[A] = true;
    dis[A] = 0;
    while (!q.empty() && !vis[B])
    {
        int h = q.front();
        q.pop();
        if (h + a[h] <= n && !vis[h + a[h]])
        {
            q.push(h + a[h]);
            dis[h + a[h]] = dis[h] + 1;
            vis[h + a[h]] = true;
        }
        if (h - a[h] >= 1 && !vis[h - a[h]])
        {
            q.push(h - a[h]);
            dis[h - a[h]] = dis[h] + 1;
            vis[h - a[h]] = true;
        }
    }
    if (vis[B])
        cout << dis[B] << endl;
    else
        cout << -1 << endl;
    return 0;
}