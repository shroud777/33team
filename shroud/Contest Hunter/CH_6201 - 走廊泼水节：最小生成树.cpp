//题意：给出一棵 n 个结点的树，要求增加若干边，使得这颗树扩展为完全图，并满足图的唯一最小生成树依旧是这棵树，求增加的权值最小为

//思路：首先要代入引理，最小生成树一定包含无向图中权值最小的边
//那么我们从此开始思考怎么做，它要构建完全图，就是剩余 n*(n-1)/-n+1 条边的扩充，我们可以把这个过程和 Kruskal 的过程相类比，首先我们为了更小的权值，我们先对边排序
//然后对于一条边 (x,y,z) 我们发现 x 一旁的并查集 sx 和 y 所在的并查集 sy，这两边的集合的点肯定要相连构成一条边，那么此时可以构成一个环，根据上述引理，这条新构建的边必然不可能比 (x,y,z) 小
//那么我们就按照这个道理，构建 (sx*sy-1) 条权值为 z+1 的边

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=6e3+10;

struct node{
	int u,v,w;
	bool operator <(const node &oth)const{
		return w<oth.w;
	}
}a[maxn];

int n,fa[maxn],sz[maxn];

void init(){
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++) scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
		sort(a+1,a+n);
		ll ans=0;
		for(int i=1;i<n;i++){
			int ru=find(a[i].u),rv=find(a[i].v);
			ans+=1ll*(a[i].w+1)*(sz[ru]*sz[rv]-1);
			fa[ru]=rv;
			sz[rv]+=sz[ru];
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
