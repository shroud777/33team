#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s;
int n, op, l;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op >> l;
        if (op == 1)
        {
            if (s.find(l) != s.end())
                cout << "Already Exist" << endl;
            else
                s.insert(l);
        }
        else if (s.empty())
        {
            cout << "Empty" << endl;
        }
        else if (s.find(l) != s.end())
        {
            cout << l << endl;
            s.erase(l);
        }
        else
        {
            set<int>::iterator p = s.lower_bound(l);
            set<int>::iterator q = p;
            if (p != s.begin())
                p--;
            if (q == s.end())
                q--;
            if (l - *p <= *q - l)
            {
                cout << *p << endl;
                s.erase(p);
            }
            else
            {
                cout << *q << endl;
                s.erase(q);
            }
        }
    }
    return 0;
}