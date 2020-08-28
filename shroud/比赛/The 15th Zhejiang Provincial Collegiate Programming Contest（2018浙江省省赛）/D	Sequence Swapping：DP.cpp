//题意：有一个长度为 n 的由二元组 <si,vi> 组成的序列，第 k 项可以和 k+1 项元素交换如果 ( s(k)='('&& s(k+1)==')' )，并且可以得到 v(i)*v(i+1) 作为分数加到总和上，求最大分数和

//思路：首先做一些观察，可以发现左括号和相邻可以交换，那么形如 "()))))" 的序列可以想象为左括号移动至这些右括号的右侧，得到的价值是 这些右括号的值的和*这个左括号的值
//那么考虑 DP 做法，我们从每个左括号移动至至不同地方种取最大值最为最优解，但是这里有些问题，就是在某个左括号像右转移时，比如转移到第 j 个位置，但是 j 个位置前存在另一个左括号
//比如这样的情况："()))())" ，可以得知我们要先把 i 个括号后 j 个位置前所有的左括号移动到 j 以后的某个位置
//到这里状态定义和状态转移基本上差不多了，我们设 dp(i,j) 代表第 i 个左括号移动到 j 号位置的最优解，
//dp[i][j]=max(dp[i][j+1],dp[i+1][j+1]+过程种交换得到的值)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e3+10;

string s;
int n;
ll dp[maxn][maxn],a[maxn],l[maxn],sum[maxn];
//dp[i][j] 代表第 i 个左括号移动到 j 号位置的最优解 

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(sum,0,sizeof sum);
		memset(dp,0,sizeof dp);
		cin>>n>>s;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int tot=0;
		s='#'+s;
		for(int i=1;i<=n;i++){
			if(s[i]=='(') l[++tot]=i,sum[i]+=sum[i-1];
			else sum[i]+=sum[i-1]+a[i];
		}
		for(int i=tot;i>=1;i--){
			int pos=l[i];
			ll mx=-1e18;
			for(int j=n;j>=pos;j--){
				mx=max(mx,dp[i+1][j]);
				dp[i][j]=mx+a[pos]*(sum[j]-sum[pos]);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,dp[1][i]);
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
