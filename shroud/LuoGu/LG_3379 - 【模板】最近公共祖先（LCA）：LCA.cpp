//题意：给出一颗有根多叉树，有 q 组查询，每组查询要求输出给出两结点的最近公共祖先

//思路：模板

//倍增算法：
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int maxlog=22;
int n,m,q,s;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot;
int fa[maxn][maxlog+5];
int dep[maxn];

void init(){
	tot=0;
	for(int i=0;i<=n;i++) head[i]=0;
	memset(fa,-1,sizeof fa);
	dep[s]=1;
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int f){
	if(~f){                   //根节点不做处理 
		dep[u]=dep[f]+1; 
		fa[u][0]=f;
	}
	for(int i=1;(1<<i)<=dep[u];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=nex[i]){
		if(f==to[i]) continue;
		dfs(to[i],u);
	}
} 

int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	for(int i=maxlog;i>=0;i--){
		if(fa[v][i]!=-1&&dep[fa[v][i]]>=dep[u]) v=fa[v][i];
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
	scanf("%d %d %d",&n,&q,&s);
	init();
	m=n-1;
	int u,v;
	while(m--){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(s,-1);
	while(q--){
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}

//tarjan算法

#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;
const int maxn=5e5+10;
typedef pair<int,int> pii;
int n,m,q,s;

vector<pii> g[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],tot;
int fa[maxn],ans[maxn];
bool vis[maxn];

void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		nex[i]=0;
		vis[i]=false;
		fa[i]=i;
	}
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void dfs(int u,int f){
	for(int i=head[u];i;i=nex[i]){
		if(to[i]!=f) dfs(to[i],u);
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first,id=g[u][i].second;
		if(vis[v]) ans[id]=find(v);
	}
	vis[u]=true;               		
	fa[u]=f;     			//一个结点访问完了才可以被记录并回溯 
}

int main(){
	scanf("%d %d %d",&n,&q,&s);
	init();
	m=n-1;
	int u,v;
	while(m--){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(pii(v,i));
		g[v].push_back(pii(u,i));
	}
	dfs(s,-1);
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
} 
