//题意：有 n 个木块排成一行从左到右编号为 1-n ，有 k 种颜色，每种颜色 i 可以足够涂 ci 快，且相邻木块颜色不可以相同，问有多少种着色方案

//思路：每种颜色能用来涂的数量 ci <=5 ,所以可以考虑把每种颜色能涂的个数作为衡量，来确定方案，这里 dp[c1][c2][c3][c4][c5][last] 这里前 5 维中第 i 维代表能涂 i 个方块的颜色有多少个
//last代表上一个涂的是什么颜色，那么对于每种格子我们有五种选择，c1~5 ,然后每次选择还要根据 last 作出调整，比如说我这次要选 c2 ,但是 last == 3，这说明我上一次用的是能涂 3 中颜色的
//然后他涂过一次变成了只能涂 2 种颜色的了，因此要判断一下
//最后要注意保存每次结果，利用记忆化搜素节约时间

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=1e9+7;
const int N=16;
int dp[N][N][N][N][N][6];
int c[6];
ll dfs(int a1,int a2,int a3,int a4,int a5,int last){
	int now=dp[a1][a2][a3][a4][a5][last];
	if(now!=-1) return now;
	ll ans=0;
	if(a1) ans=(ans+(a1-(last==2))*dfs(a1-1,a2,a3,a4,a5,1))%p;
	if(a2) ans=(ans+(a2-(last==3))*dfs(a1+1,a2-1,a3,a4,a5,2))%p;
	if(a3) ans=(ans+(a3-(last==4))*dfs(a1,a2+1,a3-1,a4,a5,3))%p;
	if(a4) ans=(ans+(a4-(last==5))*dfs(a1,a2,a3+1,a4-1,a5,4))%p;	
	if(a5) ans=(ans+a5*dfs(a1,a2,a3,a4+1,a5-1,5))%p;

	return dp[a1][a2][a3][a4][a5][last]=ans;
}
int main(){
	int n;
	cin>>n;
	int m;
	for(int i=1;i<=n;i++){
		cin>>m;
		c[m]++;
	}
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=5;i++) dp[0][0][0][0][0][i]=1;
	cout<<dfs(c[1],c[2],c[3],c[4],c[5],0)<<endl;
	return 0;
} 
