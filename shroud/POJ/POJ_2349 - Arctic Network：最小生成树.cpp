//题意：给出 n 个点在二维平面上的坐标，同时存在 s 个 satellite channel ，可以无视距离任意连接两个点，求使用 s 个 satellite channel 后的最小连通 n 个点所需要的边的最大长度

//思路：题目中给出 s 给连通任意两点的边，那么我们可以尽可能把他们用在较长的边上，那么这题就变成了求最小生成树的第 s+1 大边

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii; 
const int maxn=105;
int g[maxn][maxn];
int n,m;
bool vis[maxn];

int prim(){
	int cnt=1,cost=0;
	priority_queue<pii,vector<pii>,greater<pii> > q; 
	for(int i=1;i<=n;i++) vis[i]=false;
	vis[1]=true;
	for(int i=2;i<=n;i++){
		int w=g[1][i];
		q.push(pii(w,i));
	}
	while(cnt!=n){
		pii t=q.top();
		q.pop();
		int v=t.second;
		if(vis[v]) continue;
		vis[v]=true;
		cost+=t.first;
		cnt++;
		if(cnt==n) break;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int w=g[v][i];
			q.push(pii(w,i));
		}
	}
	return cost;
} 

int main(){
	while(~scanf("%d",&n)&&n){
		m=n*(n-1)>>1;
		int u,v,w;
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&u,&v,&w);
			g[u][v]=w;
			g[v][u]=w;
		}
		printf("%d\n",prim());
	}
	
	return 0;
} 
