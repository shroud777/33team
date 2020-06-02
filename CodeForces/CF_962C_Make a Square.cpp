#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, len, ans, d[11];
ll getnum(ll x)
{
    ll xlen = 0;
    for (int i = x; i > 0; i >>= 1)
        xlen++;
    if (d[xlen - 1] == 0)
        return -1;
    ll sum = 0;
    //i~2^j
    for (int i = 1 << (len - 1), j = len - 1; i > 0; i >>= 1, j--)
        if (x & i)
            sum = sum * 10 + d[j];
    ll sqrtsum = sqrt(sum);
    if (sqrtsum * sqrtsum != sum)
        return -1;

    xlen = 0;
    for (int i = x; i > 0; i -= (i & (-i)))
        xlen++;
    return len - xlen;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    len = 0;
    while (n > 0)
    {
        d[len++] = n % 10;
        n /= 10;
    }
    ans = -1;
    for (ll i = 1; i < (1ll << len); i++)
    {
        ll now = getnum(i);
        if (now == -1)
            continue;
        if (ans == -1 || now < ans)
            ans = now;
    }
    cout << ans << endl;
    return 0;
}