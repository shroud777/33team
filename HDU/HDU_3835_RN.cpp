#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll p[40005];
ll n, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i <= 40000; i++)
        p[i] = i * i;
    while (cin >> n)
    {
        ans = 0;
        for (int i = 40000; i >= 0; i--)
        {
            if (p[i] > n)
                continue;
            if (p[i] * 2 < n)
                continue;
            int j = lower_bound(p + 0, p + i + 1, n - p[i]) - p;
            if (p[j] != n - p[i])
                continue;
            if (i == 0 && j == 0)
            {
                ans++;
                continue;
            }
            if (i == 0 || j == 0)
            {
                ans += 4;
                continue;
            }
            if (i == j)
            {
                ans += 4;
                continue;
            }
            ans += 8;
        }
        cout << ans << endl;
    }
    return 0;
}