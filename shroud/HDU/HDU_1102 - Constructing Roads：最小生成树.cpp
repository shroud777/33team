//题意：给出 n 个点，和每个点到其他点的距离，求连通所有点的最小距离

//思路：最小生成树模板

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=105;
struct node{
	int from,to,w;
	bool operator <(const node other)const{
		return w<other.w;
	} 
}g[maxn*maxn/2];
int n,fa[maxn];

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	while(~scanf("%d",&n)){
		int m=n-1;
		int tot=0;
		int w;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			for(int j=1;j<=n;j++){
				scanf("%d",&w);
				if(i<j){
					g[++tot].from=i;
					g[tot].to=j;
					g[tot].w=w;
				}
			}
		}
		int q,v,u;
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&u,&v);
			u=find(u),v=find(v);
			if(u!=v){
				fa[u]=v;
				m--;
			}
		}
		sort(g+1,g+tot+1);
		int cnt=0,cost=0;
		for(int i=1;i<=tot;i++){
			int u=g[i].from,v=g[i].to;
			u=find(u),v=find(v);
			if(u==v) continue;
			fa[u]=v;
			cnt++;
			cost+=g[i].w;
			if(cnt==m) break;
		}
		printf("%d\n",cost);
	}
	return 0;
}
