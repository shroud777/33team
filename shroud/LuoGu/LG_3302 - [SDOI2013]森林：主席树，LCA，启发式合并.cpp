//题意：给出一片 n 个结点 m 条边的森林，现在执行两种操作：
//1.Q x y k 查询点 x 到点 y 路径上所有的权值中，第 k 小的权值是多少。此操作保证点 x 和点 y 连通，同时这两个节点的路径上至少有 k 个点。
//2.L x y 在点 x 和点 y 之间连接一条边。保证完成此操作后，仍然是一片森林

//思路：区间第 k 小，很容易想到主席树，但是这我们怎么用主席树来维护呢？
//可以想到利用主席树来维护出 x 和 y 之间的简单路径的权值线段树
//那么我们设 Tu 代表结点 u 到 u 所在树的根节点的版本的线段树，我们要维护的就是 Tu+Tv-Tlca-Tfa-lca 形成的权值线段树
//所以最后的问题就变成了维护森林的问题，并且这里我们用到启发式合并降低复杂度每次新加入树的部分就要重新维护他的倍增数组和主席树
//由于这题有很多实现细节已经一系列问题，我写的时候也RE了一天，接下来就是要注意的一些问题：
//1.首先权值值域是 [1,1e9]，所以我们需要离散化降低复杂度
//2.query 函数最后返回的是第 k 小元素在离散化数组里的下标，但是我没有代到离散化数组里去，最后导致 lastans = 离散化数组下标，然后每次强制在线异或就变成了奇奇怪怪的值（一般来说就是 1-1e9 里的数），然后求这俩的 lca 就越界RE了
//3.我在更新倍增数组的时候做了一个剪枝，但是由于合并两棵树不确定根的位置（就是不知道两个点在各自树里的深度），盲目剪枝会导致可能 x 的倍增数组信息错误 ，所以要全部覆盖掉倍增数组的信息
//总而言之就是可能本来是叶结点 u 的后来变成了根，然后 u 连到了 v 上，并且到 v 的根的有效倍增数组的最大步长小于 u，那么我那波剪枝会导致可能 u 之前的祖先 z 依旧是他存在倍增数组信息里
//具体样例
/*那首先两颗树 连边情况分别是
1 2
2 3
3 4
4 5
5 6


7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15

第一个是链 第二个是以8为根
当把这两个合并的时候 显然是把第一颗合并到第二颗上
此时修改f[1][0] f[1][1] 之后 第二颗树到头了 所以此时f数组更新完毕了（按照错误的代码）
但是在本来链情况中 f[1][2]是有值的 是5
但是这样不会更新到 然后就错了
然后求 LCA 的时候就会往下爬
*/

 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=8e4+10;

int n,m,q;
int w[maxn],o[maxn],len=0;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int fa[maxn],sz[maxn],dep[maxn],f[30][maxn];
int rt[maxn],lc[maxn*320],rc[maxn*320],tree[maxn*320],cnt=0; 

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]) fa[y]=x,sz[x]+=sz[y];
	else fa[x]=y,sz[y]+=sz[x];
}

void modify(int l,int r,int &x,int last,int pos){
	x=++cnt;
	lc[x]=lc[last];
	rc[x]=rc[last];
	tree[x]=tree[last]+1;
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],lc[last],pos);
	else modify(mid+1,r,rc[x],rc[last],pos);
}

void dfs(int u,int fa){
	modify(1,len,rt[u],rt[fa],lower_bound(o+1,o+len+1,w[u])-o);
	dep[u]=dep[fa]+1;
	f[0][u]=fa;
	for(int i=1;i<=17;i++){
		f[i][u]=f[i-1][f[i-1][u]];
	}
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

inline int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=17;i>=0;i--){
		if(dep[f[i][u]]>=dep[v]) u=f[i][u];
	}
	//cout<<"lca：："<<u<<" "<<v<<endl;
	if(u==v) return u;
	for(int i=17;i>=0;i--){
		if(f[i][u]!=f[i][v]) u=f[i][u],v=f[i][v];
	}
	return f[0][u];
}

int query(int l,int r,int u,int v,int ance1,int ance2,int k){
	if(l==r) return l;
	int mid=l+r>>1;
	int res=tree[lc[u]]+tree[lc[v]]-tree[lc[ance1]]-tree[lc[ance2]];
	//cout<<"["<<l<<" , "<<mid<<"]区间内de个数为："<<res<<endl; 
	if(res>=k) return query(l,mid,lc[u],lc[v],lc[ance1],lc[ance2],k);
	return query(mid+1,r,rc[u],rc[v],rc[ance1],rc[ance2],k-res);
}

int main(){
	int t;
	scanf("%d",&t);
	t=1; 
	while(t--){
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;i++) w[i]=read(),o[i]=w[i],head[i]=0,fa[i]=i,sz[i]=1;
		sort(o+1,o+n+1);
		len=unique(o+1,o+n+1)-o-1;
		int u,v;
		for(int i=1;i<=m;i++){
			u=read(),v=read();
			add(u,v);
			add(v,u);
			merge(u,v);
		}
		for(int i=1;i<=n;i++){
			if(fa[i]==i) dep[i]=1,dfs(i,0);
		}
		char ch[2];
		int x,y,k,lastans=0;
		while(q--){
			scanf("%s",ch);
			if(ch[0]=='Q'){
				x=read(),y=read(),k=read();
				//cout<<x<<" "<<y<<" "<<k<<" "<<lastans<<endl;
				x^=lastans,y^=lastans,k^=lastans;
				//cout<<"now:"<<x<<" "<<y<<endl; 
				int ance1=lca(x,y),ance2=f[0][ance1];
				//cout<<"ance:"<<x<<" "<<y<<" "<<ance1<<" "<<ance2<<endl;
				printf("%d\n",lastans=o[query(1,len,rt[x],rt[y],rt[ance1],rt[ance2],k)]);
			}
			else{
				x=read(),y=read();
				x^=lastans,y^=lastans;
				//cout<<"now:"<<x<<" "<<y<<endl;
				add(x,y),add(y,x); 
				if(sz[find(x)]>sz[find(y)]) dfs(y,x);
				else dfs(x,y);
				merge(x,y);
			}
		}
	}
	return 0;
}
