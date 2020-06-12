
// Problem : P1157 组合的输出
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1157
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, r;
ll a[25];
void dfs(int dep)
{
    if (dep > r)
    {
        for (int i = 1; i <= r; i++)
            cout << setw(3) << a[i];
        cout << endl;
        return;
    }
    for (int i = a[dep - 1] + 1; i <= n; i++)
    {
        a[dep] = i;
        dfs(dep + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    a[0] = 0;
    dfs(1);
    return 0;
}