//题意：n 个人排队进入医院，有 m 组朋友关系，（朋友的朋友不是朋友），如果某个人进入医院的时候发现一个朋友也没有进去，他会很悲伤
//求你给出一个进入医院的序列，使得悲伤人数最少的情况下字典序最小

//思路：先求连通块的数量，因为一个连通块只需要一人即可，为了保证悲伤的人数最少，所以每个连通块只能有 1 人
//然后根据连通块依次出发，我一开始想的是给每个序号一个所在连通块的深度和祖先的信息，这样可以先比较是否在同一祖先和深度，再看序号大小，但是存在一些问题
//其实为了保证序号最小，只要用优先队列维护，那先连通块中序号最小的优先入队，然后依次遍历每个点的邻边，这样正好模拟了一个扩展+字典序最小的过程

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot;
int fa[maxn],vis[maxn],ans[maxn];
vector<int> g[maxn]; 


void init(){
	tot=0;
	for(int i=1;i<=n;i++) vis[i]=0,fa[i]=i,g[i].clear();
}


inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		init();
		int u,v;
		while(m--){
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
			u=find(u),v=find(v);
			if(u==v) continue;
			if(u<v) fa[v]=u;
			else fa[u]=v;
		}
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=1;i<=n;i++){
			if(fa[i]==i){
				q.push(i);
				vis[i]=1;
			}
		}
		printf("%d\n",q.size());
		int t;
		tot=0;
		while(q.size()){
			t=q.top();
			ans[++tot]=t;
			q.pop();
			for(int i=0;i<g[t].size();i++){
				int v=g[t][i];
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
		for(int i=1;i<=tot;i++){
			if(i==1) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
        printf("\n");
	}
	return 0;
} 
