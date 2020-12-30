//题意：现在有 n 个长为 k，宽为 1 的截面，要将他们以宽为底面分别放在一端长度为 n 的地面上，并且每一段长为 1 的地面的基准高度都不同
//现在要求：1.相邻截面的相交部分必须大于等于 1
//2.除了第 1 个和第 n 个截面必须紧贴地面，其他可以放置在相距地面 k-1 以内的平面
//问有没有情况能满足要求？

//思路：我们只要设置每个截面的底面可以放置的范围即可，每个截面的底面取决于初始条件和上一个截面的地面可防止范围
//对于截面 i，l[i]=min(l[i-1]-k+1,a[i]),r[i]=max(r[i-1]+k-1,a[i]+k-1.
//然后只要 l[i]<=r[i]，并且最后的 r[n] 和 l[n] 的值和第 n 块地面的基准高度相同即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e3+10;

int n,m,a[maxn],b[maxn];
int dp[maxn][maxn];
//dp[i][j] 代表用 i 个 r 数组元素和 j 个 b 数组元素的最大 f(a) 值
//dp[i][j]=max(dp[i][j-1]+b[j]+dp[i-1][j]+a[i]) 

int main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&x),a[i]=a[i-1]+x;
		scanf("%d",&m);
		for(int i=1;i<=m;i++) scanf("%d",&x),b[i]=b[i-1]+x;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++) dp[i][j]=max(0,a[i]+b[j]);
		} 
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
				dp[i][j+1]=max(dp[i][j],dp[i][j+1]);
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
