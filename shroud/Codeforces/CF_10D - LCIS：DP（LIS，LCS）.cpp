//题意：给出两个长度分别为 n 和 m 的序列 A 和 B，求 A 和 B 的 LCIS

//思路：LCIS，可以结合 LIS 和 LCS 的思想，综合运用求出
//
//首先回忆下 LCS， O(n^2) 做法已经足够优秀，可以直接参考状态转移方程
// f[i][j]=f[i-1][j-1]+1             (s1[i]==s2[j])
// f[i][j]=min(f[i][j-1],f[i-1][j]   (s1[i]!=s2[j])
//
//那我们求 LCIS 似乎也可以从参考上述，设 f[i][j] 为 s1 前 i 位和 s2 前 j 位的 LCIS，但是要考虑到要求上升序列，那么每个状态必然还要保存最后一位数字，所以综合考虑加上一个以 s2[j] 为最后一位的LCIS
//然后状态转移方程也出来了
//f[i][j]=f[i-1][j]                                   (s1[i]!=s2[j])
//f[i][j]=max(f[i-1][k])+1,(1<=k<=j-1 & s2[k]<s2[j])  (s1[i]==s2[j])
//
//这里可以得出一个显然的 O(n^3) 做法，就是枚举 k，这不仅让我们想到了 LIS 的优化，如果能记录 s1[i]==s2[j] 时要用的最优解 f[i-1][k],那就省了一重循环
//可以看到这里不需要刻意的去找，因为每次第二重循环的时候我们可以记录当前 s2[j] 比 s1[i] 小的最大值，因为如果后面找到了 s2[j]==s1[i] 的情况的时候就可以直接用当前记录的最大值
//这里可以将二维数组改为滚动数组节约空间
//同时题目要求记录路径，我们只需要在每次更新的时候记录其前驱即可

#include <bits/stdc++.h>

using namespace std;
const int maxn=510;
int dp[maxn],a[maxn],b[maxn],pre[maxn];
int n,m;

//dp[i][j] 代表序列 a 的前 i 位和序列 b 的前 j 位以 b[j] 为结尾的最长公共上升子序列‘
// if (a[i]!=b[j])  dp[i][j]=dp[i-1][j]
// if (a[i]==b[j])  dp[i][j]=max(dp[i-1][k])+1 (1<=k<=j-1,b[k]<b[j])

void print(int i){
	if(pre[i]==-1){
		printf("%d",b[i]);
		return;
	}
	print(pre[i]);
	printf(" %d",b[i]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int mx,p;
	for(int i=1;i<=n;i++){
		mx=0;
		p=-1;
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				dp[j]=mx+1;
				pre[j]=p;
			}
			if(a[i]>b[j]&&dp[j]>mx){
				mx=dp[j];
				p=j; 
			}
		}
	}
	int ans=0,temp;
	for(int i=1;i<=m;i++){
		if(dp[i]>ans){
			ans=dp[i];
			temp=i;
		}
	}
	printf("%d\n",ans);
	if(ans==0) return 0;
	print(temp);
	printf("\n");
	return 0;
} 
