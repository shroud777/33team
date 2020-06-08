
// Problem : Flyer
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=4768
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[20005], b[20005], c[20005];
ll check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ll R = min(x, b[i]);
        if (R >= a[i])
            cnt += (R - a[i]) / c[i] + 1;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        ll l = 0;
        ll r = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            r = max(r, b[i]);
        }
        ll ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll now = check(mid);
            if (now % 2 == 1)
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (~ans)
            cout << ans << " " << check(ans) - check(ans - 1) << endl;
        else
            cout << "DC Qiang is unhappy." << endl;
    }
    return 0;
}