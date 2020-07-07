
// Problem : P1439 【模板】最长公共子序列
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1439
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, now, ans;
int h[100005];
int a[100005];
int dp[100005];
int bs(int x)
{
    int l = 1;
    int r = n;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (dp[mid] < a[x])
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        h[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = h[a[i]];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = a[1];
    ans = 1;
    for (int i = 2; i <= n; i++)
    {
        now = bs(i) + 1;
        if (dp[now] > a[i])
            dp[now] = a[i];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}