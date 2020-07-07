// Problem : CF510B Fox And Two Dots
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/CF510B
// Memory Limit : 250 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, sx, sy;
char g[55][55];
bool vis[55][55];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y, int d)
{
    if (d >= 3 && abs(x - sx) + abs(y - sy) == 1)
    {
        cout << "Yes" << endl;
        exit(0);
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        if (g[nx][ny] != g[sx][sy])
            continue;
        if (!vis[nx][ny])
        {
            vis[nx][ny] = true;
            dfs(nx, ny, d + 1);
            vis[nx][ny] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j])
            {
                sx = i;
                sy = j;
                vis[i][j] = true;
                dfs(i, j, 1);
                vis[i][j] = false;
            }
    cout << "No" << endl;
    return 0;
}