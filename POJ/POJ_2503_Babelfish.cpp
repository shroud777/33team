
// Problem : Babelfish
// Contest : POJ - Waterloo local 2001.09.22
// URL : http://poj.org/problem?id=2503
// Memory Limit : 65 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
int state = 0;
string s;
map<string, string> dict;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (getline(cin, s))
    {
        if (s == "")
        {
            state++;
            continue;
        }
        if (state == 0)
        {
            string a, b;
            a = b = "";
            int p;
            for (p = 0; p < s.length(); p++)
            {
                if (s[p] == ' ')
                {
                    p++;
                    break;
                }
                a += s[p];
            }
            for (; p < s.length(); p++)
                b += s[p];
            dict[b] = a;
        }
        if (state == 1)
        {
            map<string, string>::iterator x = dict.find(s);
            if (x != dict.end())
                cout << x->second << endl;
            else
                cout << "eh" << endl;
        }
    }
    return 0;
}