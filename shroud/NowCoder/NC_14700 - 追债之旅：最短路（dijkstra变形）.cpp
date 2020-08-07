//题意：给出 n 个点（ 1 - n 编号），m 条边，每条边存在一个权值，要从 1 号点出发到 n 号点，同时每次从一个点到一个点需要耗费一天的时间，每一天都有对应的权值，求从 1 号到 n 号总权值最小的方案

//思路：Dijkstra 变形，可以把原为来的 dis 数组变成二维 dis[i][j]，代表在第 j 天到达 i 点的最短距离，对于每个 dis[i][j] 只能被访问一次，跑最短路即可

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+10;
const int maxm=1e4+10;
typedef long long ll;
int n,m,k;
int head[maxn],to[maxm<<1],w[maxm<<1],nex[maxm<<1],tot;
int dis[15][maxn],vis[15][maxn];
int s[15];

struct node{
	int day,pos,val;
	node(int a,int b,int c):day(a),pos(b),val(c){}
	bool operator < (const node &other) const{
		return val>other.val;
	}
};


inline void add(int u,int v,int val){
	to[++tot]=v;
	w[tot]=val;
	nex[tot]=head[u];
	head[u]=tot;
}

void dijkstra(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[0][1]=0;
	priority_queue<node> q;
	q.push(node(0,1,0));
	while(!q.empty()){
		node temp=q.top();
		q.pop();
		int day=temp.day,u=temp.pos,val=temp.val;
		if(vis[day][u]) continue;
		vis[day][u]++;
		if(day+1>k) continue;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];jhn
			if(dis[day+1][v]>s[day+1]+val+w[i]){
				dis[day+1][v]=s[day+1]+val+w[i];
				q.push(node(day+1,v,dis[day+1][v]));
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++) scanf("%d",&s[i]);
	dijkstra();
	int ans=0x3f3f3f3f;
	for(int i=0;i<=10;i++) ans=min(ans,dis[i][n]);
	if(ans==0x3f3f3f3f) puts("-1");
	else printf("%d\n",ans);
	return 0;
} 
