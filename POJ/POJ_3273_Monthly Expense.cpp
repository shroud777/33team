
// Problem : Monthly Expense
// Contest : POJ - USACO 2007 March Silver
// URL : http://poj.org/problem?id=3273
// Memory Limit : 65 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
typedef long long ll;

ll n, m;
ll a[100005];
bool check(ll x)
{
    ll cnt = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        now += a[i];
        if (now + a[i + 1] > x)
        {
            cnt++;
            now = 0;
        }
    }
    cnt += (now > 0);
    return cnt <= m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        ll l = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            l = max(l, a[i]);
        }
        ll r = 1000000000;
        ll ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}