//题意：有三个服务员最初在 1，2，3 处，存在 q 个请求，每次需要指派且只能有一个员工去往该处（该位置只能有 1 个员工），从 p 到 q 需要花费 c(p,q)
//求满足 q 个请求的最小值，位置从 1 到 n（最大200）

//思路：DP,首先阶段很好确定，就是 1-q 个请求，但是我们发现这个阶段不足以表示状态，但是我们发现三个员工可能处在 200*200*200 个位置，所以若将三个员工的作为三个附加维度叠加上去肯定不行
//那么我们可以发现，其实某个位置的时候，一个员工的位置时确定的，那么我们可以减少一维，变得可以承受
// dp[i][x][y] 代表第 q 个询问时员工分别在 p[i],x,y (p[i]!=x!=y) 的最优解
//边界状态我们可以设 dp[0][1][2]=0,p[0]=3,代表三个员工的初始位置，目标状态 dp[q][?][?]，接着根据递推式进行状态转移即可
//还有就是在状态转移时注意三个人的位置不可以相同

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int dp[1005][205][205],c[1005][1005],p[1005];

//dp[i][x][y] 代表第 i 个请求时员工在 (x y pi) 位置的最优解
//
//dp[i+1][x][y]=min(dp[i+1][x][y],dp[i][x][y]+c[pi][p(i+1)])   (x,y,pi)->(x,y,p(i+1))
//dp[i+1][x][pi]=min(dp[i+1][x][pi],dp[i][x][y]+c[y][p(i+1)])  (x,y,pi)->(x,pi,p(i+1))
//dp[i+1][pi][y]=min(dp[i+1][pi][y],dp[i][x][y]+c[x][p(i+1)])  (x,y,pi)->(pi,y,p(i+1))

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=q;i++) scanf("%d",&p[i]);
	memset(dp,0x3f,sizeof dp);
	p[0]=3;
	dp[0][1][2]=0;
	for(int i=0;i<q;i++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(dp[i][x][y]==0x3f3f3f3f) continue;
				//cout<<i<<" "<<x<<" "<<y<<" "<<p[i]<<" "<<dp[i][x][y]<<endl;
				// x y pi
				if(x!=p[i+1]&&y!=p[i+1]&&x!=y) dp[i+1][x][y]=min(dp[i+1][x][y],dp[i][x][y]+c[p[i]][p[i+1]]);
				if(x!=p[i+1]&&p[i]!=p[i+1]&&x!=p[i]) dp[i+1][x][p[i]]=min(dp[i+1][x][p[i]],dp[i][x][y]+c[y][p[i+1]]);
				if(y!=p[i+1]&&p[i]!=p[i+1]&&y!=p[i]) dp[i+1][p[i]][y]=min(dp[i+1][p[i]][y],dp[i][x][y]+c[x][p[i+1]]);
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
           ans=min(ans,dp[q][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
