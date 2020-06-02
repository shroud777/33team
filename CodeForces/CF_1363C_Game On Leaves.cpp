#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, x, d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        d = 0;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            d += (u == x || v == x);
        }
        if (d < 2 || n % 2 == 0)
            cout << "Ayush" << endl;
        else
            cout << "Ashish" << endl;
    }
    return 0;
}