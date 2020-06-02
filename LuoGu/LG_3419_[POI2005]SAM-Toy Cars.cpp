#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, p;
int a[500005];
int nxt[500005];
int now[100005];
struct Point
{
    int x;
    bool operator<(const Point &a) const
    {
        return nxt[x] < nxt[a.x];
    }
};
priority_queue<Point> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> p;
    for (int i = 1; i <= p; i++)
        cin >> a[i];
    //初始化nxt
    for (int i = 1; i <= n; i++)
        now[i] = p + 1;
    for (int i = p; i >= 1; i--)
    {
        nxt[i] = now[a[i]];
        now[a[i]] = i;
    }
    //开始贪心模拟
    int ans = 0, num = 0;
    memset(now, false, sizeof(now));
    for (int i = 1; i <= p; i++)
    {
        if (now[a[i]])
        {
            q.push(Point{i});
        }
        else
        {
            if (num >= k)
            {
                Point h = q.top();
                q.pop();
                now[a[h.x]] = false;
                num--;
            }
            q.push(Point{i});
            now[a[i]] = true;
            num++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}