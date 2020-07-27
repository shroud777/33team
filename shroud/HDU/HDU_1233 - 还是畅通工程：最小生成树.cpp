//题意：有 n 个点，n*(n-1)/2 条边，每条边有一个权值，求使图连通的最小花费权值

//思路：最小生成树模板题，稠密图适合用 prim 求最小生成树，但是因为数据比较小就无所谓了

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
