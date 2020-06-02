#include <iostream>
using namespace std;
typedef long long ll;

int t;
ll M, H, A, B, ans;
ll _qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * a) % M;
        b /= 2;
        a = (a * a) % M;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> M >> H;
        ans = 0;
        for (int i = 1; i <= H; i++)
        {
            cin >> A >> B;
            ans = (ans + _qpow(A, B)) % M;
        }
        cout << ans << endl;
    }
    return 0;
}