#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, Q;
vector<int> g[100005];         //g[i]存储所有与i相连的点
int odd[100005], even[100005]; //odd[i]，从1到i的最短奇数路径的长度
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> Q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(odd, 0x3f, sizeof(odd));
    memset(even, 0x3f, sizeof(even));
    even[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            //u->i
            bool flag = false; //是否有优化
            if (odd[u] + 1 < even[v])
            {
                even[v] = odd[u] + 1;
                flag = true;
            }
            if (even[u] + 1 < odd[v])
            {
                odd[v] = even[u] + 1;
                flag = true;
            }
            if (flag)
                q.push(v);
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        int a, L;
        cin >> a >> L;
        if (L % 2 == 0 && even[a] <= L)
            cout << "Yes" << endl;
        else if (L % 2 == 1 && odd[a] <= L)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}