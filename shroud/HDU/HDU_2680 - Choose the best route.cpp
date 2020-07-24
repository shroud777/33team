//题意：有 n 个点，m 条条无向边（两点之间可能存在多条不同权值的边），求 w 个起点到一个终点 s 的最短距离

//思路：最短路，反向建图变为单源最短路即可。第二种做法是建立超级源点，即建立一个虚拟的源点，连接所有的起点，但是路径长度为 0 ，然后跑超级源点到汇点的距离即可。


//反向建图

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
const int N=1e3+10;
const int M=2e4+10;
int n,m,s;
struct node{
	int to,w,next;
}g[M];
int head[N],tot=0;
int dist[N],mp[N][N];
bool vis[N];

void init(){
	tot=0;
	for(int i=1;i<=m;i++) g[i].next=-1;
	for(int i=1;i<=n;i++){
		head[i]=-1;
		for(int j=1;j<=n;j++){
			mp[i][j]=0;
		}
	}
}

void add(int u,int v,int w){
	g[++tot].to=v;
	g[tot].w=w;
	g[tot].next=head[u];
	head[u]=tot;
}

void Dijkstra(){
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		vis[i]=false;
	}
	dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(pii(0,s));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int ver=t.second,distance=t.first;
		if(vis[ver]) continue;
		vis[ver]=true;
		for(int i=head[ver];~i;i=g[i].next){
			int j=g[i].to;
			if(vis[j]) continue;
			if(dist[j]>distance+g[i].w){
				dist[j]=distance+g[i].w;
				q.push(pii(dist[j],j));
			}
		}
	}
}

int main(){
	while(~scanf("%d %d %d",&n,&m,&s)){
		init();
		int u,v,w;
		while(m--){
			scanf("%d %d %d",&u,&v,&w);
			int temp;
			if(mp[v][u]){
				temp=mp[v][u]; 
				if(g[temp].w>w) g[temp].w=w;
				continue;
			}
			add(v,u,w);
			mp[v][u]=tot;
		}
		Dijkstra();
		int q;
		scanf("%d",&q);
		int ans=INF;
		while(q--){
			scanf("%d",&u);
			ans=min(ans,dist[u]);
		}
		if(ans==INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}


//建立超级源点

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
const int N=1e3+10;
const int M=2e4+10;
int n,m,s;
struct node{
	int to,w,next;
}g[M<<1];
int head[N],mp[N][N],tot=0;
int dist[N];
bool vis[N];

void init(){
	tot=0;
	for(int i=1;i<=m+n+5;i++) g[i].next=-1;
	for(int i=0;i<=n;i++) head[i]=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=0;
		}
	}
}

void add(int u,int v,int w){
	g[++tot].to=v;
	g[tot].w=w;
	g[tot].next=head[u];
	head[u]=tot;
}

void Dijkstra(){
	for(int i=0;i<=n;i++){
		dist[i]=INF;
		vis[i]=false;
	}
	dist[0]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(pii(0,0));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int ver=t.second,dis=t.first;
		if(vis[ver]) continue;
		vis[ver]=true;
		for(int i=head[ver];~i;i=g[i].next){
			int j=g[i].to,w=g[i].w;
			if(dist[j]>dis+w){
				dist[j]=dis+w;
				q.push(pii(dist[j],j));
			}
		}
	} 
}

int main(){
	while(~scanf("%d %d %d",&n,&m,&s)){
		int u,v,w;
		init();
		while(m--){
			scanf("%d %d %d",&u,&v,&w);
			if(mp[u][v]){
				int i=mp[u][v];
				g[i].w=(g[i].w>w?w:g[i].w);
				continue;
			}
			add(u,v,w);
			mp[u][v]=tot;
		}
		scanf("%d",&w);
		while(w--){
			scanf("%d",&u);
			add(0,u,0);
		}
		Dijkstra();
		if(dist[s]==INF) cout<<-1<<endl;
		else cout<<dist[s]<<endl;
	}
	return 0;
} 
