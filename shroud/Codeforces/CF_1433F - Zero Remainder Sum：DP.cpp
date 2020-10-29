//题意：给出一个大小为 n*m 的矩阵 a，现在要求矩阵每行最多取不超过 m/2 向下取整个整数，问能取到的被 k 整除的最大的数是多少

//思路：明显用DP来做，首先考虑状态定义，由于对每行取数个数有限制，那么我们可以以行为阶段进行转移，那么我们可以想到三个描述状态的变量，i，j，cnt，表示取到 a(i,j) 并且当前行的取数个数为 cnt
//但是三个变量不足以维护出题干所需要的信息，因为我们不可能盲目记录最大值，到最后最大的也不一定是我们想要的，所以我们在取一个变量 k，代表取到 a(i,j) 并且当前行的取数个数为 cnt，且余数为 k
//那么我们就对所有的状态有了一个很好的描述，然后就是转移方程，首先我们分为取和不取两种情况
//dp[x][y+1][cnt+1][(k+a[x][y])%p]=max(dp[x][y+1][cnt+1][(k+a[x][y])%p],dp[x][y][cnt][k]+a[i][j]);  选择拿 a[x][y] 并作为本行第 cnt+1 个拿的元素，注意 cnt+1 <= m/2
//dp[x][y+1][cnt][k]=max(dp[x][y+1][cnt][k],dp[x][y][cnt][k]) 不选
//另外要注意每次转移到下一行，我们要注意方程的转变
//dp[x+1][1][0][(k+a[x][y])%p]=max(dp[x+1][1][0][(k+a[x][y])%p],dp[x][y][cnt][p]+a[i][j]);  选
//dp[x+1][1][0][k]=max(dp[x+1][1][0][k],dp[x][y][cnt][k]);   不选
//注意初值问题，除了 dp[1][1][0][0] 设置为 0，其他全部为 -inf
//最后 dp[n+1][1][0][0] 就是最优解

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int dp[75][75][75/2][75],n,m,k;
int a[75][75];

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	memset(dp,-0x3f,sizeof dp);
	dp[1][1][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=(j==m)?i+1:i;
			int y=(j==m)?1:j+1;
			for(int cnt=0;cnt<=m/2;cnt++){
				for(int p=0;p<k;p++){
					if(dp[i][j][cnt][p]==-0x3f3f3f3f) continue;
					if(i!=x) dp[x][y][0][p]=max(dp[i][j][cnt][p],dp[x][y][0][p]);
					else dp[x][y][cnt][p]=max(dp[x][y][cnt][p],dp[i][j][cnt][p]);
					if(cnt+1<=m/2){
						int np=(p+a[i][j])%k;
						if(i!=x) dp[x][y][0][np]=max(dp[i][j][cnt][p]+a[i][j],dp[x][y][0][np]);
						else dp[x][y][cnt+1][np]=max(dp[i][j][cnt][p]+a[i][j],dp[x][y][cnt+1][np]);
					}
				}
			}	
		}
	}
	cout<<max(0,dp[n+1][1][0][0])<<endl; 
	return 0;
} 
