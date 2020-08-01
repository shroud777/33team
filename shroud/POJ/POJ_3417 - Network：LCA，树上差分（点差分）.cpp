//题意：一颗 n 个结点的树，有 n-1 条树边，有 m 条附加边，可以去掉一条树边和一条附加边，问有多少种方案使整个网络分成两部分

//思路：树上的任意两个点都是连通的，这意味着这 m 条附加边每一条的加入都会形成一个环，这个环可以看成是两个点 u 和 v 和他们的最近公共祖先 lca(u,v) 所构成的一个环
//那么我们可以利用树差分，d 代表这个点到根节点的这条边额外增加了多少，即差分数组。每次操作就对 d[u],d[v] + 1，d[lca] -2;然后从根开始 dfs 可以得到每个点的权值
//可以这样想，如果当前边的权值为 0，说明它没有形成任何环，那么去掉它之后连通量立刻变为 2，那么随便再去掉任意一条附加边都可以，所以方案 +m，
//如果权值为 1，说明形成了一个环，并且需要在破坏一条指定的（使其形成环的附加边）附加边，于是方案只能 +1
//权值大于等于 2，说明去掉一条附加边也不够，所以不存在这样的方案

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n,m;
int head[maxn],nex[maxn<<1],to[maxn<<1],tot;
int fa[maxn],vis[maxn];
int d[maxn];
vector<int> g[maxn];

int ans=0;

void init(){
	tot=ans=0;
	for(int i=1;i<=n;i++){
		head[i]=vis[i]=0;
		fa[i]=i;
	}
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void tarjan(int u,int f){
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==f) continue;
		tarjan(to[i],u);
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]){
			d[u]++,d[v]++,d[find(v)]-=2;
		}
	}
	vis[u]=1;
	fa[u]=f;
}

void dfs(int u,int f){
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==f) continue;
		dfs(to[i],u);
		if(d[to[i]]==1) ans++;
		else if(!d[to[i]]) ans+=m;
		d[u]+=d[to[i]];		
	}
}

int main(){
	scanf("%d %d",&n,&m);
	init();
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	tarjan(1,0);
	dfs(1,0);
	//for(int i=1;i<=n;i++) cout<<i<<" "<<d[i]<<endl;
	printf("%d\n",ans);
	return 0;
}
