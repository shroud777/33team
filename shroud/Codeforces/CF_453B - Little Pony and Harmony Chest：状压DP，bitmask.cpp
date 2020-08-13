//题意：给出一个长度为 n 的序列 A，求一个长度为 n 的序列 B，使序列中任意两数的 gcd 都等于 1，并且所有 |Ai-Bi| 的和尽可能小

//思路：长度为 n，A 序列数据的范围是 30，那么我们首先可以思考，那么 B 序列的上限肯定是 59，因为使 Ai 和 Bi 的差值尽量小
//如果 Bi 是大于 60 的数，那么 Bi 还不如等于 1，因为 1 和其他任何数互质且差值最大才是 29
//这种状态呈现指数级的 DP，显然要用状态压缩来解决
//这一点很关键，确定了枚举的范围，且 60 以内的质数个数为 17 个，我们可以将枚举序列的过程看成一个填充质因子的过程，当前选择的数 Bi 中包含的质因子，必须是 B1,B2...Bi-1 中所没有的
//这样看来我们可以用状态压缩，压缩当前枚举的所包含质数的情况。
//设 dp[i][j] 为前 i 个序列中质因子的分布情况的状压状态 j
//如果我们枚举状态，那么由 100*(1<<17) 个状态，显然过于紧张，且主要是包含了很多重复，不必要的状态
//我们可以枚举数字，那么利用数字的状压情况（其中包含的质数分布），我们可以枚举出可能的情况 k,那么说明 p[j] 和 k 是不冲突的
//可以得到 dp[i][p[prime]|k}=min(dp[i][p[j]|k],dp[i-1][k]+abs(a[i]-j))
//同时要输出方案，那么我们可以用一个数组记录，我之前还想着记录一个前缀下标，一个答案下标，但是其实不需要，因为 答案^当前状态 就得到了前一个状态，位的运用比较灵活

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int n,tot;
int vis[105],prime[105],a[105],p[105];
int dp[105][(1<<17)+1],ans[105][(1<<17)+1];

//dp[i][j] 代表前 i 位的素数的状态压缩表示 j 

void init(){
	tot=0;
	vis[1]=vis[0]=1;
	for(int i=2;i<60;i++){
		if(!vis[i]){
			prime[++tot]=i;
			for(int j=i*i;j<60;j+=i) vis[j]=1;
		}
	}
}

void get(int x){
	int temp=x;
	for(int i=1;i<=17;i++){
		int pri=prime[i];
		if(temp%pri==0){
			p[x]+=(1<<i-1);
			while(temp%pri==0) temp/=pri;
		}
	}
}

void print(int cnt,int i){
	if(cnt==1){
		printf("%d",ans[cnt][i]);
		return;
	}
	print(cnt-1,p[ans[cnt][i]]^i);
	printf(" %d",ans[cnt][i]);
}

int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<60;i++) get(i);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<60;j++){
			int temp=(~p[j])&((1<<17)-1);
			for(int k=temp; ;k=(k-1)&temp){
				if(dp[i-1][k]==0x3f3f3f3f) continue;
				if(dp[i][k|p[j]]>dp[i-1][k]+abs(a[i]-j)){
					dp[i][k|p[j]]=dp[i-1][k]+abs(a[i]-j);
					ans[i][k|p[j]]=j;
				}
				if(k==0) break;
			}
		}
	}
	int minn=0x3f3f3f3f,f;
	for(int i=0;i<(1<<17);i++){
		if(dp[n][i]<minn) minn=dp[n][i],f=i; 
	}
	print(n,f);
	return 0;
}
