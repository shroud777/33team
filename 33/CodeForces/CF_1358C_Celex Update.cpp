#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, a, b, x, y, w, h, L, num, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> x >> y;
        w = x - a;
        h = y - b;
        if (w == 0 || h == 0)
        {
            cout << 1 << endl;
            continue;
        }
        L = min(w, h);
        //1+2+3+...+L+L+L+...+3+2+1
        num = w + h - 1;
        ans = (L - 1) * L + L * (num - (L - 1) * 2);
        cout << ans + 1 << endl;
    }
    return 0;
}