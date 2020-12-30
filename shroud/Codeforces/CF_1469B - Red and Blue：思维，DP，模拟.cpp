//题意：有一个 a 序列，序列中的元素被涂成 red 和 blue 两种颜色，现在按顺序放在 r 数组和 b 数组，现在求可能的最大的 f(a)
//f(a)=max(0,a1,(a1+a2),(a1+a2+a3),…,(a1+a2+a3+⋯+an+m))

//思路：既然 r 数组和 b 数组是按照元素在 a 序列中的顺序排列的，那么答案就是就是 r 数组的前缀最大值和 b 数组的前缀最大值的和，其中最大值非负
//显然有两种做法：
//1.按照贪心思路模拟，我们只要找出两个前缀最大值并求和即可

//2.DP，这里的状态转移代表 (i,j) 继承 (i-1,j) or (i,j-1) 的答案，答案是按照拓扑序 stored 在 dp[n][m] 中的，可以预处理 dp[i][j] 的值

//做法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n,m;

int main(){
	int t;
	cin>>t;
	while(t--){
		int ans1=0,ans2=0,res=0,x;
		scanf("%d",&n);		
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			res+=x;
			ans1=max(ans1,res);
		}
		res=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			res+=x;
			ans2=max(ans2,res);
		}
		printf("%d\n",ans1+ans2);
	}
	return 0;
}

//做法2：

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
