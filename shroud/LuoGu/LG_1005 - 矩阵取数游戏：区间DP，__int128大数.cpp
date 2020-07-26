//题意：给定一个 n*m 的矩阵，每个元素都有一个值 a[i][j] 。对于每一行，每次都可以取走该行的行首或行尾的元素，其对得分的贡献是 被取走的元素值 *（2^i），其中i表示第i次取数（从1开始编号）,求取完n行的最大得分。

//思路：每一行对于答案的贡献都是独立的，所以可以单独考虑每一行。
//对于每一行，只能从首尾取数，那么行的状态则是从一个区间到另一个区间的变化，这恰好符合区间DP的特点： 以区间作为“阶段”，以划分区间的方法作为“决策” 。
//设 dp(i,j) 为区间[i,j]的最大值，因为只能从行尾或行首取数，那么 dp(i,j) 应该由 dp(i+1,j) 或 dp(i,j-1) 转移，这里把取数的过程看成向外扩展的过程，每次 <<1 ;
//状态转移方程: dp[i][j] = 2 * max(dp[i][j-1]+b[j],dp[i+1][j]+b[i])
//2^82 会爆 longlong 因此要用__int128 

#include <bits/stdc++.h>
using namespace std; 
int n,m,a[105][105];
__int128 dp[105][105];
__int128 solve(int b[]){
	memset(dp,0,sizeof dp);
	for(int len=1;len<=m;len++){
		for(int i=1;i+len-1<=m;i++){
			int j=i+len-1;
			dp[i][j]=max(dp[i+1][j]+(__int128)b[i],dp[i][j-1]+(__int128)b[j]);
			dp[i][j]<<=1;
		}
	}
	return dp[1][m];
}
void write(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	__int128 ans=0;
	for(int i=1;i<=n;i++) ans+=solve(a[i]);
	write(ans);
	printf("\n");
	return 0;
}
