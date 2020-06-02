#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> a[100005];
int n, q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            if (a[x].size() <= y)
                a[x].resize(y + 1);
            a[x][y] = k;
        }
        else
        {
            cin >> x >> y;
            cout << a[x][y] << endl;
        }
    }
    return 0;
}