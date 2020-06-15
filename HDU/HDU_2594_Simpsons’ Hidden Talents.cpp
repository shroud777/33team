
// Problem : Simpsons’ Hidden Talents
// Contest : HDOJ
// URL : http://acm.hdu.edu.cn/showproblem.php?pid=2594
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
 * 扩展KMP算法
 */
//nxt[i]:x[i...m-1]与x[0...m-1]的最长公共前缀
//extend[i]:y[i...n-1]与x[0...m-1]的最长公共前缀
int nxt[100050];
int extend[100050];
char s[100050], t[100050];
void pre_EKMP(char x[], int m, int nxt[])
{
    nxt[0] = m;
    int j = 0;
    while (j + 1 < m && x[j] == x[j + 1])
        j++;
    nxt[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++)
    {
        int p = nxt[k] + k - 1;
        int L = nxt[i - k];
        if (i + L < p + 1)
            nxt[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < m && x[i + j] == x[j])
                j++;
            nxt[i] = j;
            k = i;
        }
    }
}
void EKMP(char x[], int m, char y[], int n, int nxt[], int extend[])
{
    pre_EKMP(x, m, nxt);
    int j = 0;
    while (j < n && j < m && x[j] == y[j])
        j++;
    extend[0] = j;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int p = extend[k] + k - 1;
        int L = nxt[i - k];
        if (i + L < p + 1)
            extend[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j])
                j++;
            extend[i] = j;
            k = i;
        }
    }
}

int maxx;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s >> t)
    {
        int sLen = strlen(s);
        int tLen = strlen(t);
        EKMP(s, sLen, t, tLen, nxt, extend);
        maxx = 0;
        for (int i = 0; i < tLen; i++)
        {
            if (i + extend[i] == tLen)
            {
                maxx = extend[i];
                break;
            }
        }
        //output
        if (maxx)
        {
            for (int i = 0; i < maxx; i++)
                cout << s[i];
            cout << " " << maxx << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}