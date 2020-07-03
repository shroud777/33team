
// Problem : P1332 血色先锋队
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1332
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, s, e;
int ans[505][505];
struct Point
{
    int x, y;
} t;
queue<Point> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> e;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= s; i++)
    {
        cin >> t.x >> t.y;
        ans[t.x][t.y] = 0;
        q.push(t);
    }
    while (!q.empty())
    {
        Point h = q.front();
        q.pop();
        if (h.x > 1 && ans[h.x - 1][h.y] == -1)
        {
            ans[h.x - 1][h.y] = ans[h.x][h.y] + 1;
            q.push(Point{h.x - 1, h.y});
        }
        if (h.x < n && ans[h.x + 1][h.y] == -1)
        {
            ans[h.x + 1][h.y] = ans[h.x][h.y] + 1;
            q.push(Point{h.x + 1, h.y});
        }
        if (h.y > 0 && ans[h.x][h.y - 1] == -1)
        {
            ans[h.x][h.y - 1] = ans[h.x][h.y] + 1;
            q.push(Point{h.x, h.y - 1});
        }
        if (h.y < m && ans[h.x][h.y + 1] == -1)
        {
            ans[h.x][h.y + 1] = ans[h.x][h.y] + 1;
            q.push(Point{h.x, h.y + 1});
        }
    }
    for (int i = 1; i <= e; i++)
    {
        cin >> t.x >> t.y;
        cout << ans[t.x][t.y] << endl;
    }
    return 0;
}