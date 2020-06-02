#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int k[205], a[205];
bool dp[500005];
void p01(int v)
{
    for (int i = 500000; i >= v; i--)
        dp[i] = dp[i] || dp[i - v];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> k[i] >> a[i];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= a[i]; j *= 2)
        {
            p01(k[i] * j);
            a[i] -= j;
        }
        if (a[i] > 0)
            p01(k[i] * a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (dp[x])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}