
// Problem : B. Johnny and His Hobbies
// Contest : Codeforces - Codeforces Round #647 (Div. 2) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1362/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[1050], b[1050];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int maxa = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int k = -1;
        for (int i = 1; i <= (1 << 11) - 1; i++)
        {
            for (int j = 1; j <= n; j++)
                b[j] = a[j] ^ i;
            sort(b + 1, b + n + 1);
            bool flag = true;
            for (int j = 1; j <= n; j++)
            {
                if (b[j] != a[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                k = i;
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}