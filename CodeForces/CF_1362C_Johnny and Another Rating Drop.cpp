
// Problem : C. Johnny and Another Rating Drop
// Contest : Codeforces - Codeforces Round #647 (Div. 2) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1362/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
        ll x, ans;
        cin >> x;
        ans = 0;
        for (ll i = 1; i <= x; i *= 2)
            ans += x / i;
        cout << ans << endl;
    }
    return 0;
}