//题意：求给出图中点 0 和点 n-1 的次短路

//思路：模板题，注意：

//这里的 d 和最短路的 dist[u] 不同，
//之前的 dist[u] 是当前的最短距离、
//而这里的 d 可能是最短距离，也可能是次短距离 


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 
const int maxn=5e3+10;
const int maxm=1e5+10;
int n,m;
int head[maxn],to[maxm<<1],nex[maxm<<1],w[maxm<<1],tot;
int dist1[maxn],dist2[maxn];

void init(){
	tot=0;
	for(int i=0;i<=n;i++) head[i]=-1;
}

inline void add(int u,int v,int d){
	to[++tot]=v;
	nex[tot]=head[u];
	w[tot]=d;
	head[u]=tot;
}

//1.最短路被更新的时候，当前最短路就变成了次短路
//2.若当前距离比最短路大，比次短路小，那么更新次短路
//3.若从上一个结点过来的次短路能更新次短路，那么更新次短路 

int Dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(dist1,0x3f,sizeof dist1);
	memset(dist2,0x3f,sizeof dist2);
	dist1[0]=0;
	q.push(pii(0,0));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int u=t.second,d=t.first;
		if(dist2[u]<d) continue;
		for(int i=head[u];~i;i=nex[i]){
			int v=to[i],d2=w[i]+d;   //这里的 d 和最短路的 dist[u] 不同，
									 //之前的 dist[u] 是当前的最短距离、
									 //而这里的 d 可能是最短距离，也可能是次短距离 
			if(dist1[v]>d2){
				swap(dist1[v],d2);   //如果当前最短路被更新，那么次短路得到被更新掉的最短路的值 
				q.push(pii(dist1[v],v));
			}
			if(dist2[v]>d2&&dist1[v]<d2){
				dist2[v]=d2;
				q.push(pii(dist2[v],v));
			}
		}
	}
	return dist2[n-1];
}

int main(){
	scanf("%d %d",&n,&m);
	init();
	int u,v,d;
	while(m--){
		scanf("%d %d %d",&u,&v,&d);
		add(u,v,d);
		add(v,u,d);
	}
	cout<<Dijkstra();
	return 0;
}
