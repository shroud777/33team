
// Problem : C. Edgy Trees
// Contest : Codeforces - Codeforces Round #548 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1139/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
const ll MOD = 1000000007;
int n;
ll k;
int fa[MAXN + 5];
ll cnt[MAXN + 5];
int findFa(int x)
{
    return fa[x] == x ? x : fa[x] = findFa(fa[x]);
}
ll qpow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        fa[i] = i, cnt[i] = 1;
    for (int i = 1; i < n; i++)
    {
        int u, v, col;
        cin >> u >> v >> col;
        if (!col)
        {
            int faU = findFa(u);
            int faV = findFa(v);
            if (faU != faV)
            {
                fa[faV] = faU;
                cnt[faU] += cnt[faV];
            }
        }
    }
    ll ans = qpow(n, k, MOD);
    ll sub = 0;
    for (int i = 1; i <= n; i++)
        if (fa[i] == i)
            sub = (sub + qpow(cnt[i], k, MOD)) % MOD;
    ans -= sub;
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;
    return 0;
}
