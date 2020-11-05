//题意：给定一棵树，现在要求对它作四种操作：
//1.将树从 x 到 y 结点最短路径上的所有节点的值加上 z
//2.求树从 x 到 y 结点最短路径上的所有结点的值之和
//3.将以 x 为根节点的子树内的所有节点值加上一个值 z
//4.求以 x 为根节点的子树内的所有节点值之和

//思路：树链剖分模板题，关于树链剖分，主要是预处理出重儿子，然后构造出重链和维护一系列信息，一条重链上的dfs序是连续的，然后就可以用线段树维护
//详情如下：
//https://github.com/shroud777/33team/blob/patch-2/shroud/%E6%80%9D%E8%80%83%E6%80%BB%E7%BB%93/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E9%93%BE%E5%89%96%E5%88%86/%E6%A0%91%E9%93%BE%E5%89%96%E5%88%86.md


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int n,m,r,p;
int head[maxn],nex[maxn<<1],to[maxn<<1],tot=0;
int sz[maxn],fa[maxn],dep[maxn],son[maxn],id[maxn],top[maxn],cnt=0;
ll w[maxn],tree[maxn<<2],lazy[maxn<<2],wt[maxn]; 
int L,R;

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs_1(int u,int f){
	sz[u]=1;
	fa[u]=f;
	int mx=-1;
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==f) continue;
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
	id[u]=++cnt;
	wt[cnt]=w[u];
	top[u]=topf;
	if(!son[u]) return;
	dfs_2(son[u],topf);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa[u]||v==son[u]) continue;
		dfs_2(v,v);
	}
}

inline void update(int x){
	tree[x]=(tree[x<<1]+tree[x<<1|1])%p;
}

void build(int l,int r,int x){
	if(l==r){
		tree[x]=wt[l]%p;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}

void put_lazy(int l,int r,int x,ll k){
	lazy[x]=(lazy[x]+k)%p;
	tree[x]=(tree[x]+1ll*(r-l+1)*k%p)%p;
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
	if(L<=l&&r<=R) return tree[x]%p;
	if(lazy[x]) down_lazy(l,r,x);
	int mid=l+r>>1;
	ll ans=0;
	if(L<=mid) ans=(ans+query(l,mid,x<<1))%p;
	if(mid<R) ans=(ans+query(mid+1,r,x<<1|1))%p;
	return ans;
}

ll query_psum(int x,int y){
	ll res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		L=id[top[x]],R=id[x];
		x=top[x],x=fa[x];
		res=(res+query(1,n,1))%p;
	}
	if(dep[x]<dep[y]) swap(x,y);
	L=id[y],R=id[x];
	res=(res+query(1,n,1))%p;
	return res;
}

void modify_qsum(int x,int y,ll k){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		L=id[top[x]],R=id[x];
		x=top[x],x=fa[x];
		modify(1,n,1,k);
	}
	if(dep[x]<dep[y]) swap(x,y);
	L=id[y],R=id[x];
	modify(1,n,1,k);
}

ll query_ssum(int x){
	L=id[x],R=id[x]+sz[x]-1;
	return query(1,n,1);
}

void modify_ssum(int x,ll k){
	L=id[x],R=id[x]+sz[x]-1;
	modify(1,n,1,k);
}

int main(){
	scanf("%d %d %d %d",&n,&m,&r,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs_1(r,0);
	//for(int i=1;i<=n;i++) cout<<"id:"<<i<<" "<<sz[i]<<" "<<fa[i]<<endl;
	dfs_2(r,r);
	//for(int i=1;i<=n;i++) cout<<"id:"<<i<<" "<<id[i]<<" "<<son[i]<<" "<<top[i]<<endl;
	build(1,n,1);
	int op,x,y;
	ll k,z;
	while(m--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d %d %lld",&x,&y,&k);
			modify_qsum(x,y,k);
		}
		else if(op==2){
			scanf("%d %d",&x,&y);
			printf("%lld\n",query_psum(x,y));
		}
		else if(op==3){
			scanf("%d %lld",&x,&z);
			modify_ssum(x,z);
		}
		else{
			scanf("%d",&x);
			printf("%lld\n",query_ssum(x));
		}
	}
	return 0;
}
