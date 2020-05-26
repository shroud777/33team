#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, ans, a[200005], l, r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        ans = 0;
        for (int l = 1, r; l <= n; l = r + 1)
        {
            r = l + a[l] - 1;
            while (r <= n && r - l + 1 < a[r])
                r = l + a[r] - 1;
            if (r <= n)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
