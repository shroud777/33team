//题意：一棵树上有 n 个节点，编号分别为 1 到 n，每个节点都有一个权值 w，有三种操作
//1: 把结点 uu 的权值改为 tt。
//2: 询问从点 uu 到点 vv 的路径上的节点的最大权值。
//3: 询问从点 uu 到点 vv 的路径上的节点的权值和。

//思路：树剖模板，维护最大值和和即可，注意有负权值，还有细节问题注意即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+10;

int n,q,a[maxn];
int head[maxn],nex[maxn<<1],to[maxn<<1],tot=0;
int sz[maxn],dep[maxn],son[maxn],f[maxn];
int top[maxn],dfn[maxn],w[maxn],cnt=0;
int sum[maxn<<2],mx[maxn<<2],L,R;

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs_1(int u,int fa){
	sz[u]=1;
	f[u]=fa;
	dep[u]=dep[fa]+1;
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
	w[cnt]=a[u];
	if(son[u]) dfs_2(son[u],topf);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==f[u]||v==son[u]) continue;
		dfs_2(v,v);
	}
}

inline int max(int x,int y){
	return x>y?x:y;
}

inline void update(int x){
	sum[x]=sum[x<<1]+sum[x<<1|1];
	mx[x]=max(mx[x<<1],mx[x<<1|1]);
}

void build(int l,int r,int x){
	if(l==r){
		sum[x]=mx[x]=w[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}

void modify(int l,int r,int x,int pos,int k){
	if(l==r){
		sum[x]=mx[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,x<<1,pos,k);
	else modify(mid+1,r,x<<1|1,pos,k);
	update(x);
}

int st_qmax(int l,int r,int x){
	if(L<=l&&r<=R) return mx[x];
	int mid=l+r>>1;
	int ans=-0x3f3f3f3f;
	if(L<=mid) ans=max(ans,st_qmax(l,mid,x<<1));
	if(mid<R) ans=max(ans,st_qmax(mid+1,r,x<<1|1));
	return ans;
}

int st_qsum(int l,int r,int x){
	if(L<=l&&r<=R) return sum[x];
	int mid=l+r>>1;
	int ans=0; 
	if(L<=mid) ans+=st_qsum(l,mid,x<<1);
	if(mid<R) ans+=st_qsum(mid+1,r,x<<1|1);
	return ans; 
}

int hld_qsum(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		L=dfn[top[x]],R=dfn[x]; 
		ans+=st_qsum(1,n,1);
		x=top[x];
		x=f[x];
	}
	if(dep[x]<dep[y]) swap(x,y);
	L=dfn[y],R=dfn[x];
	ans+=st_qsum(1,n,1);
	return ans;
}

int hld_qmax(int x,int y){
	int ans=-0x3f3f3f3f;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		L=dfn[top[x]],R=dfn[x];
		ans=max(ans,st_qmax(1,n,1));
		x=top[x];
		x=f[x];
	}
	if(dep[x]<dep[y]) swap(x,y);
	L=dfn[y],R=dfn[x];
	ans=max(ans,st_qmax(1,n,1));
	return ans;
}

int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs_1(1,0);
	dfs_2(1,1);
	//for(int i=1;i<=n;i++) cout<<i<<" "<<son[i]<<" "<<sz[i]<<" "<<top[i]<<endl;
	build(1,n,1);
	scanf("%d",&q);
	char ch[10];
	int x,y;
	while(q--){
		scanf("%s %d %d",ch,&x,&y);
		//cout<<x<<" "<<y<<endl;
		if(ch[0]=='Q'&&ch[1]=='S') printf("%d\n",hld_qsum(x,y));
		else if(ch[0]=='Q'&&ch[1]=='M') printf("%d\n",hld_qmax(x,y));
		else modify(1,n,1,dfn[x],y);
	}
	return 0;
}
