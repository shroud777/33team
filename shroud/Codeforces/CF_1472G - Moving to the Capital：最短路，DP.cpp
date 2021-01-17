//题意：给出一张 n 个点，m 条权为 1 的单向边的图，设 d[i] 为点 i 到 1 点号点的最短距离，现在可以选择一个起点开始，按照如下规则开始行动：
//1.从 i 移动到 j：d[i]<d[j]
//2.从 i 移动到 j：d[i]>=d[j]，并且以某个的点为起点的行动中至多执行一次 2 号操作
//问行动过程中遇到的离 1 号点距离最近的距离是多少

//思路：首先用 bfs/Dijkstra 维护出 d[i] 数组
//然后根据 d[i] 数组重建图，对于从 u 到 v 的边，如果 d[u]<d[v]，建一条实边；反之，建一条虚边
//接下来我们只需要在图上作DP即可，对于当前点 u ，对于实边相连的点，我们可以直接找答案；对于虚边，由于题干要求至多执行一次 2 号操作，我们只能选择走一次虚边，那么就是 min(dp[u],d[v])，因为由于接下来不能做 2 号操作，这个d[v]肯定是最小值了
//最后鉴于重复率很高，我们可以使用记忆化搜索

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=2e5+10;

int n,m;
int head[maxn],to[maxn],nex[maxn],tot=0;
int d[maxn],dp[maxn];

vector<int> g1[maxn],g2[maxn];

void init(){
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0,d[i]=0x3f3f3f3f,g1[i].clear(),g2[i].clear(),dp[i]=n+1;
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void bfs(){
	d[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}

int dfs(int u){
	if(dp[u]!=n+1) return dp[u];
	for(int i=0;i<g1[u].size();i++){
		int v=g1[u][i];
		dp[u]=min(dp[u],dfs(v));
	}
	for(int i=0;i<g2[u].size();i++){
		int v=g2[u][i];
		dp[u]=min(dp[u],d[v]);
	}
	return dp[u]=min(dp[u],d[u]);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d %d",&n,&m);
		init();
		int u,v;
		while(m--){
			scanf("%d %d",&u,&v);
			add(u,v);
		}
		bfs();
		for(int i=1;i<=n;i++){
			for(int j=head[i];j;j=nex[j]){
				int v=to[j];
				if(d[v]<=d[i]) g2[i].push_back(v);
				else g1[i].push_back(v); 
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]==n+1) dfs(i);
		}
		for(int i=1;i<=n;i++) printf("%d ",dp[i]);
		printf("\n");
	}
	return 0;
}
