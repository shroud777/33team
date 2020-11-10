//题意：有 n 个点，给出 m 个操作，操作类型有 3 种
//1.u 和 v 建权值为 w 的有向边
//2.u 和 v∈[l,r] 建权值为 w 的有向边
//3.u∈[l,r] 和 v 建权值为 w 的有向边
//现在求 s 点到其他点的最短路

//思路：如果按照正常建边，那么不说时间复杂度，连空间都不够用
//这里考虑使用线段树优化建图，具体如下：
//这里线段树建完图之和就变成了入边到一个集合，和一个集合到出边的模板题，最后跑一个Dijkstra求单源最短路即可

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
const ll inf=1e17;
const int maxn=1e5+10;


int n,q,s;
int head[maxn*10],nex[maxn*10],to[maxn*10],tot=0,cnt;
int rt1,rt2,lc[maxn*20],rc[maxn*20],L,R,u,v;
ll dist[maxn*10],w[maxn*10],d;
int vis[maxn*10];

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

void build_1(int l,int r,int &x){
	if(l==r){
		x=l;
		return;
	}
	x=++cnt;
	int mid=l+r>>1;
	build_1(l,mid,lc[x]);
	build_1(mid+1,r,rc[x]);
	add(x,lc[x],0);
	add(x,rc[x],0);
}

void build_2(int l,int r,int &x){
	if(l==r){
		x=l;
		return;
	}
	x=++cnt;
	int mid=l+r>>1;
	build_2(l,mid,lc[x]);
	build_2(mid+1,r,rc[x]);
	add(lc[x],x,0);
	add(rc[x],x,0);	
}

void modify_1(int l,int r,int x){
	if(L<=l&&r<=R){
		add(u,x,d);
		return;
	}
	int mid=l+r>>1;
	if(L<=mid) modify_1(l,mid,lc[x]);
	if(mid<R) modify_1(mid+1,r,rc[x]);
}

void modify_2(int l,int r,int x){
	if(L<=l&&r<=R){
		add(x,u,d);
		return;
	}
	int mid=l+r>>1;
	if(L<=mid) modify_2(l,mid,lc[x]);
	if(mid<R) modify_2(mid+1,r,rc[x]);
}

void Dijkstra(){
	fill(dist,dist+n+cnt+5,inf);
	priority_queue<pli,vector<pli>,greater<pli> > pq;
	dist[s]=0;
	pq.push(pli(0,s));
	while(!pq.empty()){
		pli t=pq.top();
		pq.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]++;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(dist[v]>dist[u]+w[i]){
				dist[v]=dist[u]+w[i];
				pq.push(pli(dist[v],v));
			}
		}		
	}
}

int main(){
	scanf("%d %d %d",&n,&q,&s);
	cnt=n;
	build_1(1,n,rt1);	
	build_2(1,n,rt2);
	int opt;
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d %d %lld",&u,&v,&d);
			add(u,v,d);
		}
		else if(opt==2){
			scanf("%d %d %d %lld",&u,&L,&R,&d);
			modify_1(1,n,rt1);
		}
		else{
			scanf("%d %d %d %lld",&u,&L,&R,&d);
			modify_2(1,n,rt2);
		}
	}
	Dijkstra();
	for(int i=1;i<=n;i++) printf("%lld%c",dist[i]==1e17?-1:dist[i],i==n?'\n':' ');
	return 0;
}
