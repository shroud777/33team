//题意：给出一棵树，求连接树上任意三个点的距离

//思路：三个点求lca，自己的做法两两求 lca ，然后把较深的那个 lca 和另一个点再求 lca，同时路径是前两个点的距离 再加上这两个点的 lca 和另外一个点的距离之和，
//然后发现网上只要两两求 lca，然后算出两两的距离除以2就可以了，仔细一想还真是那么一回事

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=5e4+10;
const int maxlog=22;
int n,m,q;
int head[maxn],to[maxn<<1],nex[maxn<<1],w[maxn<<1],tot;
int dep[maxn],dis[maxn],dfn[maxn<<1],fi[maxn],len;
int f[maxn<<1][maxlog+5];

struct node{
	int lca,id;
}b[3];

bool cmp(node x,node y){
	return dep[x.lca]>dep[y.lca];
}

void init(){
	tot=len=0;
	for(int i=0;i<=n;i++) head[i]=-1;
}

inline void add(int u,int v,int l){
	to[++tot]=v;
	w[tot]=l;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int f){
	dfn[++len]=u;
	fi[u]=len;
	for(int i=head[u];~i;i=nex[i]){
		if(to[i]==f) continue;
		dep[to[i]]=dep[u]+1;
		dis[to[i]]=dis[u]+w[i];
		dfs(to[i],u);
		dfn[++len]=u;	
	}
}

void init_RMQ(){
	for(int i=1;i<=len;i++) f[i][0]=dfn[i];
	for(int i=1;(1<<i)<=len;i++){
		for(int j=1;j+(1<<i)-1<=len;j++){
			if(dep[f[j][i-1]]>dep[f[j+(1<<i-1)][i-1]]) f[j][i]=f[j+(1<<i-1)][i-1];
			else f[j][i]=f[j][i-1];
		}
	}
} 

inline int lca(int u,int v){
	u=fi[u],v=fi[v];
	if(u>v) swap(u,v);
	int d=log2(v-u+1);
	if(dep[f[u][d]]>dep[f[v-(1<<d)+1][d]]) return f[v-(1<<d)+1][d];
	return f[u][d];
}


int main(){
	bool f=0;
	while(~scanf("%d",&n)){
		if(f) printf("\n");
 		f=1;
		init();
		m=n-1;
		int u,v,l;
		while(m--){
			scanf("%d %d %d",&u,&v,&l);
			add(u,v,l);
			add(v,u,l);
		}
		scanf("%d",&q);
		dep[0]=1;
		dis[0]=0;
		dfs(0,-1);
		init_RMQ();
		int ans,temp;
		while(q--){
			ans=0;
			scanf("%d %d %d",&u,&v,&l);
			b[0].id=0,b[0].lca=lca(u,v);
			b[1].id=1,b[1].lca=lca(u,l);
			b[2].id=2,b[2].lca=lca(v,l);
			sort(b,b+3,cmp);
			if(b[0].id==0){
				ans+=dis[u]+dis[v]-2*dis[b[0].lca];
				temp=lca(b[0].lca,l);
				ans+=dis[b[0].lca]+dis[l]-2*dis[temp];
			}
			else if(b[0].id==1){
				ans+=dis[u]+dis[l]-2*dis[b[0].lca];
				temp=lca(b[0].lca,v);
				ans+=dis[b[0].lca]+dis[v]-2*dis[temp];
			}
			else if(b[0].id==2){
				ans+=dis[v]+dis[l]-2*dis[b[0].lca];
				temp=lca(b[0].lca,u);
				ans+=dis[b[0].lca]+dis[u]-2*dis[temp];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
