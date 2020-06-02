#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 11000000 * 2 + 3;
int n, P[MAXN+5];
string tempS, s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> tempS;
    //build
    s += "^", s += "#";
    for (int i = 0; i < tempS.length(); i++)
        s += tempS[i], s += "#";
    s += "$";
    n = s.length();
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
    //ans
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, P[i]);
    cout << ans << endl;
    return 0;
}