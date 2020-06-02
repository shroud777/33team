#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, C, D, ans;
ll t[1000005] = {};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans = 0;
    cin >> A >> B >> C >> D;
    for (int i = A; i <= B; i++)
    {
        ++t[i + B];
        --t[i + C + 1];
    }
    for (ll i = 1; i <= 1000000; i++)
        t[i] += t[i - 1];
    for (ll i = C; i <= B + C; i++)
        ans += t[i] * min(i - C, D - C + 1);
    cout << ans << endl;
    return 0;
}
