//题意：给出一颗 n 个结点的树，每条边都有一个权值，现在有 q 组询问，每组询问有 k 个关键点，问每次询问隔断 k 个关键点和结点 1 的最小权值

//思路：对于每组询问，显然是一个树形dp，设 dp[i] 代表以 i 为根的子树的最小代价，mn[i] 为点 i 到 1 号结点的最小路径的值
//那么显然 dp[u]=min(Σdp[v],mn[u])(v 代表 u 的子节点)
//但是有 q 组询问，我们不能考虑暴力dp，这里我们就要使用虚树，对所有有用的结点和它们的 lca 建立一棵虚树，然后跑树形 dp，因为 k 的和很小，我们也能在 O(n) 内完成
//对于虚树的构建，详情参考：

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;

const int maxn=5e5+10;

int n,m,q;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int f[maxn],son[maxn],dep[maxn],top[maxn],sz[maxn],dfn[maxn],cnt=0;
int a[maxn];
int st[maxn],tp;
ll dp[maxn],minn[maxn],w[maxn<<1];
vector<int> g[maxn];

bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}

inline void add(int u,int v,ll d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs_1(int u,int fa){
	int mx=0;
	sz[u]=1;
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		minn[v]=min(minn[u],w[i]);
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs_1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>mx){
			mx=sz[v];
			son[u]=v;
		}
 	}
}

void dfs_2(int u,int topf){
	top[u]=topf;
	dfn[u]=++cnt;
	if(son[u]) dfs_2(son[u],topf);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==f[u]||v==son[u]) continue;
		dfs_2(v,v);
	}
}

inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=top[u];
		u=f[u];
	}
	return dep[u]>dep[v]?v:u;
}

void insert(int x){
	if(tp==1){
		st[++tp]=x;
		return;
	} 
	int ance=lca(x,st[tp]);
	if(ance==st[tp]) return;
	while(dfn[st[tp-1]]>=dfn[ance]&&tp>1)  g[st[tp-1]].pb(st[tp]),--tp;
	if(ance!=st[tp]) g[ance].pb(st[tp]),st[tp]=ance;
	st[++tp]=x;
}

ll dfs_3(int u){
	if(!g[u].size()) return minn[u];
	ll sum=0;
	for(int i=0;i<g[u].size();i++) sum+=dfs_3(g[u][i]);
	g[u].clear();
	return min(sum,minn[u]);
}

int main(){
	scanf("%d",&n);
	int u,v;
	ll d;
	for(int i=1;i<n;i++){
		scanf("%d %d %lld",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
	}
	int x;
	minn[1]=1e18;
	dfs_1(1,0);
	dfs_2(1,1);
	scanf("%d",&q);
	st[1]=1;
	while(q--){
		scanf("%d",&m);
		tp=1;
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++) insert(a[i]);
		while(tp) g[st[tp-1]].pb(st[tp]),tp--;
		printf("%lld\n",dfs_3(1));
	}
	return 0;
} 
