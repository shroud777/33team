
// Problem : P2895 [USACO08FEB]Meteor Shower S
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P2895
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
int T[305][305];
int dx[] = {0, 0, -1, 1, 0};
int dy[] = {-1, 1, 0, 0, 0};
struct Point
{
    int x, y;
};
queue<Point> q;
bool vis[305][305];
int dis[305][305];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;
    memset(T, 0x3f, sizeof(T));
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= m; i++)
    {
        int t, x, y;
        cin >> x >> y >> t;
        for (int j = 0; j < 5; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0)
                continue;
            T[nx][ny] = min(T[nx][ny], t);
        }
    }
    q.push(Point{0, 0});
    vis[0][0] = true;
    dis[0][0] = 0;
    while (!q.empty())
    {
        Point h = q.front();
        q.pop();
        if (T[h.x][h.y] == 0x3f3f3f3f)
        {
            cout << dis[h.x][h.y] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = h.x + dx[i];
            int ny = h.y + dy[i];
            int nt = dis[h.x][h.y] + 1;
            if (nx < 0 || ny < 0)
                continue;
            if (nt >= T[nx][ny] || vis[nx][ny])
                continue;
            q.push(Point{nx, ny});
            dis[nx][ny] = nt;
            vis[nx][ny] = true;
        }
    }
    cout << -1 << endl;
    return 0;
}