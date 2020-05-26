#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a, r, m, h[100005], ans, L, R;
ll check(int x)
{
    ll res = 0, small = 0, big = 0;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] < x)
            small += x - h[i];
        if (h[i] > x)
            big += h[i] - x;
    }
    if (m >= a + r)
        res = small * a + big * r;
    else if (big >= small)
        res = small * m + (big - small) * r;
    else
        res = big * m + (small - big) * a;
    ans = min(ans, res);
    //cout << x << " " << small << " " << big << " " << res << " " << ans << endl;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> r >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    sort(h + 1, h + n + 1);
    L = 0, R = h[n], ans = ~0ull >> 1;
    while (L <= R)
    {
        ll x = L + R >> 1;
        ll y = x + R + 1 >> 1;
        //cout << "--- " << L << " " << x << " " << y << " " << R << endl;
        if (check(x) < check(y))
        {
            R = y - 1;
        }
        else
        {
            L = x + 1;
        }
        //cout << "=== " << L << " " << R << endl;
    }
    cout << ans << endl;
    return 0;
}