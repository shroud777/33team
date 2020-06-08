
// Problem : The Frog's Games
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=4004
// Memory Limit : 65 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, n, m;
ll a[500005];
bool check(int x)
{
    int cnt = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - last > x)
            return false;
        if (a[i + 1] - a[i] > x)
            return false;
        if (a[i + 1] - last > x)
        {
            cnt++;
            last = a[i];
        }
    }
    return cnt < m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> l >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        a[n + 1] = l;
        ll l = 0;
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