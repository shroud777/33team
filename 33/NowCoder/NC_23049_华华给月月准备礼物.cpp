#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll L[200005];
bool check(int x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += L[i] / x;
    return cnt >= k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    ll l = 1, r = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i];
        r = max(r, L[i]);
    }
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}