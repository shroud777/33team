//题意：给出一颗有 n 个结点的树，每个树上会存在一个权值 ai，现在给出 ci（即结点 i 的子树中权值 aj<ai 的结点的数量），让你来确定所有节点 ai 的大小

//思路：首先要来思考确定 ai 的过程，如果我们从子节点向上确定的话，那么可能会导致父节点的 ci 无法协调，那么我们自上而下的确定，利用 dfs 的顺序，我们确定当前结点的 ai 值
//对于 n 个结点，我们可以用 [1,n] 所有的数构造出每个 ai 结点
//对于具体当前的 ai 怎么确定，我们可以考虑下，我们需要确保有 ci 个子树中结点的值小于当前结点的值，那么我们可以取 [1,n] 中还未取走的第 ci+1 大的数
//同时根据上述结论，我们还可以知道对于那些子树大小小于 ci 的样例必然不存在解
//动态第 k 大可以用暴力法 O(n^2) 或者权值线段树 O(n*logn) 维护

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn=2e3+10;
 
int n,c[maxn],ans[maxn];
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int tree[maxn<<2];
bool f=1;

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
 
inline void update(int x){
	tree[x]=tree[x<<1]+tree[x<<1|1];
}
 
void build(int l,int r,int x){
	if(l==r){
		tree[x]=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}
 
void modify(int l,int r,int x,int pos){
	if(l==r){
		tree[x]=0;return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos);
	else modify(mid+1,r,x<<1|1,pos);
	update(x); 
}
 
int query(int l,int r,int x,int k){
	if(l==r) return l;
	int mid=l+r>>1;
	if(tree[x<<1]>=k) return query(l,mid,x<<1,k);
	return query(mid+1,r,x<<1|1,k-tree[x<<1]);
}
 
int dfs(int u,int fa){
	int sz=1;
	ans[u]=query(1,n,1,c[u]+1);
	modify(1,n,1,ans[u]);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		sz+=dfs(v,u);
	}
	if(sz<=c[u]) f=0;
	return sz;
}
 
int main(){
	scanf("%d",&n);
	int p,root;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&p,&c[i]);
		if(!p) root=i;
		add(p,i);
		add(i,p);
	}
	build(1,n,1);
	dfs(root,0);
	if(f){
		puts("YES");
		for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	else puts("NO");
	return 0;
}
