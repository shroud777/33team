
// Problem : Can you solve this equation?
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=2199
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double f(double x, double y)
{
    return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6 - y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        double y;
        cin >> y;
        if (f(0, y) > 0 || f(100, y) < 0)
        {
            cout << "No solution!" << endl;
            continue;
        }
        double l = 0;
        double r = 100;
        while (r - l >= 1e-6)
        {
            double mid = (l + r) / 2;
            if (f(mid, y) > 0)
                r = mid;
            else
                l = mid;
        }
        cout << fixed << setprecision(4) << r << endl;
    }
    return 0;
}