//题意：一家商店在 n 天每天都上架 m 个糖果，所有 n*m 每个糖果加个不同，每天去商店可以选择不买或者买多颗糖果，在同一天内如果购买了 k 个糖果，就需要额外支付 k^2 的费用
//问最少花费多少钱才能使 n 天每天都能至少吃到一颗糖果？

//思路：有两种做法
//首先说说贪心做法，我们需要先求出第 i 天买的第 j 颗糖的价格（贡献），以一天为单位研究，肯定先对一天的糖果按照价格降序，肯定优先买便宜的
//于是第 i 天买 j 颗的总花费是 sum[i][j]+x^2, 第 i 天买 j-1 课的花费是 sum[i][j-1]+(x-1)^2 ，所以得到第 i 天买第 j 颗的花费是 a[i][j]+2*x-1
//我们可以根据上述结果看出每颗糖他对花费的贡献只与他本身的价格和他在当天所在的价格位置（当天第几颗买的有关），那么每天的糖果之间可以说是完全独立的
//我们可以这样想，第一天以前 m 个（第 1 堆）糖果为一个集合，选出里面花费最小的那一颗即可，第二天 2 堆糖果 2*m-1（已经被选走一颗），那么我们只需要通过排序维护每颗糖的贡献，然后用优先队列维护即可

//接着是 DP 做法：
//dp[i][j] 代表 前 i 天得到 j 颗糖的最小花费 
//dp[i][j]=min( dp[i-1][k]+s[i][j-k]+(j-k)*(j-k) )
//枚举 i 从 1-n ，j 从 i-min(i*m,n) 因为的考虑每行有几个元素，比如第一行只有 2 个，但是 n = 3 ，那么显然不可能等于第 1 天取 3 个


//贪心+优先队列维护

#include <bits/stdc++.h>

using namespace std;
const int maxn=305;
int n,m;

int main(){
	priority_queue<int,vector<int>,greater<int> > q;
	scanf("%d %d",&n,&m);
	vector<int> a(m);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++) scanf("%d",&a[j]);
		sort(a.begin(),a.end());
		for(int j=0;j<m;j++) q.push(a[j]+2*(j+1)-1);
		ans+=q.top();
		q.pop();
	}
	printf("%d\n",ans);
	return 0;
}

//DP
#include <bits/stdc++.h>

using namespace std;
const int maxn=305;
int n,m;
int s[maxn][maxn],dp[maxn][maxn]; 

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&s[i][j]);
		}
		sort(s[i]+1,s[i]+m+1);
		for(int j=1;j<=m;j++) s[i][j]+=s[i][j-1];
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=min(n,m*i);j++){
			for(int k=i-1;k<=j;k++){
				dp[i][j]=min(dp[i][j],dp[i-1][k]+s[i][j-k]+(j-k)*(j-k));
			}
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}
