#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, k;
ll a[200005], sum[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a[0] = sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        ll ans = sum[2 * k], last = sum[k];
        for (int i = k + 1; i + k - 1 <= n; i++)
        {
            ans = max(ans, last + sum[i + k - 1] - sum[i - 1]);
            last = max(last, sum[i] - sum[i - k]);
        }
        cout << ans << endl;
    }
    return 0;
}