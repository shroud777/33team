#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
string s;
struct P
{
    string name;
    int v;
} a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].name;
        cin >> s;
        a[i].v = 0;
        for (int j = 0; j + 2 < s.length(); j++)
            a[i].v += (s[j] == 's' && s[j + 1] == 'o' && s[j + 2] == 's');
    }
    int maxv = a[1].v;
    for (int i = 1; i <= n; i++)
        if (a[i].v > maxv)
            maxv = a[i].v;
    for (int i = 1; i <= n; i++)
        if (a[i].v == maxv)
            cout << a[i].name << " ";
    cout << endl;
    cout << maxv << endl;
    return 0;
}