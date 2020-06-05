
// Problem : A. Minimal Square
// Contest : Codeforces - Codeforces Round #644 (Div. 3)
// URL : https://codeforces.com/contest/1360/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
        int a, b, A, B;
        cin >> a >> b;
        int ans = max(min(a, b) * 2, max(a, b));
        cout << ans * ans << endl;
    }
    return 0;
}