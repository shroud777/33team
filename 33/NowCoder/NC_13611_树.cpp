#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, dp[305][305];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j - 1] * (k - j + 1) + dp[i - 1][j]) % 1000000007;
    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + dp[n][i]) % 1000000007;
    cout << ans << endl;
    return 0;
}