#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1005], cnt[140005], sum[1005], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            cnt[sum[i - 1] ^ sum[j - 1]]++;
        for (int j = i; j <= n; j++)
            ans += cnt[sum[j] ^ sum[i - 1]];
    }
    cout << ans << endl;
    return 0;
}