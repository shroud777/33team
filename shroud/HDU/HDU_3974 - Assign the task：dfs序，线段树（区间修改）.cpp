//题意：有一颗 n 个结点的有根树，对他做两种操作，第一种查询某个结点的值，第二种修改某个结点为根节点的子树中所有结点的值

//思路：和 POJ_3321 - Apple Tree 思路一样，本质上都是将树形结构转化为区间上的问题，但是这里和上一题不同，这里改变的是区间的值，只要使用 lazy-tag 即可，某个结点的值只需要单点查询即可

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2e5+10;
int n,q,L,R;
int lazy[maxn<<2];
bool vis[maxn];
int ts_s[maxn],ts_e[maxn];
int nex[maxn],head[maxn],to[maxn];
int len,tot,st;


void init(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		head[i]=0;
	}
	len=tot=0;
}

void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int fa){
	ts_s[u]=++len;
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==fa) continue;
		dfs(to[i],u);
	}
	ts_e[u]=len;
}

void put_lazy(int l,int r,int x,int k){
	lazy[x]=k;
} 

void down_lazy(int l,int r,int x){
	int mid=l+r>>1;
	put_lazy(l,mid,x<<1,lazy[x]);
	put_lazy(mid+1,r,x<<1|1,lazy[x]);
	lazy[x]=-1;
}

void modify(int l,int r,int x,int k){
	if(L<=l&&r<=R){
		put_lazy(l,r,x,k);
		return;
	}
	if(lazy[x]!=-1) down_lazy(l,r,x);
	int mid=l+r>>1;
	if(L<=mid) modify(l,mid,x<<1,k);
	if(mid<R) modify(mid+1,r,x<<1|1,k);
}

int query(int l,int r,int x,int pos){
	if(l==r) return lazy[x];
	int mid=l+r>>1;
	if(lazy[x]!=-1) down_lazy(l,r,x);
	if(pos<=mid) return query(l,mid,x<<1,pos);
	return query(mid+1,r,x<<1|1,pos);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		printf("Case #%d:\n",T);
		memset(lazy,-1,sizeof lazy);
		scanf("%d",&n);
		init();
		int u,v,m=n-1;
		while(m--){
			scanf("%d %d",&u,&v);
			vis[u]++;
			add(v,u);
		}
		for(int i=1;i<=n;i++) if(!vis[i]) {st=i;break;} 
		dfs(st,0);
		scanf("%d",&q);
		char ch[2];
		int k;
		while(q--){
			scanf("%s",ch);
			if(ch[0]=='T'){
				scanf("%d %d",&u,&k);
				L=ts_s[u],R=ts_e[u];
				modify(1,n,1,k);
			}
			else{
				scanf("%d",&u);
				printf("%d\n",query(1,n,1,ts_s[u]));
			} 
		}
	}
	return 0;
} 
