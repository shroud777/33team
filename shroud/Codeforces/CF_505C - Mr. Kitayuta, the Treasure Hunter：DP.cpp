//题意：有 3e4+1 个岛屿，有 n 个宝藏在若干个岛屿上（每个岛屿上数量不限），A 从 0 号岛屿开始跳了 d 步到 d 号岛屿，之后每次可以跳 d-1/d/d+1 步，且每次步数不可等于 0，每跳到一个岛屿就拿走了上面的宝藏
//求可以拿走的宝藏的最大值

//思路：DP，首先我们可以想到一个 O(n^2) 做法，我们可以设 dp[i][j] 为跳到 i 号岛屿，且上一步跳的长度为 j，状态转移方程也可以确定
//dp[i][j]=min(dp[i-j][j],dp[i-j+1][j-1],dp[i-j-1][j+1])+a[i]
//但是由于数据规模较大，n^2 的状态转移会超时，那么我们再想想怎么改进，可以发现上面有很多种状态是无用的，因为实际上这个 j 和 d 的最大差值其实只有 245,1+2+...+245>=3e4+1;
//但是我们的状态转移方程却可能产生如下情况：d=1时，j 会遍历到 3e4。
//那我们可以思考设 dp[i][j] 为到达岛屿 i 并且上一步跳了 d+j 步(-250<=j<=250)，
//为了方便数组下标的维护，我们把 j 引申为跳了 d+j-250 步，j 的范围变为 (0<=j<=500)
//状态转移方程: last（上一个岛屿）= i-(d+j-250)
//dp[i][j]=min(dp[last][j-1],dp[last][j],dp[last][j+1])+a[i]

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=3e4+10;
int dp[maxn][510],a[maxn]; 
int n,d;

//dp[i][j] 代表从上一个岛屿跳 d+j-250 步到达 i 岛屿的最优解
//last=i-d-j+250;
//dp[i][j]=max(dp[last][j],dp[last][j-1],dp[last][j+1])+a[i]


int main(){
	int x,mx=0;
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&x),a[x]++,mx=max(mx,x);
	memset(dp,-1,sizeof dp);
	dp[d][250]=a[d];
	int ans=a[d];
	for(int i=d;i<=mx;i++){
		for(int j=1;j<=500;j++){
			int last=i-(d+j-250);
			if(last<d||last>=i) continue;
			for(int k=-1;k<=1;k++){
				if(dp[last][j]!=-1) dp[i][j]=max(dp[i][j],dp[last][j]+a[i]);
				if(dp[last][j+1]!=-1) dp[i][j]=max(dp[i][j],dp[last][j+1]+a[i]);
				if(dp[last][j-1]!=-1) dp[i][j]=max(dp[i][j],dp[last][j-1]+a[i]);
				ans=max(ans,dp[i][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
