
// Problem : Girls' research
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=3294
// Memory Limit : 65 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
string tempS, s;
int P[400005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> c && cin >> tempS)
    {
        //build tempS->s
        s = "^";
        s += "#";
        for (int i = 0; i < tempS.length(); i++)
            s += tempS[i], s += "#";
        s += "$";
        int n = s.length();
        //manacher
        int C, R;
        C = R = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int i_mirror = 2 * C - i; //C - i_mirror = i - C
            if (R > i)
                P[i] = min(R - i, P[i_mirror]);
            else
                P[i] = 0;
            while (s[i + P[i] + 1] == s[i - P[i] - 1])
            {
                P[i]++;
            }
            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
        }
        int pos = -1;
        for (int i = 1; i < n - 1; i++)
            if (P[i] >= 2 && (pos == -1 || P[i] > P[pos]))
                pos = i;
        if (pos == -1)
        {
            cout << "No solution!" << endl;
        }
        else
        {
            int l = (pos - P[pos] + 1) / 2 - 1;
            int r = l + P[pos] - 1;
            cout << l << " " << r << endl;
            for (int i = l; i <= r; i++)
            {
                int x = tempS[i] - 'a';
                x -= (c - 'a');
                if (x < 0)
                    x += 26;
                cout << (char)(x + 'a');
            }
            cout<<endl;
        }
    }
    return 0;
}