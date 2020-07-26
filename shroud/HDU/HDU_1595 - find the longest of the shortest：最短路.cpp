//题意：一共有 n 个城市（1~n），A 在城市 n，B 在城市 1，给出 m 条两两连接城市的通道，其中有一条（未知）道路已经不通畅了，求最坏情况下的 A 通往 B 所在城市的最短路径

//思路：最暴力的想法，直接枚举去边，然后求每种情况的最短路，但是会超时。其实只要先求出最短路，然后在这条路上枚举移除路径就可以了

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
const int N=1005;
const int maxn=N*(N-1)/2+10;
int n,m;
struct node{
	int to,w,next;
}e[maxn<<1];
int head[N],tot=0;
int dist[N],pre[N];
bool vis[N];
bool f;

void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=-1;
		pre[i]=0;
	}
	for(int i=1;i<=m*2;i++) e[i].to=-1;
}

inline add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}

void dijkstra(){
	for(int i=1;i<=n;i++){
		vis[i]=false;
		dist[i]=INF;
	}
	dist[n]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(pii(0,n));
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		int ver=t.second,distance=t.first;
		if(vis[ver]) continue;
		vis[ver]++;
		//cout<<endl<<"ver"<<endl;
		for(int i=head[ver];~i;i=e[i].next){
			int j=e[i].to,val=e[i].w;
			//cout<<j<<" ";
			if(vis[j]) continue;
			if(dist[j]>distance+val){
				dist[j]=distance+val;
				if(f) pre[j]=ver;
				q.push(pii(dist[j],j));
			} 
		}
	}
	f=0;
}

int main(){
	while(~scanf("%d %d",&n,&m)){
		f=1;
		init();
		int u,v,w;
		while(m--){
			scanf("%d %d %d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dijkstra();
		int ans=0;
		for(int i=1;;i=pre[i]){
			if(pre[i]==0) break;
			int temp1,t1,temp2,t2;
			for(int j=head[i];~j;j=e[j].next){
				if(e[j].to==pre[i]){
					t1=j;
					temp1=e[j].w;
					e[j].w=INF;
					if(j&1) t2=j+1;
					else t2=j-1;
					temp2=e[t2].w;
					e[t2].w=INF; 
					break;
				}
			}
			dijkstra();
			ans=max(ans,dist[1]);
			e[t1].w=temp1;
			e[t2].w=temp2;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
