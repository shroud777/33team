//题意：有N个节点，标号从1到N，这N个节点一开始相互不连通。第i个节点的初始权值为a[i]，接下来有如下一些操作：
//U x y: 加一条边，连接第x个节点和第y个节点
//A1 x v: 将第x个节点的权值增加v
//A2 x v: 将第x个节点所在的连通块的所有节点的权值都增加v
//A3 v: 将所有节点的权值都增加v
//F1 x: 输出第x个节点当前的权值
//F2 x: 输出第x个节点所在的连通块中，权值最大的节点的权值
//F3: 输出所有节点中，权值最大的节点的权值

//思路：做法1：线段树+离线：节点直接虽然有个连通的过程，但是要是我们按照他合并的顺序，离线处理数据，预先用dfs序把每个点用新的编号记录，然后用并查集维护连通块信息
//记录一个并查集的头和尾结点，这样可以用线段树维护一端连续的区间
//做法2：可并堆

//做法1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e5+10;

int n,q,a[maxn],op[maxn];
int fa[maxn],ed[maxn],nex[maxn],dfn[maxn],tot=0;
ll tree[maxn<<3],lazy[maxn<<3],mx[maxn<<3],x[maxn],y[maxn],w[maxn];
int L,R; 

void init_DSU(){
	for(int i=1;i<=n;i++) fa[i]=ed[i]=i;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void merge(int i){
	int rx=find(x[i]),ry=find(y[i]);
	if(rx==ry) return; 
	fa[ry]=rx;
	nex[ed[rx]]=ry;
	ed[rx]=ed[ry];
}

inline void update(int x){
	tree[x]=tree[x<<1]+tree[x<<1|1];
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}

void build(int l,int r,int x){
	if(l==r){
		tree[x]=mx[x]=w[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x); 
}

void put_lazy(int l,int r,int x,ll k){
	lazy[x]+=k;
	tree[x]+=1ll*k*(r-l+1);
	mx[x]+=k;
	return;
}

void down_lazy(int l,int r,int x){
	int mid=l+r>>1;
	put_lazy(l,mid,x<<1,lazy[x]);
	put_lazy(mid+1,r,x<<1|1,lazy[x]);
	lazy[x]=0;
}

void modify(int l,int r,int x,ll k){
	if(L<=l&&r<=R){
		put_lazy(l,r,x,k);
		return;
	}
	if(lazy[x]) down_lazy(l,r,x);
	int mid=l+r>>1;
	if(L<=mid) modify(l,mid,x<<1,k);
	if(mid<R) modify(mid+1,r,x<<1|1,k);
	update(x);
}

ll query(int l,int r,int x){
	if(L<=l&&r<=R) return tree[x];
	ll ans=0,mid=l+r>>1;
	if(lazy[x]) down_lazy(l,r,x);
	if(L<=mid) ans+=query(l,mid,x<<1);
	if(mid<R) ans+=query(mid+1,r,x<<1|1);
	return ans;
}

ll query_max(int l,int r,int x){
	if(L<=l&&r<=R) return mx[x];
	ll ans=-0x3f3f3f3f,mid=l+r>>1;
	if(lazy[x]) down_lazy(l,r,x);
	if(L<=mid) ans=max(ans,query_max(l,mid,x<<1));
	if(mid<R) ans=max(ans,query_max(mid+1,r,x<<1|1));
	return ans;
}

int main(){
	scanf("%d",&n);
	init_DSU();
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	char ch[10];
	for(int i=1;i<=q;i++){
		scanf("%s",ch);
		if(ch[0]=='U'){
			op[i]=1,scanf("%lld %lld",&x[i],&y[i]);
			merge(i);
		}
		else if(ch[0]=='A'){
			if(ch[1]=='1') op[i]=2,scanf("%lld %lld",&x[i],&y[i]);
			else if(ch[1]=='2') op[i]=3,scanf("%lld %lld",&x[i],&y[i]);
			else op[i]=4,scanf("%lld",&x[i]);
		}
		else{
			if(ch[1]=='1') op[i]=5,scanf("%lld",&x[i]);
			else if(ch[1]=='2') op[i]=6,scanf("%lld",&x[i]);
			else op[i]=7;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==fa[i]){
			int t=i;
			while(t){
				dfn[t]=++tot;
				w[tot]=a[t];
				t=nex[t];
			}
		}
	}
	build(1,n,1);
	init_DSU();
	for(int i=1;i<=q;i++){
		if(op[i]==1) merge(i);
		else if(op[i]==2) L=R=dfn[x[i]],modify(1,n,1,y[i]);
		else if(op[i]==3){
			int root=find(x[i]);
			L=dfn[root],R=dfn[ed[root]];
			modify(1,n,1,y[i]);
		}
		else if(op[i]==4){
			L=1,R=n;
			modify(1,n,1,x[i]);
		}
		else if(op[i]==5){
			L=R=dfn[x[i]];
			printf("%lld\n",query(1,n,1));
		}
		else if(op[i]==6){
			int root=find(x[i]);
			L=dfn[root],R=dfn[ed[root]];
			printf("%lld\n",query_max(1,n,1));
		}
		else{ 
			L=1,R=n;
			printf("%lld\n",query_max(1,n,1));
		}
	}
	return 0;
}
