#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
string a, b;
int nxt[1000005][30];
int last[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    memset(last, -1, sizeof(last));
    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            nxt[i][j] = last[j];
        }
        last[a[i] - 'a'] = i;
    }
    cin >> t;
    while (t--)
    {
        cin >> b;
        int p = last[b[0] - 'a'];
        bool flag = ~p;
        for (int i = 1; i < b.length(); i++)
        {
            p = nxt[p][b[i] - 'a'];
            if (p == -1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}