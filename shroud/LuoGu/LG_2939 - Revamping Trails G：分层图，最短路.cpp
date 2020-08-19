//题意：n 个点，m 条边，每条边存在一个花费，找一条从 1 到 n 的路，路径上最多 k 段路免去花费，求最小花费的路径

//思路：分层图板题，练练手

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
const int maxn=1e4+10;
const int maxm=5e4+10;
const int maxk=22;
int n,m,k,tot=0;
int head[maxn*maxk],to[maxm*maxk*maxk<<1],nex[maxm*maxk*maxk<<1],w[maxm*maxk*maxk<<1];
ll dist[maxn*maxk];
int vis[maxn*maxk];

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

void Dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=n*(k+1);i++) dist[i]=INF;
	dist[1]=0;
	q.push(pii(0,1));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]++;
		//cout<<u<<":"<<endl;
		for(int i=head[u];i;i=nex[i]){
			//cout<<to[i]<<" ";
			int v=to[i],d=w[i];
			if(dist[v]>d+dist[u]){
				dist[v]=d+dist[u];
				q.push(pii(dist[v],v));
			}
		}
		//cout<<endl;
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	int x,y,z;
	while(m--){
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			for(int k=head[j];k;k=nex[k]){
				add(j+n*i,to[k]+n*(i+1),0);
				add(j+n*(i+1),to[k]+n*(i+1),w[k]);
			}
		}
	}
	Dijkstra();
	ll minn=1e18;
	for(int i=1;i<=k+1;i++) if(dist[n*i]<minn) minn=dist[n*i];
	printf("%lld\n",minn);
	return 0;
} 
