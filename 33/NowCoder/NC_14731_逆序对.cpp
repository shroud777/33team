#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P = 1000000007;
ll n;
ll quick_pow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    cout << (((n % P) * ((n - 1) % P)) % P * quick_pow(2, n - 3)) % P << endl;
    return 0;
}