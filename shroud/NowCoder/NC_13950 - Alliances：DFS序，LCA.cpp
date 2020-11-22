//题意：有一颗 n 个结点的数，现在有 k 个帮派，每个帮派有若干个成员分布在结点，每个帮派在树上的控制领域是所有帮派成员所在结点之间的路径，现在有 q 组询问，每次给出一个结点 c，与若干帮派编号
//q 次询问互相独立，问结点 c 到当前询问给出帮派的控制领域的最短距离（可能为 0）

//思路：其实中心结点 c 到帮派成员构成的树网的距离只有三种情况
//第一种情况：c 在树网 lca 之外，那么判断条件就是树网的 lca 不是 c 的祖先结点，那么距离就是 c 到树网 lca 的距离
//第二种情况：c 在树网 lca 之内，且 c 在树网上，那么 lca 必然是 c 的祖先结点，那么在 c 的子树中，必然有若干个结点是帮派成员结点
//第三种情况，c 在树网 lca 之内，且 c 不在树网上，那么与上一种情况相反，子树中没有帮派成员结点
//那么对于上述三种情况，我们怎么判断具体情况内
//首先判断 c 和树网的 lca 的关系很好判断，接下来，问题就转化为子树中有没有标记结点，有关子树的我们可以去从 dfs 序思考
//可以找 c 结点最右边的标记结点的 dfs序 位置，然后判断该节点的 lca 是不是 c，或者用欧拉序直接来判断
//然后第三种情况，还有具体距离，就是 dfs 序中里 c 最近的两个结点离 c 的距离的最小值

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e5+10; 

int n,a[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dep[maxn],son[maxn],top[maxn],f[maxn],sz[maxn],dfn[maxn],cnt=0;
int pos[maxn],l[maxn];

vector<int> g[maxn];

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs_1(int u,int fa){
	dep[u]=dep[fa]+1;
	sz[u]=1;
	f[u]=fa;
	int mx=0;
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
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
	pos[cnt]=u;
	if(son[u]) dfs_2(son[u],topf);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==f[u]||v==son[u]) continue;
		dfs_2(v,v);
	}
}

int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=top[u];
		u=f[u];
	}
	return dep[u]>dep[v]?v:u;
}

inline int dist(int u,int v,int root){
	return dep[u]+dep[v]-2*dep[root];
}

int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs_1(1,0);
	dfs_2(1,1);
	int k,m,x;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			if(j==1) l[i]=x;
			else l[i]=lca(l[i],x);
			g[i].push_back(dfn[x]); 
		}
		sort(g[i].begin(),g[i].end());
	}
	int q,c,rt,left,right;
	vector<int>::iterator p;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&c,&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			if(i==1) rt=l[a[i]];
			else rt=lca(rt,l[a[i]]);
		}
		int t=lca(rt,c);
		if(t!=rt){
			printf("%d\n",dist(rt,c,t));
			continue;
		}
		left=0,right=n+1; 
		for(int i=1;i<=m;i++){
			p=lower_bound(g[a[i]].begin(),g[a[i]].end(),dfn[c]);
			if(p!=g[a[i]].end()) right=min(right,*p);
			if(p!=g[a[i]].begin()) left=max(left,*(--p));
		}
		if(right!=n+1&&lca(pos[right],c)==c){
			puts("0");
			continue;
		}
		int ans=0x3f3f3f3fl;
		if(right!=n+1){
			right=pos[right];
			int rt=lca(right,c);
			ans=min(ans,dist(c,rt,rt));
		}
		if(left!=0){
			left=pos[left];
			int rt=lca(left,c);
			ans=min(ans,dist(c,rt,rt));
		}
		printf("%d\n",ans);
	}
	return 0;
}
