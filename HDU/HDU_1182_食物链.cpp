
// Problem : 食物链
// Contest : POJ - Noi 01
// URL : http://poj.org/problem?id=1182
// Memory Limit : 10 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int n, k, d, x, y;
int fa[50005], rnk[50005];
int findFa(int x)
{
    if (x == fa[x])
        return fa[x];
    int y = findFa(fa[x]);
    rnk[x] = (rnk[x] + rnk[fa[x]]) % 3;
    return fa[x] = y;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        rnk[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (x == y && d == 2)
        {
            ans++;
            continue;
        }
        int fx = findFa(x);
        int fy = findFa(y);
        if (fx == fy)
        {
            if ((rnk[x] - rnk[y] + 3) % 3 == d - 1)
                continue;
            else
            {
                ans++;
                continue;
            }
        }
        fa[fx] = fy;
        rnk[fx] = (rnk[y] - rnk[x] + d - 1 + 3) % 3;
    }
    printf("%d", ans);
    return 0;
}