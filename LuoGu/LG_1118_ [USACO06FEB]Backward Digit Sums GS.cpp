
// Problem : P1118 [USACO06FEB]Backward Digit Sums G/S
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1118
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, sum;
ll a[15];
bool used[15];
ll cnt[15];
ll gen()
{
    a[1] = 1;
    cnt[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            if (j == 1 || j == i)
                cnt[j] = 1;
            else
                cnt[j] = a[j] + a[j - 1];
        for (int j = 1; j <= i; j++)
            a[j] = cnt[j];
    }
}
void dfs(ll dep, ll last)
{
    if (last > sum)
        return;
    if (dep > n)
    {
        if (last == sum)
        {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
            exit(0);
        }
        else
            return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            a[dep] = i;
            used[i] = true;
            dfs(dep + 1, last + i * cnt[dep]);
            used[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> sum;
    gen();
    memset(used, false, sizeof(used));
    dfs(1, 0);
    return 0;
}
