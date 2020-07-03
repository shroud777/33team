
// Problem : P4160 [SCOI2009]生日快乐
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4160
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dfs(double x, double y, double n)
{
    if (n == 1)
        return max(x / y, y / x);
    double res = 10001;
    for (double i = 1; i * 2 <= n; i++)
    {
        double ansX = max(dfs(x * i / n, y, i),
                          dfs(x * (n - i) / n, y, n - i));
        double ansY = max(dfs(x, y * i / n, i),
                          dfs(x, y * (n - i) / n, n - i));
        res = min(res, min(ansX, ansY));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double x, y, n;
    cin >> x >> y >> n;
    cout << fixed << setprecision(6) << dfs(x, y, n) << endl;
    return 0;
}