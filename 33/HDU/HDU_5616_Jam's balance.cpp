#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int N, wi, M, k;
bool dp[4005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> N;
        memset(dp, false, sizeof(dp));
        dp[0 + 2000] = true;
        for (int i = 1; i <= N; i++)
        {
            cin >> wi;
            //wi
            for (int i = 2000; i - wi >= -2000; i--)
                dp[i + 2000] = dp[i + 2000] || dp[i + 2000 - wi];
            //-wi
            for (int i = -2000; i + wi <= 2000; i++)
                dp[i + 2000] = dp[i + 2000] || dp[i + 2000 + wi];
        }
        cin >> M;
        for (int i = 1; i <= M; i++)
        {
            cin >> k;
            if (0 <= k + 2000 && k + 2000 <= 4000 && dp[k + 2000])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}