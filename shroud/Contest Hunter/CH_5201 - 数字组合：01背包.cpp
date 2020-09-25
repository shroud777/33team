//题意：有 n 个正整数，选出若干个数，使他们的和为 m，求方案数

//思路：01背包模型，以选取的东西为阶段，从而进行转移

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+10;

int dp[maxn],a[maxn],tot=0;
int n,m,x;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x>m) continue;
		a[++tot]=x;
	}
	dp[0]=1;
	for(int i=1;i<=tot;i++){
		for(int j=m;j>=a[i];j--) dp[j]+=dp[j-a[i]];
	}
	cout<<dp[m]<<endl;
	return 0;
} 
