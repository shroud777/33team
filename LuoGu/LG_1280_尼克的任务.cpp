
// Problem : P1280 尼克的任务
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1280
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Task
{
    int s, e;
} a[100005];
int dp[100005];
int n, k;
bool cmp(Task x, Task y)
{
    return x.s < y.s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i].s >> a[i].e;
        a[i].e += a[i].s;
    }
    sort(a + 1, a + k + 1, cmp);
    dp[n + 1] = 0;
    for (int j = k, i = n; i >= 1; i--)
    {
        if (a[j].s != i){
            dp[i] = dp[i + 1]+1;
        }else
        {
            dp[i] = 0;
            while (a[j].s == i)
            {
                dp[i] = max(dp[i], dp[a[j].e]);
                j--;
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}