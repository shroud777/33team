
// Problem : Can you find it?
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=2141
// Memory Limit : 32 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, l, n, m, k, x;
int a[505], b[505], c[505];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    t = 0;
    while (cin >> l >> n >> m && ++t)
    {
        for (int i = 1; i <= l; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= m; i++)
            cin >> c[i];
        v.clear();
        for (int i = 1; i <= l; i++)
            for (int j = 1; j <= n; j++)
                v.push_back(a[i] + b[j]);
        sort(v.begin(), v.end());
        cin >> k;
        cout << "Case " << t << ":" << endl;
        while (k--)
        {
            cin >> x;
            bool flag = false;
            for (int i = 1; i <= m; i++)
                if (binary_search(v.begin(), v.end(), x - c[i]))
                    flag = true;
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
