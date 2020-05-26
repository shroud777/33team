#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[1000005];
deque<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q.size())
        q.pop_front();
    for (int i = 1; i <= k; i++)
    {
        while (q.size() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << a[q.front()];
    for (int i = k + 1; i <= n; i++)
    {
        while (q.size() && i - q.front() + 1 > k)
            q.pop_front();
        while (q.size() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
        cout << " " << a[q.front()];
    }
    cout << endl;
    while (q.size())
        q.pop_front();
    for (int i = 1; i <= k; i++)
    {
        while (q.size() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << a[q.front()];
    for (int i = k + 1; i <= n; i++)
    {
        while (q.size() && i - q.front() + 1 > k)
            q.pop_front();
        while (q.size() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        cout << " " << a[q.front()];
    }
    cout << endl;
    return 0;
}