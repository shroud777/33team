#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    if (s < 2 * n)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i < n; i++)
        cout << "2 ";
    cout << s - 2 * (n - 1) << endl
         << 1 << endl;
    return 0;
}