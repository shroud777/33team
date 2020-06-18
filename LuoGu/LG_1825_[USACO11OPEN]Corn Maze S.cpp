
// Problem : P1825 [USACO11OPEN]Corn Maze S
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1825
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char g[305][305];
struct Point
{
    int x, y;
    bool operator==(const Point &a)
    {
        return x == a.x && y == a.y;
    }
};
Point w[26][2], e;
queue<Point> q;
bool vis[305][305];
int dis[305][305];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(w, -1, sizeof(w));
    memset(dis, -1, sizeof(dis));
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == '@')
            {
                q.push(Point{i, j});
                vis[i][j] = true;
                dis[i][j] = 0;
            }
            if ('A' <= g[i][j] && g[i][j] <= 'Z')
            {
                if (w[g[i][j] - 'A'][0].x == -1)
                {
                    w[g[i][j] - 'A'][0].x = i;
                    w[g[i][j] - 'A'][0].y = j;
                }
                else
                {
                    w[g[i][j] - 'A'][1].x = i;
                    w[g[i][j] - 'A'][1].y = j;
                }
            }
            if (g[i][j] == '=')
            {
                e.x = i;
                e.y = j;
            }
        }
    }
    while (!vis[e.x][e.y] && !q.empty())
    {
        Point h = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point nxt = Point{h.x + dx[i], h.y + dy[i]};
            if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m)
                continue;
            if (g[nxt.x][nxt.y] == '#')
                continue;
            if (vis[nxt.x][nxt.y])
            {
                continue;
            }
            vis[nxt.x][nxt.y] = true;
            if ('A' <= g[nxt.x][nxt.y] && g[nxt.x][nxt.y] <= 'Z')
            {
                if (w[g[nxt.x][nxt.y] - 'A'][0] == nxt)
                    nxt = w[g[nxt.x][nxt.y] - 'A'][1];
                else
                    nxt = w[g[nxt.x][nxt.y] - 'A'][0];
                if (nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m)
                    continue;
            }
            q.push(nxt);
            dis[nxt.x][nxt.y] = dis[h.x][h.y] + 1;
        }
    }
    cout << dis[e.x][e.y] << endl;
    return 0;
}