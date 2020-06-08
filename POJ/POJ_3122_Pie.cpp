
// Problem : Pie
// Contest : POJ - Northwestern Europe 2006
// URL : http://poj.org/problem?id=3122
// Memory Limit : 65 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const double pi = 3.14159265358979323;
ll n;
double f;
double a[10005];
bool check(double x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += a[i] / x;
    }
    return cnt >= f;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lf", &n, &f);
        f++;
        double l = 0;
        double r = 0;
        double ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &a[i]);
            a[i] *= a[i];
            r = max(r, a[i]);
        }
        while (r - l > 1e-6)
        {
            double mid = (l + r) / 2;
            if (check(mid))
            {
                l = mid + 1e-7;
                ans = mid;
            }
            else
            {
                r = mid - 1e-7;
            }
        }
        printf("%.4f\n",ans * pi);
    }
    return 0;
}