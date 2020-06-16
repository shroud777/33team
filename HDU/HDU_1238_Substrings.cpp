
// Problem : Substrings
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=1238
// Memory Limit : 65 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
string s[105], now;
int nxt[105];
void gen_nxt(const string &t)
{
    nxt[0] = 0;
    for (int i = 1; i < t.length(); i++)
    {
        int j = nxt[i - 1];
        while (j && t[i] != t[j])
            j = nxt[j - 1];
        if (t[i] == t[j])
            j++;
        nxt[i] = j;
    }
}
//find t from s, need gen_nxt for t before
bool kmp_find(const string &s, const string &t)
{
    for (int i = 0, j = 0; i < s.length();)
    {
        if (s[i] == t[j])
            i++, j++;
        else if (j == 0)
            i++;
        else
            j = nxt[j - 1];
        if (j == t.length())
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }
        int ans = 0;
        for (int len = 1; len <= s[1].length(); len++)
        {
            if (ans < len - 1)
                break;
            for (int pos = 0; pos + len - 1 < s[1].length(); pos++)
            {
                now = s[1].substr(pos, len);
                gen_nxt(now);
                bool flag = true;
                for (int i = 2; i <= n; i++)
                {
                    if (!kmp_find(s[i], now))
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    reverse(now.begin(), now.end());
                    gen_nxt(now);
                    flag = true;
                    for (int i = 2; i <= n; i++)
                    {
                        if (!kmp_find(s[i], now))
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    ans = len;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}