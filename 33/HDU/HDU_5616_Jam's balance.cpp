#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int N, wi, M, k;
bool dp[2005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> N;
        memset(dp, false, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            cin >> wi;
            for (int i = 2000; i - wi >= 0; i--)
                dp[i] = dp[i] || dp[i - wi];
            for (int i = 0; i + wi <= 2000; i++)
                dp[i] = dp[i] || dp[i + wi];
        }
        cin >> M;
        for (int i = 1; i <= M; i++)
        {
            cin >> k;
            if (0 <= k && k <= 2000 && dp[k])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}