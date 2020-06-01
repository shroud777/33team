#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, k;
int fset[1005];   //fset[x]存储x在哪一个集合里
set<int> s[1005]; //s[i] 第i个集合
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(fset, 0, sizeof(fset));
        for (int i = 1; i <= k; i++)
        {
            int nn, x;
            cin >> nn;
            s[i].clear();
            for (int j = 1; j <= nn; j++)
            {
                cin >> x;
                fset[x] = i;
                s[i].insert(x);
            }
        }
        int maxA, maxAA, l, r;
        cout << "? " << n;
        for (int i = 1; i <= n; i++)
            cout << " " << i;
        cout << endl;
        cout.flush();
        cin >> maxA;
        l = 1;
        r = n;
        while (l < r)
        {
            //cout << "--" << l << " " << r << endl;
            int mid = l + r >> 1, nowmax;
            cout << "? " << mid - l + 1;
            for (int i = l; i <= mid; i++)
                cout << " " << i;
            cout << endl;
            cout.flush();
            cin >> nowmax;
            if (nowmax == maxA)
                r = mid;
            else
                l = mid + 1;
        }
        if (fset[l] != 0)
        {
            cout << "? " << n - s[fset[l]].size();
            for (int i = 1; i <= n; i++)
                if (!s[fset[l]].count(i))
                    cout << " " << i;
            cout << endl;
            cout.flush();
            cin >> maxAA;
        }
        cout << "!";
        for (int i = 1; i <= k; i++)
            if (i != fset[l])
                cout << " " << maxA;
            else
                cout << " " << maxAA;
        cout << endl;
        cout.flush();
        string ts;
        cin >> ts; //ofcourseCorrect
    }
    return 0;
}