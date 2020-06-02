#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, d, k;
ll a[1005];
ll count(ll x)
{
    int res = 0;
    while (x > 0)
    {
        res++;
        x -= (x & (-x)); //x-=lowbit(x);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        a[i] = 0;
        for (int j = 1; j <= num; j++)
        {
            int now;
            cin >> now;
            a[i] |= 1 << (now - 1);
        }
    }
    //枚举每种疾病组合
    int ans = 0;
    for (int i = 0; i <= (1ll << d) - 1; i++)
    {
        if (count(i) > k)
            continue;
        int now = 0;
        for (int j = 1; j <= n; j++)
            if ((i | a[j]) == i)
                now++;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}