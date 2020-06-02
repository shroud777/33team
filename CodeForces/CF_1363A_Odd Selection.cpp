#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, x, odd, even, temp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        odd = even = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            odd += (temp % 2);
            even += ((temp + 1) % 2);
        }
        if (odd == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            x--;
            odd--;
            x -= min(x - x % 2, (odd / 2) * 2);
            if (x <= even)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}