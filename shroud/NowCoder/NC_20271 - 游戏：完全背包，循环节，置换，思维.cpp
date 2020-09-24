//题意：对于 1 到 n 这 n 个数字，都有唯一且不同的 1 到 n 与之对应，每次都在一排数字下面写下与之对应的数字，这样会产生若干排数字直到又回到 1-n 的有序排列，问对于所有可能的对应关系，有多少种可能的排数

//思路：首先这里运用到循环与置换的概念，这 n 个数一一对应映射，最终必然会形成若干个环，证明略。
//那么这些重回有序排列的所需要的排数就是这些若干个环大小的最小公倍数
//那么问题就变成了：将 n 分解为若干个数，问若干个数的 lcm 的可能的个数，这是一个完全背包问题

#include <bits/stdc++.h>

using namespace std;	
typedef long long ll;
const int maxn=1e3+10;

int n;
int prime[maxn],vis[maxn],tot=0;
int dp[maxn];

void init(){
	vis[0]=vis[1]=1;
	for(int i=2;i*i<=n;i++){
		if(!vis[i]){
			for(int j=i*i;j<=n;j+=i) vis[j]=1;
		}
	}
	for(int i=2;i<=n;i++) if(!vis[i]) prime[++tot]=i;
}

int main(){
	scanf("%d",&n);
	init();
	dp[0]=1;
	for(int i=1;i<=tot;i++){
		for(int j=n;j>=prime[i];j--){
			for(int k=prime[i];k<=j;k*=prime[i]) dp[j]+=dp[j-k];
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++) ans+=dp[i];
	cout<<ans<<endl;
	return 0;
}
