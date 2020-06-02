#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s1, s2;
//dp[i][j][k][l] s1[i]~s1[j]+s2[k]~s2[l]能否组成回文串
int dp[55][55][55][55];
int len1, len2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int ans = 0;
        cin >> s1 >> s2;
        len1 = s1.length();
        len2 = s2.length();
        for (int l1 = 0; l1 <= len1; l1++)
            for (int l2 = 0; l2 <= len2; l2++)
                for (int p1 = 1; p1 + l1 - 1 <= len1; p1++)
                    for (int p2 = 1; p2 + l2 - 1 <= len2; p2++)
                    {
                        int q1 = p1 + l1 - 1;
                        int q2 = p2 + l2 - 1;
                        if (l1 + l2 <= 1)
                        {
                            dp[p1][q1][p2][q2] = true;
                        }
                        else
                        {
                            dp[p1][q1][p2][q2] = false;
                            if (l1 >= 2)
                                dp[p1][q1][p2][q2] |= (dp[p1 + 1][q1 - 1][p2][q2] && s1[p1 - 1] == s1[q1 - 1]);
                            if (l1 && l2)
                                dp[p1][q1][p2][q2] |= (dp[p1 + 1][q1][p2][q2 - 1] && s1[p1 - 1] == s2[q2 - 1]);
                            if (l1 && l2)
                                dp[p1][q1][p2][q2] |= (dp[p1][q1 - 1][p2 + 1][q2] && s2[p2 - 1] == s1[q1 - 1]);
                            if (l2 >= 2)
                                dp[p1][q1][p2][q2] |= (dp[p1][q1][p2 + 1][q2 - 1] && s2[p2 - 1] == s2[q2 - 1]);
                        }
                        if (dp[p1][q1][p2][q2])
                        {
                            ans = max(ans, q1 - p1 + 1 + q2 - p2 + 1);
                        }
                    }
        cout << ans << endl;
    }
    return 0;
}