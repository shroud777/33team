//题意：存在 n 个点，他们构成了森林，给出 q 组查询，每组查询包含两个点，回答这两个点能否到达与距离

//思路：用并查集判断两个点在不在同一棵树，如果不在直接否定输出，否则通过树上差分和求出lca得到两个点的路径长度，tarjan 算法会 MLE，还是倍增LCA、

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e4+10;
const int maxlog=22;
int n,m,q;
int head[maxn],nex[maxn<<1],to[maxn<<1],w[maxn<<1],tot;
int Fa[maxn];
int fa[maxn][maxlog+5],dep[maxn],dis[maxn];

void init(){
	tot=0;
	memset(fa,0,sizeof fa);
	for(int i=1;i<=n;i++){
		Fa[i]=i;
		head[i]=0;
	}
}

inline void add(int u,int v,int len){
	to[++tot]=v;
	w[tot]=len;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){return x==Fa[x]?x:Fa[x]=find(Fa[x]);}

void dfs(int u,int f,int root){
	if(~f) fa[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==f) continue;
		dis[to[i]]=dis[u]+w[i];
		dep[to[i]]=dep[u]+1;
		dfs(to[i],u,root);
	}
}

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=maxlog;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	}
	if(u==v) return u;
	for(int i=maxlog;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}


int main(){
	while(~scanf("%d %d %d",&n,&m,&q)){
		init();
		int u,v,len;
		while(m--){
			scanf("%d %d %d",&u,&v,&len);
			add(u,v,len);
			add(v,u,len);
			u=find(u);
			v=find(v);
			if(u!=v) Fa[u]=v;
		}
		for(int i=1;i<=n;i++){
			if(Fa[i]!=i) continue;
			dis[i]=0;
			dep[i]=1;
			dfs(i,-1,i);
		}
		int ru,rv;
		while(q--){
			scanf("%d %d",&u,&v);
			ru=find(u),rv=find(v);
			if(ru!=rv){
				printf("Not connected\n");
				continue;
			}
			printf("%d\n",dis[u]+dis[v]-2*dis[lca(u,v)]);
		}
	}
	
	
	return 0;
}
/*
5 4 5
3 1 1
2 4 2
5 1 3
1 4 4
2 4
3 2
3 5
1 2
4 5
*/
