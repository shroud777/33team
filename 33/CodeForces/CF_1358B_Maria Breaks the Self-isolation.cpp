#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, a[200005], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        ans = 1;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] <= i)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}