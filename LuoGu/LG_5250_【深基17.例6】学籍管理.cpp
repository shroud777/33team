#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, int> s;
int n, op, score;
string name;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> name >> score;
            if (s.count(name))
                s[name] = score;
            else
                s[name] = score;
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            cin >> name;
            if (s.count(name))
                cout << s[name] << endl;
            else
                cout << "Not found" << endl;
        }
        else if (op == 3)
        {
            cin >> name;
            if (s.count(name))
            {
                s.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
                cout << "Not found" << endl;
        }
        else if (op == 4)
            cout << s.size() << endl;
    }
    return 0;
}