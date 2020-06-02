#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct CCC
{
    int l, r, len;
    CCC(int x, int y) : l(x), r(y), len(r - l + 1) {}
    bool operator<(const CCC &x) const
    {
        if (x.len != len)
            return len < x.len;
        return l > x.l;
    }
};
priority_queue<CCC> q;

int a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        q.push(CCC(1, n));
        int cnt = 0;
        while (q.size())
        {
            CCC x = q.top();
            q.pop();
            int mid;
            if ((x.r - x.l + 1) % 2 == 1)
                mid = x.l + x.r >> 1;
            else
                mid = x.l + x.r - 1 >> 1;
            //cout << x.l << " " << x.r << " " << mid << endl;
            a[mid] = ++cnt;
            if (x.l < mid)
                q.push(CCC(x.l, mid - 1));
            if (mid < x.r)
                q.push(CCC(mid + 1, x.r));
        }
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
                cout << " ";
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}