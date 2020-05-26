#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a1, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a1 >> k;
        for (int i = 1; i < k; i++)
        {
            ll maxx = a1 % 10, minx = a1 % 10;
            for (ll x = a1 / 10; x; x /= 10)
            {
                maxx = max(maxx, x % 10);
                minx = min(minx, x % 10);
            }
            if (!minx)
                break;
            a1 += maxx * minx;
        }
        cout<<a1<<endl;
    }
    return 0;
}
