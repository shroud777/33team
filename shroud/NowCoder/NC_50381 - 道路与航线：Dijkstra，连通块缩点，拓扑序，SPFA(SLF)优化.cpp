//题意：给出一张有 t 个点的图，其中有 r 条双向道，p 条单向道，每条路都存在一个花费，保证单向同行的终点无法达到起点(单向道路不可能构成环),求出从起点 s 到各点的最少花费

//思路：负权图可以跑 SPFA，但是本题存在若干组数据特地卡 SPFA 的时间复杂度。所以 SPFA 不可行。
//做法 1：
//那么存在负权的图该怎么做呢，若我们只把双向边添加到图里，图中形成了多个连通块，然后把每个连通块看成一个点，那么再加入单向边，就变成了一个有向无环图，那么我们可以考虑拓扑排序
//以拓扑序为框架对每个连通块内的点用 Dijkstra 找到连通块内的最短路
//做法 2:
//这里普通的SPFA不行，但是经过 SLF(small label first)优化的 SPFA 是可行的，每次入队如果当前点的 dist 小于队首元素的 dist，直接插入队首，否则插入队尾


//做法 1：

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=3e4+10;
const int maxm=5e4+10;

int n,r,p,s;
int head[maxn],to[maxm<<2],nex[maxm<<2],w[maxm<<2],tot=0;
int fa[maxn],in[maxn],vis[maxn];
int dist[maxn];
vector<int> g[maxn];
vector<int> top;
vector<int> save[maxn];
int len=0;

inline void add(int u,int v,int d){
	to[++tot]=v;
	w[tot]=d;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs(int u,int f){
	fa[u]=f;
	save[f].push_back(u);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(fa[v]==f) continue;
		dfs(v,f);
	}
}

void topsort(){
	queue<int> q;
	for(int i=1;i<=len;i++) if(in[i]==0) q.push(i);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		top.push_back(t);
		for(int i=0;i<g[t].size();i++){
			int j=g[t][i];
			in[j]--;
			if(in[j]==0) q.push(j);
		}
	}
}

void Dijkstra(int k){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=0;i<save[k].size();i++) q.push(pii(dist[save[k][i]],save[k][i]));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int u=t.second,d=t.first;
		if(vis[u]) continue;
		vis[u]++;
		if(d==0x3f3f3f3f) continue;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(dist[v]>dist[u]+w[i]){
				dist[v]=dist[u]+w[i];
				if(fa[u]==fa[v]) q.push(pii(dist[v],v));
			}
		}
	}
}


int main(){
	scanf("%d %d %d %d",&n,&r,&p,&s);
	int a,b,c;
	for(int i=1;i<=r;i++){
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	len=0;
	for(int i=1;i<=n;i++) if(!fa[i]) dfs(i,++len);
	for(int i=1;i<=p;i++){
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		g[fa[a]].push_back(fa[b]);
		in[fa[b]]++;
	}
	topsort();
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[s]=0;
	for(int i=0;i<top.size();i++){
		Dijkstra(top[i]);
	}
	for(int i=1;i<=n;i++){
		if(dist[i]==0x3f3f3f3f) puts("NO PATH");
		else printf("%d\n",dist[i]); 
	}
	return 0;
}

//做法 2:

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=3e4+10;
const int maxm=5e4+10;

int n,r,p,s;
int head[maxn],to[maxm<<2],nex[maxm<<2],w[maxm<<2],tot=0;
int vis[maxn],dist[maxn];

inline void add(int u,int v,int d){
	to[++tot]=v;
	nex[tot]=head[u];
	w[tot]=d;
	head[u]=tot;
}

void SPFA(){
	deque<int> q;
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	q.push_back(s);
	dist[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(dist[v]>dist[u]+w[i]){
				dist[v]=dist[u]+w[i];
				if(vis[v]) continue;
				vis[v]=1;
				if(dist[q.front()]>dist[v]) q.push_front(v);
				else q.push_back(v);
			}
		}
	}
}

int main(){
	cin>>n>>r>>p>>s;
	int a,b,c;
	for(int i=1;i<=r;i++){
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=p;i++){
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
	}
	SPFA();
	for(int i=1;i<=n;i++) dist[i]==0x3f3f3f3f?puts("NO PATH"):printf("%d\n",dist[i]);
	return 0;
}
