//题意：n 个点，给出一定数量的有权边，求使图连通所需要的最小花费

//思路：最小生成树模板，没啥可说的

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
int n;
int fa[maxn];

struct node{
	int u,v,w;
}g[maxn];

bool cmp(node x,node y){
	return x.w<y.w;
}

void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	while(~scanf("%d",&n)){
		if(!n) break;
		char s[2];
		int u,v,w,tot=0,m=n-1,r;
		while(m--){
			scanf("%s",s);
			u=s[0]-'A'+1;
			scanf("%d",&r);
			while(r--){
				scanf("%s%d",s,&w);
				int v=s[0]-'A'+1;
				g[++tot].u=u,g[tot].v=v,g[tot].w=w;
			}
		}
		sort(g+1,g+tot+1,cmp);
		init();
		int cnt=0,cost=0;
		for(int i=1;i<=tot;i++){
			u=g[i].u,v=g[i].v;
			u=find(u),v=find(v);
			if(u==v) continue;
			fa[u]=v;
			cnt++;
			cost+=g[i].w;
			if(cnt==n-1) break;
		}
		printf("%d\n",cost);
	}
	
	return 0;
}
