#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t;
double n, l;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        //n^n = 10^(nlog10(n))
        l = n * log10(n) - (long long)(n * log10(n));
        cout << (int)pow(10.0, l) << endl;
    }
    return 0;
}