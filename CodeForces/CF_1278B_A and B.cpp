#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a, b, rem, sum[50005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    sum[0] = 0;
    for (int i = 1; i <= 50000; ++i)
        sum[i] = sum[i - 1] + i;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        rem = a - b;
        int ans = lower_bound(sum, sum + 50000 + 1, rem) - sum;
        if ((sum[ans] - rem) % 2 == 1)
            if (ans % 2 == 1)
                cout << ans + 2 << endl;
            else
                cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}