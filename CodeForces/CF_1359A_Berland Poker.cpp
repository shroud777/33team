
// Problem : A. Berland Poker
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int A = min(n / k, m);
        int B = (m - A + k - 2) / (k - 1);
        cout << A - B << endl;
    }
    return 0;
}