
// Problem : B. Shuffle
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x, m;
struct Line
{
    ll l, r;
} a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> m;
        for (int i = 1; i <= m; i++)
            cin >> a[i].l >> a[i].r;
        ll l = x;
        ll r = x;
        for (int j = 1; j <= m; j++)
        {
            if (!(a[j].r < l || r < a[j].l))
            {
                l = min(l, a[j].l);
                r = max(r, a[j].r);
            }
        }
        cout << r - l + 1 << endl;
    }
    return 0;
}