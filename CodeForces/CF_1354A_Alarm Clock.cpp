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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <= b)
        {
            cout << b << endl;
            continue;
        }
        if (d >= c)
        {
            cout << -1 << endl;
            continue;
        }
        ll cnt = (a - b) / (c - d) + ((a - b) % (c - d) > 0);
        cout << b + cnt * c << endl;
    }

    return 0;
}