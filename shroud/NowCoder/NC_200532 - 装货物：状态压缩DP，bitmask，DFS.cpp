//题意：有 n 件货物，每件都有若干重量，有 x 个集装箱，每个能装 w 重量的货物，问有没有方案能使所有 n 件物品都装入 x 个集装箱内

//思路1：DFS+剪枝
//我们可以通过爆搜，每次把第 i 件货物尝试装入前 i 个集装箱，注意剪枝即可，同时还可以通过降序排序，使得搜索树更小
//
//思路2：状态压缩DP
//由于货物的个数不超过 20，我们可以考虑用 dp1[i],dp2[i] 分别表示装下货物的情况 i 下的最少所需集装箱和最大集装箱剩余
//那么状态转移有两种，一种是继上一个集装箱的容量，继续在里面放
//那么 dp1[i|(1<<j)]=min(dp1[i|(1<<j)],dp1[i])
//     dp2[i|(1<<j)]=max(dp2[i|(1<<j)],dp2[j]-w[j]);
//另一种,新加入一个集装箱来放
//     dp1[i|(1<<j)]=min(dp1[i|(1<<j)],dp1[i]+1)
//     dp2[i|(1<<j)]=max(dp2[i|(1<<j)],m-w[j]);


//1
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int w[25];
int b[25];
bool f;
int n,x,m;

bool dfs(int now){
	if(now==n+1) return 1;
	for(int i=1;i<=min(now,x);i++){
		if(b[i]+w[now]>m) continue;
		b[i]+=w[now];
		if(dfs(now+1)) return 1;
		b[i]-=w[now];
	}
	return 0;
}


int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		memset(b,0,sizeof b);
		scanf("%d %d %d",&n,&x,&m);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		sort(w+1,w+1+n,greater<int>());
		if(dfs(1)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}



//2

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n,x,m,w[25];
int dp1[1<<21],dp2[1<<21];

//dp1[i] 状态 i 下最少集装箱数
//dp2[i] 状态 i 下最大的集装箱剩余容量 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&x,&m);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		if(*max_element(w+1,w+n+1)>m){
			puts("No");
			continue;
		}
		for(int i=0;i<=(1<<n);i++){
			dp1[i]=0x3f3f3f3f;
			dp2[i]=0;
		}
		dp1[0]=1;dp2[0]=m;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1)) continue;
				if(dp2[i]>=w[j]&&dp1[i|(1<<j-1)]>=dp1[i]){
					dp1[i|(1<<j-1)]=dp1[i];
					dp2[i|(1<<j-1)]=max(dp2[i|(1<<j-1)],dp2[i]-w[j]);
				}
				if(dp1[i|(1<<j-1)]>=dp1[i]+1){
					dp1[i|(1<<j-1)]=dp1[i]+1;
					dp2[i|(1<<j-1)]=max(dp2[i|(1<<j-1)],m-w[j]);
				}
			}
		}
		if(dp1[(1<<n)-1]>x) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
