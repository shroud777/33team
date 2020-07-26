//题意：一个有 n 个点，m 条边的无向图，每条边有权值，求从起点到终点的最小花费

//思路：模板题，#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e4+10;
struct node{
	int to,w,next;
}e[maxn];
int head[105],tot=0;
int dist[105];
bool vis[105];
int n,m;

void init(){
	for(int i=1;i<=maxn;i++){
		e[i].next=-1;
		head[i]=-1;
	}
	tot=0;
}

inline void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}

int dijkstra(){
	memset(dist,0x3f,sizeof dist);
	memset(vis,false,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dist[1]=0;
	q.push(pii(0,1));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int ver=t.second,distance=t.first;
		if(vis[ver]) continue;
		vis[ver]=1;
		for(int i=head[ver];~i;i=e[i].next){
			int j=e[i].to,w=e[i].w;
			if(vis[j]) continue;
			if(dist[j]>distance+w){
				dist[j]=distance+w;
				q.push(pii(dist[j],j));
			}
		}
	}
	if(dist[n]==0x3f3f3f3f) return -1;
	return dist[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m){
		if(n==0&&m==0) return 0;
		init();
		int u,v,w;
		while(m--){
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
		cout<<dijkstra()<<endl;
	}
	return 0;
} Dijkstra 直接终点到起点的最短路即可

