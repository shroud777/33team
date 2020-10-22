//题意：有一只小鸟参加游戏，游戏界面是一个长为 n，高为 m 的二维平面，其中有 k 个管道
//小鸟始终在游戏界面内移动。小鸟从游戏界面最左边任意整数高度位置出发，到达游戏界面最右边时，游戏完成。
//小鸟每个单位时间沿横坐标方向右移的距离为1，竖直移动的距离由玩家控制。如果点击屏幕，小鸟就会上升一定高度X，每个单位时间可以点击多次，效果叠加；如果不点击屏幕，小鸟就会下降一定高度Y。
//小鸟位于横坐标方向不同位置时，上升的高度X和下降的高度Y可能互不相同。
//小鸟高度等于0或者小鸟碰到管道时，游戏失败 。小鸟高度为m时，无法再上升。
//现在，请你判断是否可以完成游戏。如果可以，输出最少点击屏幕数；否则，输出小鸟最多可以通过多少个管道缝隙。

//思路：很容易想到用 DP 来解决问题，DP状态很好表示，dp(i,j) 表示在 (i,j) 时的最小弹跳次数
//从第长为 i-1 自由掉落 ：dp[i][j]=min(dp[i][j],dp[i-1][j+down[i-1]]  01背包，转移或不转
//从第长为 i-1 点击上升 : dp[i][j]=min(dp[i][j],min(dp[i-1][j-up[i-1],dp[i][j-up[i-1])+1) 这里是完全背包解法，可以从 i 重复转移，也可以从 i-1 某位置转移一次到当前状态 dp(i,j)
//若选择对于有没有管道的地方分类讨论转移，那么码量会增大很多，我们可以选择判断当前状态存不存在管道，来去掉一些非法状态

#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f
const int maxn=1e4+10;
const int maxm=1e3+10;

int n,m,k;
int dp[maxn][maxm],up[maxn],down[maxn],p[maxn],l[maxn],h[maxn],vis[maxn];

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d %d",&up[i],&down[i]);
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&p[i],&l[i],&h[i]),p[i]++,vis[p[i]]=i;
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=m;i++) dp[1][i]=0; 
	for(int i=2;i<=n+1;i++){
		for(int j=up[i-1]+1;j<=m;j++) dp[i][j]=min(dp[i][j],min(dp[i][j-up[i-1]],dp[i-1][j-up[i-1]])+1);
		for(int j=m-up[i-1];j<=m;j++) dp[i][m]=min(dp[i][m],min(dp[i][j],dp[i-1][j])+1);
		for(int j=1;j<=m-down[i-1];j++) dp[i][j]=min(dp[i][j],dp[i-1][j+down[i-1]]);
		if(vis[i]){
			for(int j=l[vis[i]];j>0;j--) dp[i][j]=inf;
			for(int j=h[vis[i]];j<=m;j++) dp[i][j]=inf;
		}
		int res=inf;
		for(int j=1;j<=m;j++) res=min(res,dp[i][j]);
		if(res==inf){
			puts("0");
			int ans=0;
			for(int j=1;j<i;j++) ans+=!!vis[j];
			printf("%d\n",ans);
			return 0;
		}
	}
	/*for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m;j++) cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		cout<<endl;
	}*/
	puts("1");
	int ans=inf;
	for(int i=1;i<=m;i++) ans=min(ans,dp[n+1][i]);
	printf("%d\n",ans);
	return 0;
}
