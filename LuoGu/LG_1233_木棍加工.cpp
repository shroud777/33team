
// Problem : P1233 木棍加工
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1233
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Sti
{
    int w, h;
};
int n;
Sti a[5005];
bool cmp(Sti a, Sti b)
{
    return a.h > b.h || a.h == b.h && a.w > b.w;
}
int dp[5005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].h;
    sort(a + 1, a + n + 1, cmp);
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = a[1].w;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int l = 1;
        int r = n;
        int now = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (dp[mid] < a[i].w)
            {
                now = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        now++;
        if (dp[now] > a[i].w)
            dp[now] = a[i].w;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}