#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e3+10;

int n,m;
int dp[maxn][maxn];

int main(){
	string s1,s2;
	cin>>n>>m>>s1>>s2;
	s1='@'+s1;
	s2='@'+s2;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+2;
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j])-1; 
			}
			if(dp[i][j]<0) dp[i][j]=0;
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
} //题意：现在定义 S(s1,s2) 的值为 s1 和 s2 的 LCS 长度 *4 - s1 和 s2 的长度之和，现在给出两个字符串，求他们的子串中最大的 S(A,B) 值

//思路：我们用求 LCS 的过程类比这个题干内容，我们设 dp(i,j) 为 s1i 和 s2j 的最大 S 值，那么和 LCS 一样
//当 s1i == s2j 时，dp[i][j]=dp[i-1][j-1]+2，因为多了两字符，增加了一个 LCS 长度，相当于总值+2
//当 s1i != s2j 时，dp[i][j]=max(dp[i-1][j],dp[i][j-1])-1
//然后转移完成后，用一个变量记录最大值即可

