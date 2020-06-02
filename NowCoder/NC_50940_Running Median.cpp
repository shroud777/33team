#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int> small, big;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ith, num, n;
        scanf("%d%d", &ith, &n);
        printf("%d %d\n", ith, (n + 1) / 2);
        num = 0;
        while (small.size())
            small.pop();
        while (big.size())
            big.pop();
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
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
                    printf("%d ", small.top());
                }
                else
                {
                    printf("%d ", -big.top());
                }
                if (num % 10 == 0 && i != n)
                    printf("\n");
                num++;
            }
        }
        printf("\n");
    }

    return 0;
}