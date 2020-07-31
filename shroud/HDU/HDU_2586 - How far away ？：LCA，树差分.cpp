//题意：有一颗 n 个点的树，给出 q 组询问，输出两点间的最短距离

//思路：LCA入门题，先用倍增lca求得最近公共祖先，然后两点间的距离就是 u 到根的距离+ v 到根的距离 - 2*lca到根的距离

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=4e4+10;
const int maxlog=20;
int head[maxn],to[maxn<<1],w[maxn<<1],nex[maxn<<1],tot;
int dep[maxn],fa[maxn][maxlog+5];
ll dis[maxn];
int n,m,q;

void init(){
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
}

void add(int u,int v,int c){
	to[++tot]=v;
	w[tot]=c;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int f,int dist){
	if(~f){
		dep[u]=dep[f]+1;
		dis[u]=dis[f]+dist;
		fa[u][0]=f;
	}
	for(int i=1;(1<<i)<=dep[u];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	
	for(int i=head[u];i;i=nex[i]){
		if(to[i]!=f) dfs(to[i],u,w[i]);
	}
} 

int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	for(int i=maxlog;i>=0;i--){
		if(dep[fa[v][i]]>=dep[u]) v=fa[v][i];
	}
	if(u==v) return u;
	for(int i=maxlog;i>=0;i--){
		if(fa[v][i]!=fa[u][i]){
			v=fa[v][i];
			u=fa[u][i];
		}
	}
	return fa[u][0];
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&q);
		init();
		m=n-1;
		int u,v,c;
		while(m--){
			scanf("%d %d %d",&u,&v,&c);
			add(u,v,c);
			add(v,u,c);
		}
		dep[1]=1;
		dis[1]=0;
		dfs(1,-1,0);
		while(q--){
			scanf("%d %d",&u,&v);
			printf("%lld\n",dis[u]+dis[v]-1ll*dis[lca(u,v)]*2);
		}
	}
	return 0;
} 
