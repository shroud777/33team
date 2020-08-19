//题意：有 n 个点，m 条边，编号从 0 号点到 n-1 号城市，其中路径中可以选择最多 k 条使其花费为 0，求最小花费

//思路：分层图模板，有几次免费机会，就建几层图，从 i 层移动至 i+1 层代表第 i 次免费，最后从每层图的终点中得到最小值

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
const int maxn=1e4+10;
const int maxm=5e4+10;
int n,m,k,s,t;

int head[maxn*15],to[maxm*15*15],nex[maxm*15*15],w[maxm*15*15],tot=0;
int dist[maxn*15],vis[maxn*15];

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

void Dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=n*(k+1);i++) dist[i]=INF;
	dist[s]=0;
	q.push(pii(0,s));
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
			if(dist[v]>dist[u]+d){
				dist[v]=dist[u]+d;
				q.push(pii(dist[v],v));
			}
		}
		//cout<<endl;
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	scanf("%d %d",&s,&t);
	s++,t++;
	int x,y,z;
	while(m--){
		scanf("%d %d %d",&x,&y,&z);
		x++,y++;
		add(x,y,z);
		add(y,x,z); 
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			for(int k=head[j];k;k=nex[k]){
				add(j+i*n,to[k]+(i+1)*n,0);         //第 i 层图扩展到 i+1 层图 
				add(j+(i+1)*n,to[k]+(i+1)*n,w[k]);  //第 i+1 层复制 i 层图 
			}
		}
	}
	Dijkstra();
	int ans=INF;
	for(int i=0;i<=k;i++) ans=min(ans,dist[t+i*n]);
	printf("%d\n",ans);
	return 0;
} 
