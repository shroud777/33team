//题意：多组输入，每组输入给出一个起点位置和终点位置，还有 n 组可通行双向路线还有权值（经过所花费的时间），问从起点到终点需要花费的最短时间。

//思路：用 map 来给每个地点 hash 一个序号，然后用这些序号构建图，并求出两点的最短路即可，数据 n<= 150 , Floyd 也可以做

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
const int maxn=1e4+10;
struct node{
	int to,w,next;
}e[maxn<<1];
int head[155],tot;
int dist[155];
bool vis[155];

void init(){
	for(int i=1;i<=150;i++) head[i]=-1;
	for(int i=1;i<=n;i++) e[i].next=-1;
	tot=0;
}

inline void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}

/*void print_(int u){
	cout<<res[u]<<":   ";
	for(int i=head[u];~i;i=e[i].next){
		int j=e[i].to;
		cout<<res[j]<<" ";
	}
	cout<<endl;
}*/

void Dijkstra(int st,int end){
	memset(dist,0x3f,sizeof dist);
	memset(vis,false,sizeof vis);
	//memset(pre,-1,sizeof pre); 
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dist[st]=0;
	q.push(pii(0,st));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int ver=t.second,distance=t.first;
		//cout<<endl<<ver<<" "<<res[ver]<<endl;
		if(vis[ver]) continue;
		vis[ver]++;
		for(int i=head[ver];~i;i=e[i].next){
			int j=e[i].to,val=e[i].w;
			if(vis[j]) continue;
			if(dist[j]>val+distance){
				dist[j]=val+distance;
				q.push(pii(dist[j],j));
				//pre[j]=ver;
			}
		}
	}
	if(dist[end]!=0x3f3f3f3f) printf("%d\n",dist[end]);
	else puts("-1");
}

map<string,int> mp;
int main(){
	while(~scanf("%d",&n)&&n!=-1){
		mp.clear();
		init();
		string S,E;
		cin>>S>>E;
		int cnt=0;
		string s1,s2;
		int u,v,w;
		while(n--){
			cin>>s1>>s2>>w;
			if(!mp[s1]) mp[s1]=++cnt;
			if(!mp[s2]) mp[s2]=++cnt;
			u=mp[s1];
			v=mp[s2];
			add(u,v,w);
			add(v,u,w);
		}
		if(!mp[S]||!mp[E]){
			cout<<-1<<endl;
			continue;
		}
		int s,e;
		s=mp[S],e=mp[E];
		if(s==e){
			cout<<0<<endl;
			continue;
		}
		Dijkstra(s,e);
	}
	return 0;
}
