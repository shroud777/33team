//题意：给出一颗有根数，求两个点的最近公共祖先

//模板


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
int n;
int in[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dep[maxn],fa[maxn][maxlog+5];

void init(){
	tot=0;
	memset(fa,0,sizeof fa);
	for(int i=1;i<=n;i++){
		head[i]=0;
		in[i]=0;
	}
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int f){
	if(~f){
		fa[u][0]=f;
		dep[u]=dep[f]+1;
	}
	for(int i=1;(1<<i)<=dep[u];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=nex[i]){
		if(to[i]!=f) dfs(to[i],u);
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
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		int u,v;
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			add(u,v);
			add(v,u);
			in[v]++;
		}
		int root;
		for(int i=1;i<=n;i++){
			if(!in[i]){
				root=i;
				break;
			}
		}
		dep[root]=1;
		dfs(root,0);

		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}	
	return 0;
}
