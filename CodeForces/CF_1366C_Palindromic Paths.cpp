
// Problem : C. Palindromic Paths
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ans;
int g[35][35];
int cnt0[70], cnt1[70];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(cnt0, 0, sizeof(cnt0));
        memset(cnt1, 0, sizeof(cnt1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> g[i][j];
                cnt0[min(i - 1 + j - 1, abs(n - i) + abs(m - j))] += g[i][j] ^ 1;
                cnt1[min(i - 1 + j - 1, abs(n - i) + abs(m - j))] += g[i][j];
            }
        ans = 0;
        for (int i = 0; i < (n + m - 1) / 2; i++)
        {
            ans += min(cnt1[i], cnt0[i]);
        }
        cout << ans << endl;
    }
    return 0;
}