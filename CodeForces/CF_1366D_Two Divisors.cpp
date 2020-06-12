
// Problem : D. Two Divisors
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 10000000 + 5;
int n, a[MAXN], d1[MAXN], d2[MAXN];
int min_pri[MAXN];
int pcnt;
bool vis[MAXN];
int pri[MAXN];
void init()
{
    pcnt = 0;
    for (int i = 2; i < MAXN; ++i)
    {
        if (!vis[i])
        {
            pri[pcnt++] = i;
            min_pri[i] = i;
        }
        for (int j = 0; j < pcnt; ++j)
        {
            if (1ll * i * pri[j] >= MAXN)
                break;
            vis[i * pri[j]] = 1;
            min_pri[i * pri[j]] = pri[j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> n;
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < 6)
            continue;
        int minp = min_pri[a[i]];
        d1[i] = 1;
        while (a[i] % minp == 0)
        {
            d1[i] *= minp;
            a[i] /= minp;
        }
        if (a[i] > 1)
            d2[i] = a[i];
        else
            d2[i] = d1[i] = -1;
    }
    for (int i = 1; i <= n; i++)
        cout << d1[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << d2[i] << " ";
    cout << endl;
    return 0;
}