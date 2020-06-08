
// Problem : Drying
// Contest : POJ - Northeastern Europe 2005
// URL : http://poj.org/problem?id=3104
// Memory Limit : 65 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, k;
ll a[100005];
bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
        {
            cnt += (a[i] - x) / (k - 1);
            if ((a[i] - x) % (k - 1))
                cnt++;
        }
    }
    return cnt <= x;
}
int main()
{
    while (~scanf("%lld", &n))
    {

        ll l = 1;
        ll r = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            r = max(r, a[i]);
        }
        scanf("%lld", &k);
        if (k == 1)
        {
            printf("%lld\n", r);
            continue;
        }
        ll ans = l;
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
        printf("%lld\n", ans);
    }
    return 0;
}