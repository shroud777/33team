#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, sum, ans[30];
ll a[30];
ll count(int x)
{
    ll res = 0;
    //i~2^j
    for (int i = 1, j = 0; i <= x; i <<= 1, j++)
        if (x & i)
            res += a[j];
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            ans[i] = 0;
        }
        for (int p = 0; p < (1 << n); p++)
        {
            ll now = count(p);
            if (now * 2 > sum)
                for (int i = 1, j = 0; i <= p; i <<= 1, j++)
                    if (p & i)
                        if ((now - a[j]) * 2 <= sum)
                            ans[j]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}