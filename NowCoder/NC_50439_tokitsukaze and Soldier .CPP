#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
priority_queue<ll> q;
struct Soldier
{
    ll v, s;
} a[100005];
bool cmp(const Soldier &a, const Soldier &b)
{
    return a.s > b.s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v >> a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);
    ll now, ans;
    now = ans = 0;
    for (int i = 1; i <= n; i++)
    {
        now += a[i].v;
        q.push(-(a[i].v));
        while (q.size() > a[i].s)
        {
            now -= (-q.top());
            q.pop();
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}