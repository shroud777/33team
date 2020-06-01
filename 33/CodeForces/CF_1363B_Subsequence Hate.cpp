#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int t;
int L[1005][2];
int R[1005][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> s;
        int ans = s.length();
        if (s.length() < 3)
        {
            cout << 0 << endl;
            continue;
        }
        s = "#" + s + "#";
        int len = s.length();
        L[0][0] = L[0][1] = R[len - 1][0] = R[len - 1][1] = 0;
        for (int i = 1; i < len; i++)
        {
            L[i][0] = L[i - 1][0] + (s[i] == '0');
            L[i][1] = L[i - 1][1] + (s[i] == '1');
        }
        for (int i = len - 2; i >= 0; i--)
        {
            R[i][0] = R[i + 1][0] + (s[i] == '0');
            R[i][1] = R[i + 1][1] + (s[i] == '1');
        }
        for (int i = 0; i < len; i++)
        {
            ans = min(ans, L[i][0] + R[i + 1][0]);
            ans = min(ans, L[i][0] + R[i + 1][1]);
            ans = min(ans, L[i][1] + R[i + 1][1]);
            ans = min(ans, L[i][1] + R[i + 1][0]);
        }
        cout << ans << endl;
    }
    return 0;
}