//题意：在一个图中有 n 个点，m 条边，走每条路都有一个时间，但是每个点可能存在一些保护点，即如果要访问该点，必须先访问过所有它的保护点再访问它

//思路：其实过程和普通的最短路有点相像，只不过受到保护点的限制，我们要做一些处理
//首先，我们用优先队列维护跑 Dij，然后我们可以想到，对于那些没有保护点限制的，就直接处理最短路即可，如果有保护点处理，我们要等他入度为 0 才能入队进行下一步
//并且有保护点的值应该是 max(最晚的保护点到达时间，该点的最短路时间)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back 
#define INF 0x3f3f3f3f
const int maxn=3e3+10;
const int maxm=7e4+10;

int n,m;
int head[maxn],to[maxm<<1],nex[maxm<<1],tot=0;
int deg[maxn],vis[maxn];
ll w[maxm<<1],dist1[maxn],dist2[maxn];
vector<int> g[maxn];

void init(){
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0,g[i].clear();
}

inline void add(int u,int v,ll d){
	to[++tot]=v;
	nex[tot]=head[u];
	w[tot]=d;
	head[u]=tot;
}

void Dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(dist1,0x3f,sizeof dist1);
	memset(dist2,0,sizeof dist2);
	memset(vis,0,sizeof vis);
	dist1[1]=0;
	q.push(pii(0,1));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int u=t.second;
		ll d=t.first;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			deg[v]--;
			dist2[v]=max(dist2[v],dist1[u]);
			if(!deg[v]){
				dist1[v]=max(dist2[v],dist1[v]);
				q.push(pii(dist1[v],v));
			}
		}
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(dist1[v]>dist1[u]+w[i]){
				dist1[v]=dist1[u]+w[i];
				dist1[v]=max(dist1[v],dist2[v]);
				if(!deg[v]) q.push(pii(dist1[v],v));
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		init();
		int u,v;
		ll d;
		for(int i=1;i<=m;i++){
			scanf("%d %d %lld",&u,&v,&d);
			add(u,v,d);
		}
		int num;
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			deg[i]=num;
			for(int j=1;j<=num;j++){
				scanf("%d",&u);
				g[u].pb(i);
			}
		}
		Dijkstra();
		printf("%lld\n",dist1[n]);
	}
	return 0;
}
