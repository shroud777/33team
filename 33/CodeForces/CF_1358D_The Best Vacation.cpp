#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, d[400005], sumd[400005], maxd, maxsumd, p, q, nowd, nowsumd, ans, r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    maxd = 0;
    maxsumd = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sumd[i] = (1 + d[i]) * d[i] / 2;
        maxd = max(maxd, d[i]);
        maxsumd = max(maxsumd, sumd[i]);
    }
    if (x <= maxd)
    {
        cout << ((maxd + maxd - x + 1) * x / 2) << endl;
        return 0;
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        d[i] = d[i - n];
        sumd[i] = sumd[i - n];
    }
    n *= 2;
    d[0] = d[n];
    sumd[0] = sumd[n];
    ans = 0;
    p = q = n;
    nowd = d[n];
    nowsumd = sumd[n];
    while (nowd + d[p - 1] < x)
    {
        p--;
        nowd += d[p];
        nowsumd += sumd[p];
    }
    while (1)
    {
        r = x - nowd;
        ans = max(ans, nowsumd + r * (d[p - 1] + d[p - 1] - r + 1) / 2);
        nowd -= d[q];
        nowsumd -= sumd[q];
        q--;
        while (p - 1 >= 0 && nowd + d[p - 1] < x)
        {
            p--;
            nowd += d[p];
            nowsumd += sumd[p];
        }
        if (p == 0)
            break;
    }
    cout << ans << endl;
    return 0;
}
