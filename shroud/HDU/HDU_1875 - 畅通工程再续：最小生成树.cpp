//题意：给出 n 个点的坐标，修建最小花费的路使每个点都连通，同时每条路不可小于 10 ，也不可大于 1000

//思路：把所有点两两之间符合要求的边按照权值从小到大遍历，利用 kruskal 得到 MST

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=105;
struct node{
	int u,v;
	double w;
	bool operator <(const node other) const{
		return w<other.w;
	}
}g[maxn*maxn/2];
int n,m,tot;
int fa[maxn],x[maxn],y[maxn];

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

double cal(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

double Kruskal(){
	double cost=0;
	int cnt=0;
	for(int i=1;i<=tot;i++){
		int u=g[i].u,v=g[i].v;
		u=find(u),v=find(v);
		if(u==v) continue;
		fa[u]=v;
		cost+=g[i].w;
		if(++cnt==n-1) return cost;
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y[i]);
			fa[i]=i;
		}
		tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double d=cal(i,j);
				if(d<10||d>1000) continue;
				g[++tot].u=i;
				g[tot].v=j;
				g[tot].w=d;
			}
		}
		sort(g+1,g+tot+1);
		double ans=Kruskal();
		if(ans==-1) printf("oh!\n");
		else printf("%.1f\n",ans*100);
	}
	return 0;
}
