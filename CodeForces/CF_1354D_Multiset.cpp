#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int c[1000005];

int lowbit(int x)
{
    return x & (-x);
}
void add(int i, int k)
{
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}
int sumof(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}
void del(int x)
{
    int l = 1, r = n, ans;
    while (l <= r)
    {
        int mid = l + r >> 1;
        //cout << l << " " << r << " " << mid;
        if (sumof(mid) >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        //cout << " " << sumof(mid) << " " << ans << endl;
    }
    add(ans, -1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x, 1);
    }
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            add(x, 1);
        }
        else
        {
            x = -x;
            del(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}