
// Problem : How many
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=2609
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int min_cirstr(const string &s)
{
    int k = 0, i = 0, j = 1, n = s.length();
    while (k < n && i < n && j < n)
    {
        if (s[(i + k) % n] == s[(j + k) % n])
        {
            k++;
        }
        else
        {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j)
                i++;
            k = 0;
        }
    }
    return min(i, j);
}
int n;
string s, t;
set<string> cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        cnt.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            int x = min_cirstr(s);
            t = s.substr(x, s.length() - x);
            t += s.substr(0, x);
            cnt.insert(t);
        }
        cout << cnt.size() << endl;
    }
    return 0;
}