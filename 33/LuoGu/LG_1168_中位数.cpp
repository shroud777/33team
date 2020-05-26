#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int> small, big;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ith, num, n;
    cin >> n;
    while (small.size())
        small.pop();
    while (big.size())
        big.pop();
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (small.empty() || x <= small.top())
            small.push(x);
        else
            big.push(-x);
        if (small.size() > big.size() + 1)
        {
            big.push(-small.top());
            small.pop();
        }
        else if (big.size() > small.size() + 1)
        {
            small.push(-big.top());
            big.pop();
        }
        if (i % 2)
        {
            if (small.size() > big.size())
            {
                cout << small.top() << endl;
            }
            else
            {
                cout << -big.top() << endl;
            }
        }
    }
    return 0;
}