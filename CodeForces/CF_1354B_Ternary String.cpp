#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int cnt[5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int l, r;
        l = r = 0;
        cnt[1] = cnt[2] = cnt[3] = 0;
        cnt[s[0] - '0']++;
        while (!(cnt[1] && cnt[2] && cnt[3]) && r + 1 < s.length())
        {
            r++;
            cnt[s[r] - '0']++;
        }
        if (!(cnt[1] && cnt[2] && cnt[3]))
        {
            cout << 0 << endl;
            continue;
        }
        while (cnt[s[l] - '0'] > 1)
        {
            cnt[s[l] - '0']--;
            l++;
        }
        //cout << l << " " << r << endl;
        int ans = r - l + 1;
        for (r++; r < s.length(); r++)
        {
            cnt[s[r] - '0']++;
            while (cnt[s[l] - '0'] > 1)
            {
                cnt[s[l] - '0']--;
                l++;
            }
            ans = min(ans, r - l + 1);
        }
        cout << ans << endl;
    }
    return 0;
}