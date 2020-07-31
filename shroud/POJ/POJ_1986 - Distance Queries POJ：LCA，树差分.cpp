//题意：给出 n 个点，m 条边，使图构成一颗树，给出 q 组查询，每组包含两个点，输出这两个点的距离

//思路：模板模板

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=4e4+10;
const int maxlog=22;
int n,m,q;
int head[maxn],nex[maxn<<1],to[maxn<<1],w[maxn<<1],tot=0;
int vis[maxn],dis[maxn],ans[maxn],fa[maxn];
vector<pii> g[maxn];

void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		head[i]=0;
	}
}

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void dfs(int u,int f){
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==f) continue;
		dis[to[i]]=dis[u]+w[i];
		dfs(to[i],u);
	}
	for(int i=0;i<g[u].size();i++){
		int j=g[u][i].first,id=g[u][i].second;
		if(vis[j]) ans[id]=dis[u]+dis[j]-2*dis[find(j)];
	}
	vis[u]=1;
	fa[u]=f;
}


int main(){
	scanf("%d %d",&n,&m);
	init(); 
	int u,v,d;
	char ch[2];
	while(m--){
		scanf("%d %d %d %s",&u,&v,&d,ch);
		add(u,v,d);
		add(v,u,d);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(pii(v,i));
		g[v].push_back(pii(u,i));
	}
	dis[1]=0;
	dfs(1,0);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
