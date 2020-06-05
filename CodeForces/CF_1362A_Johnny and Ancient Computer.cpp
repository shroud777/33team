
// Problem : A. Johnny and Ancient Computer
// Contest : Codeforces - Codeforces Round #647 (Div. 2) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1362/problem/A
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
        ll a, b, d, cnt;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (b % a != 0)
        {
            cout << "-1" << endl;
            continue;
        }
        d = b / a;
        cnt = 0;
        while (d && d % 2 == 0)
        {
            d /= 2;
            cnt++;
        }
        if (d < 2)
            cout << (cnt / 3) + (cnt % 3 / 2) + (cnt % 3 % 2) << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}