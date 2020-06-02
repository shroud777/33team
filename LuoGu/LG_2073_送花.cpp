#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int op, w, c;
int W[1000005];
priority_queue<int> small, big;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll answ, ansc;
    answ = ansc = 0;
    while (cin >> op)
    {
        if (op == -1)
            break;
        if (op == 1)
        {
            cin >> w >> c;
            if (W[c])
                continue;
            W[c] = w;
            answ += w;
            ansc += c;
            small.push(-c);
            big.push(c);
        }
        else if (op == 3)
        {
            while (small.size() && !W[-small.top()])
                small.pop();
            if (small.size())
            {
                ansc -= -small.top();
                answ -= W[-small.top()];
                W[-small.top()] = 0;
                small.pop();
            }
        }
        else if (op == 2)
        {
            while (big.size() && !W[big.top()])
                big.pop();
            if (big.size())
            {
                ansc -= big.top();
                answ -= W[big.top()];
                W[big.top()] = 0;
                big.pop();
            }
        }
        //cout << answ << "~" << ansc << endl;
    }
    cout << answ << " " << ansc << endl;
    return 0;
}