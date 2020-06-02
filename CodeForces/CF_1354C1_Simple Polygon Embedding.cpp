#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
double n, ans;
const double PI = 3.1415926535897932384626433832;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 1 / tan(PI / (2 * n));
        cout<<fixed<<setprecision(9) << ans << endl;
    }
    return 0;
}