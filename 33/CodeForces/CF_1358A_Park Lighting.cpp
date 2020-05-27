#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ans = n * m / 2;
        if (n * m % 2)
            ans++;
        cout << ans << endl;
    }
    return 0;
}