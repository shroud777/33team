//题意：有 n 个点（编号从 1-n 开始）， t 条无向带权边，求从点 n 到点 1 的最短路径

//思路：最短路模板

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pii; 
int t,n;
const int maxn=2005;
struct node{
	int to,w,next;
}e[maxn<<1];
int head[maxn],tot=0;
int dist[maxn];
bool vis[maxn];

void init(){
	tot=0;
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1;i<=2*t;i++) e[i].next=-1;
}

void add(int u,int v,int w){
	e[++tot].w=w;
	e[tot].to=v;
	e[tot].next=head[u];
	head[u]=tot;
}

int Dijkstra(){
	memset(dist,0x3f,sizeof dist);
	memset(vis,false,sizeof vis);
	dist[n]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(pii(0,n));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int ver=t.second,distance=t.first;
		if(vis[ver]) continue;
		vis[ver]++;
		for(int i=head[ver];~i;i=e[i].next){
			int j=e[i].to,val=e[i].w;
			if(vis[j]) continue;
			if(dist[j]>distance+val){
				dist[j]=distance+val;
				q.push(pii(dist[j],j));
			}
		}
	}
	return dist[1];
}
int main(){
	scanf("%d %d",&t,&n);
	init();
	int u,v,w;
	while(t--){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	cout<<Dijkstra()<<endl;
	return 0;
}
