
// Problem : Theme Section
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=4763
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
int nxt[1000005];
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> s;
        gen_nxt(s);
        int ans = 0;
        for (int i = 1; i < s.length() - 1; i++)
            ans = max(ans, nxt[i]);
        ans = min(ans, nxt[s.length() - 1]);
        cout << ans << endl;
    }
    return 0;
}