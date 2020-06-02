#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, k;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '1')
                sum++;
        int ans = sum;
        for (int i = 0; i < k; i++)
        {
            int now = 0, maxX = 0, one = 0;
            for (int j = i; j < s.length(); j += k)
            {
                if (s[j] == '1')
                    now++, one++;
                else
                    now--;
                if (now < 0)
                    now = 0;
                maxX = max(maxX, now);
            }
            ans = min(ans, sum - maxX);
        }
        cout << ans << endl;
    }
    return 0;
}
