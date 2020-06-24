
// Problem : 魔咒词典
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=1880
// Memory Limit : 32 MB
// Time Limit : 8000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull h(string s)
{
    ull ans = 0;
    for (int i = 0; i < s.length(); i++)
        ans = ans * 131 + s[i];
    return ans;
}

map<ull, int> x;
map<ull, int>::iterator it;
string ts, s1, s2;
char s[200000][90];
int tot, ans;
ull hts;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    tot = 0;
    while (getline(cin, ts))
    {
        if (ts == "@END@")
            break;
        int pos;
        for (int i = 1; i < ts.length(); i++)
            if (ts[i] == ']')
                pos = i;
        s1 = ts.substr(0, pos + 1);
        s2 = ts.substr(pos + 2);
        for (int i = 0; i < s1.length(); i++)
            s[tot][i] = s1[i];
        s[tot++][s1.length()] = '\0';
        for (int i = 0; i < s2.length(); i++)
            s[tot][i] = s2[i];
        s[tot++][s2.length()] = '\0';
        x[h(s1)] = tot - 1;
        x[h(s2)] = tot - 2;
    }
    int t;
    cin >> t;
    getline(cin, ts);
    while (t--)
    {
        getline(cin, ts);
        hts = h(ts);
        it = x.find(hts);
        if (it != x.end())
        {

            ans = x[hts];
            if (s[ans][0] == '[')
            {
                for (int i = 1; s[ans][i] != ']'; i++)
                    cout << s[ans][i];
                cout << endl;
            }
            else
                cout << s[ans] << endl;
        }
        else
            cout << "what?" << endl;
    }
    return 0;
}