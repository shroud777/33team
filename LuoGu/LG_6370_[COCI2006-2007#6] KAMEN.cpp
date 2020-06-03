#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r, c, m;
//存图
char g[30005][35];
//(1,i)为起点的路径，第j个点为(j,path[i][j])
int path[35][30005];
//(1,i)为起点的路径，最后一个点在第lastRow[i]行
int lastRow[35];
//维护路径
void xjb(int ith, int nowX, int nowY)
{
    path[ith][nowX] = nowY;
    while (1)
    {
        if (g[nowX + 1][nowY] == 'X')
            break;
        if (g[nowX + 1][nowY] == '.')
            nowX++;
        else if (g[nowX][nowY - 1] == '.' && g[nowX + 1][nowY - 1] == '.')
            nowX++, nowY--;
        else if (g[nowX][nowY + 1] == '.' && g[nowX + 1][nowY + 1] == '.')
            nowX++, nowY++;
        else
            break;
        path[ith][nowX] = nowY;
    }
    lastRow[ith] = nowX;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c;
    memset(g, 'X', sizeof(g));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> g[i][j];
    for (int i = 1; i <= c; i++)
        xjb(i, 1, i);
    cin >> m;
    while (m--)
    {
        int nowC;
        cin >> nowC;
        int toX, toY;
        toX = lastRow[nowC];
        toY = path[nowC][toX];
        g[toX][toY] = 'O';
        for (int i = 1; i <= c; i++)
            if (lastRow[i] == toX && path[i][toX] == toY)
                xjb(i, toX - 1, path[i][toX - 1]);
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
            cout << g[i][j];
        cout << endl;
    }
    return 0;
}