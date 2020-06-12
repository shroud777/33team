
// Problem : P3375 【模板】KMP字符串匹配
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3375
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1, s2;
int nxt[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s1 >> s2;
    nxt[0] = 0;
    for (int i = 1; i < s2.length(); i++)
    {
        int j = nxt[i - 1];
        while (j && s2[i] != s2[j])
            j = nxt[j - 1];
        if (s2[i] == s2[j])
            j++;
        nxt[i] = j;
    }
    int i1 = 0, i2 = 0;
    while (i1 < s1.length())
    {
        if (s1[i1] == s2[i2])
            i1++, i2++;
        else if (i2 == 0)
            i1++;
        else
            i2 = nxt[i2-1];
        if (i2 == s2.length())
        {
            cout << i1 - s2.length() + 1 << endl;
            i2 = nxt[i2 - 1];
        }
    }
    for (int i = 0; i < s2.length(); i++)
        cout << nxt[i] << " ";
    cout << endl;
    return 0;
}