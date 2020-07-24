//题意：给出 n 个点，m 条边，每个点有一个权值，可以选择一个连通块，把所有的点权值减1，如果一个点权值变 0，可以看做这个点和它的领域全部断开，求最少操作次数使所有点权值为 0

//思路：每次选择肯定是找一个极大的连通块，将里面的数变小，直到全部为 0。然后变成 0 的点删除，分裂成多个连通块继续再做
//根据 b 的权值从大到小来把点加入进来。然后遍历所有与 x 相连的 y，对于每个 y ，如果之前已经加入过了，说明这个点不仅和他连通而且比它大，那么我们可以将 x 和 y 合并，
//并将 y 所在连通块的树根的父亲设为 x，得到一棵有根树。那么每个点 x 在成为最小值之前已经被做了 b[fa[x]] 次操作，所以每个点 x 对答案的贡献为 b[x]- b[fa[x]]

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+55;
const int M=5e5+55;
int n,m;

struct node{
	int id,w;
}b[N];
inline bool cmp(node x,node y){
	return x.w>y.w;
}

struct edge{
	int to,w,next;
}g[M<<1];
int head[N],tot=0;
bool vis[N];
int fa[N],f[N],W[N];

void init(){
	for(int i=1;i<=n;i++){
		head[i]=-1;
		vis[i]=f[i]=0;
		fa[i]=i;
	}
}

inline void add(int u,int v){
	g[++tot].to=v;
	g[tot].next=head[u];
	head[u]=tot;	
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		//init();
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i].w);W[i]=b[i].w;
			b[i].id=fa[i]=i;
			head[i]=-1;
			vis[i]=f[i]=0;
		}
		int u,v;
		while(m--){
			scanf("%d %d",&u,&v);
			add(u,v);
			add(v,u);
		}
		sort(b+1,b+n+1,cmp);
		int now,ver;
		for(int i=1;i<=n;i++){
			now=b[i].id;
			vis[now]=1;
			for(int j=head[now];~j;j=g[j].next){ 
				ver=g[j].to;
				if(!vis[ver]) continue;
				ver=find(ver);
				if(ver!=now) f[ver]=fa[ver]=now;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=W[i]-W[f[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
