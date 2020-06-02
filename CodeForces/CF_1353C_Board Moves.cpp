#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, num, ans;
        cin >> n;
        ans = 0;
        for (ll i = 1, j = 8; i <= n / 2; i++, j += 8)
        {
            ans += i * j;
        }
        cout << ans << endl;
    }
    return 0;
}