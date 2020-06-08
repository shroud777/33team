
// Problem : Aggressive cows
// Contest : POJ - USACO 2005 February Gold
// URL : http://poj.org/problem?id=2456
// Memory Limit : 65 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll n, c;
ll a[100005];
bool check(ll x)
{
    int cnt = 1, last = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - last >= x)
        {
            cnt++;
            last = a[i];
        }
    }
    return cnt >= c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 0;
    ll r = 1000000000;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}