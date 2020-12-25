//题意：有一颗 n 个结点的树，树上每个结点都有相应的宗教值和评级值，现在要求 4 种操作：
//1.CC x c：结点 x 的宗教值改成 c
//2.CW x w：结点 x 的评级值改成 w
//3.QS x y：查询从 x 到 y 的路径上宗教值和 x（x 和 y 的宗教值相等）相等的结点的评级值之和
//4.QM x y：查询从 x 到 y 的路径上宗教值和 x（x 和 y 的宗教值相等）相等的结点之中的最大评级值

//思路：乍一看可以树链剖分，但是不知道怎么查询特定宗教值的结点，然后冒出了开 n（最大宗教值个数）颗线段树的想法，保存每个宗教值在树上的情况
//刚开始觉得有点不靠谱，但事实上就是这么多，思想类似于主席树，对于每个宗教值开一个版本的主席树，并且要运用动态开点的技巧，否则会空间不够
//注意细节即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,q,L,R;
int rt[maxn],lc[maxn*40],rc[maxn*40],mx[maxn*40],sum[maxn*40],cnt=0;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int dep[maxn],f[maxn],sz[maxn],son[maxn],top[maxn],dfn[maxn],wt[maxn],len=0;
int a[maxn],c[maxn];

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs_1(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	sz[u]=1;
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
	dfn[u]=++len;
	wt[len]=a[u];
	top[u]=topf;
	if(son[u]) dfs_2(son[u],topf);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==f[u]||v==son[u]) continue;
		dfs_2(v,v);
	}
}

inline void update(int x){
	sum[x]=sum[lc[x]]+sum[rc[x]];
	mx[x]=max(mx[lc[x]],mx[rc[x]]);
}

void modify(int l,int r,int &x,int pos,int k){
	if(!x) x=++cnt;
	if(l==r){
		sum[x]=mx[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(l,mid,lc[x],pos,k);
	else modify(mid+1,r,rc[x],pos,k); 
	update(x);
}

int query_max(int l,int r,int x){
	if(L<=l&&r<=R||!x) return mx[x];
	int mid=l+r>>1,ans=0;
	if(L<=mid) ans=max(ans,query_max(l,mid,lc[x]));
	if(mid<R) ans=max(ans,query_max(mid+1,r,rc[x]));
	return ans;
}

int query_sum(int l,int r,int x){
	if(L<=l&&r<=R||!x) return sum[x];
	int mid=l+r>>1,ans=0;
	if(L<=mid) ans+=query_sum(l,mid,lc[x]);
	if(mid<R) ans+=query_sum(mid+1,r,rc[x]);
	return ans;
}

int prepare_query_max(int u,int v,int qc){
	int ans=0;	
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		L=dfn[top[u]],R=dfn[u];
		ans=max(ans,query_max(1,n,rt[qc]));
		u=top[u];
		u=f[u];
	}
	L=dfn[u],R=dfn[v];
	if(L>R) swap(L,R);
	return max(ans,query_max(1,n,rt[qc]));
}

int prepare_query_sum(int u,int v,int qc){
	int ans=0;	
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		L=dfn[top[u]],R=dfn[u];
		ans+=query_sum(1,n,rt[qc]);
		u=top[u];
		u=f[u];
	}
	L=dfn[u],R=dfn[v];
	if(L>R) swap(L,R);
	return ans+query_sum(1,n,rt[qc]);
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&c[i]);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs_1(1,0);
	dfs_2(1,1);
	for(int i=1;i<=n;i++) modify(1,n,rt[c[i]],dfn[i],a[i]);
	char ch[5];
	int x,y;
	while(q--){
		scanf("%s %d %d",ch,&x,&y);
		if(ch[0]=='C'&&ch[1]=='C'){
			modify(1,n,rt[c[x]],dfn[x],0);
			c[x]=y;
			modify(1,n,rt[c[x]],dfn[x],a[x]);
		}
		else if(ch[0]=='C'&&ch[1]=='W'){
			modify(1,n,rt[c[x]],dfn[x],y);
			a[x]=y;
		}
		else if(ch[0]=='Q'&&ch[1]=='M'){
			printf("%d\n",prepare_query_max(x,y,c[x]));
		}
		else printf("%d\n",prepare_query_sum(x,y,c[x]));
	}
	return 0;
}
