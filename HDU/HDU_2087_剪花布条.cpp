
// Problem : 剪花布条
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=2087
// Memory Limit : 32 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;
int nxt[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s && s != "#")
    {
        cin >> t;
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
        int cnt = 0;
        for (int i = 0, j = 0; i < s.length();)
        {
            if (s[i] == t[j])
                i++, j++;
            else if (j == 0)
                i++;
            else
                j = nxt[j - 1];
            if (j == t.length())
            {
                cnt++;
                j = 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}