//题意：有一颗 n 个结点的数，其中有 k 个特殊点，现在要求去除一些边，使得权值花费最小的情况下，是这些点两两之间都不连通

//思路：树形DP/Kruskal
//树形DP 的方法待补
//Kruskal 的做法其实就是最小生成树的原理，把边权按照降序排序，然后对于当前的边，如果两端点都有特殊点就删除这条边，否则将两端并入一个集合，不断扩展，直到完成

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;

struct node{
	int u,v;
	ll w;
	bool operator <(const node&oth)const{
		return w>oth.w;
	}
}g[maxn];
int n,k;
int vis[maxn],fa[maxn];


void init(){
	for(int i=0;i<=n;i++) vis[i]=0,fa[i]=i;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		init();
		for(int i=1;i<n;i++) scanf("%d %d %lld",&g[i].u,&g[i].v,&g[i].w);
		sort(g+1,g+n);
		int x,y;
		for(int i=1;i<=k;i++){
			scanf("%d",&x);
			vis[x]=1;
		}
		ll ans=0;
		for(int i=1;i<n;i++){
			x=g[i].u,y=g[i].v;
			x=find(x),y=find(y);
			if(vis[x]&&vis[y]){
				ans+=g[i].w;
				continue;
			}
			if(vis[x]||vis[y]) vis[x]=vis[y]=1;
			fa[x]=y;
		}
		printf("%lld\n",ans);
	}
}
