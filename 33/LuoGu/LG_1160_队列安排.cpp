#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
struct Node
{
    int l, r;
} a[100005];
bool b[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(a, -1, sizeof(a));
    memset(b, true, sizeof(b));
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
        {
            a[i].l = a[k].l;
            a[i].r = k;
            a[a[i].l].r = i;
            a[a[i].r].l = i;
        }
        else
        {
            a[i].l = k;
            a[i].r = a[k].r;
            a[a[i].l].r = i;
            a[a[i].r].l = i;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        b[x] = false;
    }
    int p = 1;
    while (~a[p].l)
        p = a[p].l;
    while (~p)
    {
        if (b[p])
            cout << p << " ";
        p = a[p].r;
    }
    cout << endl;
    return 0;
}