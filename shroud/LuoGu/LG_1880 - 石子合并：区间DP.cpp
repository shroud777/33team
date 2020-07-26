//题意：将环形摆放的 N 堆石子合并成一堆.规定每次只能选相邻的 2 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。

//思路：如果是链式摆放的 N 堆石子，就可以设合并区间[i,j]的最大/最小得分为 dp(i,j) ,状态转移方程为 dp(i,j)=max/min(dp(i,j),dp(i,k)+dp(K+1,j)+sum[j]-sum[i]) ;
//将这条链延长两倍，变成 2*n 堆，其中第 i 堆与第 i+n 堆相同，用动态规划求解后，取 dp(1,n),dp(2,n+1),...,dp(i,n+i-1) 中的最优值，即为最后的答案。  时间复杂度O(n^3)。

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=105;
int n;
int a[maxn*2],sum[maxn*2],dp_max[maxn*2][maxn*2],dp_min[maxn*2][maxn*2];
int main(){
	for(int i=1;i<=n*2;i++){
		dp_min[i][i]=0;
		dp_max[i][i]=0;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]+=sum[i-1]+a[i];
		a[i+n]=a[i];
	}
	for(int i=n+1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=2*n;i++){
			int j=i+len-1;
			dp_min[i][j]=INF;
			dp_max[i][j]=0;
			for(int k=i;k<j;k++){
				dp_min[i][j]=min(dp_min[i][j],dp_min[i][k]+dp_min[k+1][j]+sum[j]-sum[i-1]);
				dp_max[i][j]=max(dp_max[i][j],dp_max[i][k]+dp_max[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	int mi=INF;
	int mx=0;
	for(int i=1;i<=n;i++){
		mi=min(mi,dp_min[i][i+n-1]);
		mx=max(mx,dp_max[i][i+n-1]);
	}
	cout<<mi<<endl<<mx<<endl;
	return 0;
}
