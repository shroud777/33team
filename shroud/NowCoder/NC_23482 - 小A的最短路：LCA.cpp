//题意：在一颗 n 个景点，有 n-1 条路，从一个景点到走路到相邻的一个景点需要 1 点体力，某两个景点中开通了缆车，可以直接到达并且不耗费体力，有 q 组询问，每组询问两个景点所需要耗费的最少体力

//思路：如果没有缆车，这题是 lca 求树上两点距离的模板题、有了缆车，可以通过讨论坐不坐缆车和怎么坐缆车来求得最短距离，
//设缆车开设点为 v1,v2, 从 u 点到 v 点不做缆车的距离就是 dist[u]+dist[v]-2*dist[lca(u,v)]。
//最后即距离 u-v，距离 u-v1+v2-v, 距离 v-v1+v2-v（v1-v2是不需要体力的，所以看做一点）的比较

#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5+10;
const int maxlog=22;
int head[maxn],nex[maxn<<1],to[maxn<<1],tot;
int dis[maxn],dfn[maxn<<1],fi[maxn],t;
int f[maxn<<1][maxlog];
int n,q,v1,v2; 

void init(){
	tot=t=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int f){
	dfn[++t]=u;
	fi[u]=t;
	for(int i=head[u];i;i=nex[i]){
		if(f==to[i]) continue;
		dis[to[i]]=dis[u]+1;
		dfs(to[i],u);
		dfn[++t]=u;
	}
}

void init_RMQ(){
	for(int i=1;i<=t;i++) f[i][0]=dfn[i];
	for(int j=1;(1<<j)<=t;j++){
		for(int i=1;i+(1<<j)-1<=t;i++){
			if(dis[f[i][j-1]]>dis[f[i+(1<<j-1)][j-1]]) f[i][j]=f[i+(1<<j-1)][j-1];
			else f[i][j]=f[i][j-1];
		}
	}
} 

inline int lca(int x,int y){
	x=fi[x],y=fi[y];
	if(x>y) swap(x,y);
	int d=log2(y-x+1);
	if(dis[f[x][d]]>dis[f[y-(1<<d)+1][d]]) return f[y-(1<<d)+1][d];
	return f[x][d];
}

#define MIN(i,j) (i<j?i:j)
#define dist(u,v) dis[u]+dis[v]-2*dis[lca(u,v)]
int main(){
	scanf("%d",&n);
	init();
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	scanf("%d %d",&v1,&v2);
	dis[1]=0;
	dfs(1,0);
	init_RMQ();
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&u,&v);
		printf("%d\n",MIN(MIN(dist(u,v),dist(u,v1)+dist(v2,v)),dist(u,v2)+dist(v,v1)));
	}
	return 0;
}
