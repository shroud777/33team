
// Problem : P1103 书本整理
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1103
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
struct Book
{
    int h, w;
} a[105];
int dp[105][105];
bool cmp(Book x, Book y)
{
    return x.h < y.h;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].h >> a[i].w;
    sort(a + 1, a + n + 1, cmp);
    dp[0][0] = 0;
    int ans=30000;
    if(n-k<=1) ans=0;
    for (int i = 1; i <= n; i++)
    {
    	dp[i][1]=0;
        for (int j = 2; j <= i; j++)
        {
        	dp[i][j]=-1;
        	for(int ii=i-1;ii>=j-1;ii--)
        		if(dp[i][j]==-1)
        			dp[i][j]=dp[ii][j-1]+abs(a[i].w-a[ii].w);
        		else
        			dp[i][j]=min(dp[i][j],dp[ii][j-1]+abs(a[i].w-a[ii].w));
        	if(j>=n-k)
        		ans=min(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}