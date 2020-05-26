#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n, k, a[50], b[50];
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = 1, j = n; i <= k; i++, j--)
        {
            sum += max(0, b[j] - a[i]);
        }
        cout << sum << endl;
    }
    return 0;
}