#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, now, cnt[100000];
char g[1505][1505];
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
void dfs(int x, int y)
{
    now++;
    g[x][y] = '.';
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
            if (g[nx][ny] == '*')
                dfs(nx, ny);
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
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '*')
            {
                now = 0;
                dfs(i, j);
                cnt[now]++;
            }
        }
    int num, ans;
    num = 0;
    ans = 0;
    for (int i = 1; i <= 100000; i++)
    {
        if (cnt[i])
        {
            num++;
            ans = max(ans, cnt[i] * i);
        }
    }
    cout << num << " " << ans << endl;
    return 0;
}