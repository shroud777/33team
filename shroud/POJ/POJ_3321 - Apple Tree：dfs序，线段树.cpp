//题意：有一颗 n 结点的树，给出 n-1 条边，题中有两种操作，分别是修改某个结点的值和查询某个结点子树的值

//思路：求出每个点的dfs序并加上时间戳，可以求出每个点的管辖区域，那么每个节点就有了区间的性质，可以建立线段树。
//注意：刚开始我在想怎么建树，是自己根据节点的关系来划分区间呢还是怎么滴，后来一想，其实可以直接用这个dfs序产生的区间，n 个点既是 [1,n] 的区间
//然后每次修改就相当于单点修改，想想一下dfs序产生的区间，一颗子树的根节点的左区间端点必然就是这个根节点的时间戳序号，那么每次只需要修改单点修改左边即可，然后区间查询就是查询 x 点所管辖的整个区间

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,L,R;
int tot,len;
int head[maxn],nex[maxn],to[maxn],pos[maxn],ts_s[maxn],ts_e[maxn];
int tree[maxn<<2];

void init(){
	tot=0;
	len=0;
	for(int i=1;i<=n;i++) head[i]=0;
}

void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot; 
}

void dfs(int u,int fa){
	ts_s[u]=++len;
	for(int i=head[u];i;i=nex[i]){
		if(to[i]!=fa) dfs(to[i],u);
	}
	ts_e[u]=len;
}

inline void update(int x){
	tree[x]=tree[x<<1]+tree[x<<1|1];
}

void build(int l,int r,int x){
	tree[x]=r-l+1;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
}

void modify(int l,int r,int x,int pos){ 
	if(l==r){
		//cout<<x<<" tag"<<tag[x]<<" tree:"<<tree[x]<<endl; 
		tree[x]^=1;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos);
	else modify(mid+1,r,x<<1|1,pos);
	update(x);
}

int query(int l,int r,int x){
	if(L<=l&&r<=R) return tree[x];
	int mid=l+r>>1;
	int ans=0;
	if(L<=mid) ans+=query(l,mid,x<<1);
	if(mid<R) ans+=query(mid+1,r,x<<1|1);
	return ans;	
}

int main(){
	while(~scanf("%d",&n)){
		init();
		m=n-1;
		int u,v;
		while(m--){
			scanf("%d %d",&u,&v);
			add(u,v);
		}
		dfs(1,0);
		build(1,n,1);
		int q,x;
		char s[2];
		scanf("%d",&q);
		while(q--){
			scanf("%s%d",s,&x); 
			if(s[0]=='C') modify(1,n,1,ts_s[x]);
			else {
				L=ts_s[x],R=ts_e[x];
				printf("%d\n",query(1,n,1));
			}
		}
	}
	return 0;
}
