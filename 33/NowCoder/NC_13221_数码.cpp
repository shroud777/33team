#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L, R, r[20] = {}, l[20] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> R;
    //1~R => r[]
    for (ll i = 1; i * i <= R; i++)
    {
        for (ll num = 1; num <= R; num *= 10) //位数
            for (int k = 1; k <= 9; k++)      //首位
                r[k] += max(min(num * (k + 1) - 1, R / i) - max(num * k, i + 1) + 1, 0ll);
        for (int x = i; x; x /= 10)
        {
            if (x < 10)
            {
                r[x] += R / i - i + 1;
                break;
            }
        }
    }
    //1~L-1 => l[]
    L--;
    for (ll i = 1; i * i <= L; i++)
    {
        for (ll num = 1; num <= L; num *= 10) //位数
            for (int k = 1; k <= 9; k++)      //首位
                l[k] += max(min(num * (k + 1) - 1, L / i) - max(num * k, i + 1) + 1, 0ll);
        for (int x = i; x; x /= 10)
        {
            if (x < 10)
            {
                l[x] += L / i - i + 1;
                break;
            }
        }
    }
    //ans
    for (int i = 1; i <= 9; i++)
        cout << r[i] - l[i] << endl;
    return 0;
}
