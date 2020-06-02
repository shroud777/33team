#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, s;
struct Edge
{
    ll to, w;
};
vector<Edge> e[100005];
ll book[100005];
void dfs(int u, int fa)
{
    ll num = e[u].size();
    bool flag = true;
    book[u] = 0;
    for (int i = 0; i < num; i++)
    {
        ll v = e[u][i].to;
        ll w = e[u][i].w;
        if (v == fa)
            continue;
        flag = false;
        dfs(v, u);
        book[u] += min(book[v], w);
    }
    if (flag)
        book[u] = ~0ull >> 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(Edge{v, w});
        e[v].push_back(Edge{u, w});
    }
    dfs(s, 0);
    cout << book[s] << endl;
    return 0;
}