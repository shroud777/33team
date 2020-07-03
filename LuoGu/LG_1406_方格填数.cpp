
// Problem : P1406 方格填数
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1406
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, nn, sum;
int ans[5][5], rowsum[5], colsum[5], a[20];
bool vis[20];
void dfs(int x, int y)
{
    if (x < n && y > n)
    {
        x++;
        y = 1;
    }
    if (y == 1 && x > 1)
        if (rowsum[x - 1] != sum)
            return;
    if (x == n && y > 1)
        if (colsum[y - 1] != sum)
            return;
    if (x == n && y == n + 1)
    {
        int ts = 0;
        for (int i = 1; i <= n; i++)
            ts += ans[i][i];
        if (ts != sum)
            return;
        ts = 0;
        for (int i = 1; i <= n; i++)
            ts += ans[i][n-i+1];
        if (ts != sum)
            return;
        cout << sum << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        exit(0);
    }
    for (int i = 1; i <= nn; i++)
    {
        if (!vis[i])
        {
            ans[x][y] = a[i];
            vis[i] = true;
            rowsum[x] += a[i];
            colsum[y] += a[i];
            dfs(x, y + 1);
            vis[i] = false;
            rowsum[x] -= a[i];
            colsum[y] -= a[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    nn = n * n;
    sum = 0;
    for (int i = 1; i <= nn; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    sort(a + 1, a + nn + 1);
    memset(vis, false, sizeof(vis));
    memset(rowsum, 0, sizeof(rowsum));
    memset(colsum, 0, sizeof(colsum));
    dfs(1, 1);
    return 0;
}