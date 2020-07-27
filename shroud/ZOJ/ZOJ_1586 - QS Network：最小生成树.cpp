//题意：有 n 个点，给出每个点连通其他点所需要的花费（每连接一个点都需要加上，每个点都不一样），以及某两个点连通所需要的花费，求出连通所有点需要的最小花费

//思路：只要根据要求求出每个点两两直接的边，然后排序后通过 kruskal 求最小生成树即可

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
struct node{
	int u,v,w;
	bool operator < (const node other)const{
		return w<other.w;
	}
}g[maxn*maxn/2];
int p[maxn],fa[maxn];

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			fa[i]=i;
		}
		int tot=0,w;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&w);
				if(i<j){
					g[++tot].u=i;
					g[tot].v=j;
					g[tot].w=p[i]+p[j]+w;
				}
			}
		}
		int m=n-1,cnt=0,cost=0;
		sort(g+1,g+tot+1);
		for(int i=1;i<=tot;i++){
			int u=g[i].u,v=g[i].v;
			u=find(u);
			v=find(v);
			if(u==v) continue;
			fa[u]=v;
			cost+=g[i].w;
			if(++cnt==m) break; 
		}
		printf("%d\n",cost);
	} 
	
	return 0;
}
