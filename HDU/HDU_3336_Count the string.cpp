
// Problem : Count the string
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=3336
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
string s;
int nxt[200000];
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
    cin >> T;
    while (T--)
    {
        cin >> n >> s;
        gen_nxt(s);
        int ans = n % 10007;
        for (int i = 1; i < n; i++)
            ans += (nxt[i] > 0);
        cout << ans % 10007 << endl;
    }
    return 0;
}