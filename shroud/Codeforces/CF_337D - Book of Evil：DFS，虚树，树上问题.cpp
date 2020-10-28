//题意：给出一棵 n 个结点的树，给出 m 个被标记的点，和距离 d，求树上到这 m 个点的最大距离小于等于 d 的点的个数

//思路：1.虚树  2.dfs 处理出每个点到 m 个标记点的最大距离
//虚树做法待补
//先说说怎么通过两次 dfs 得到每个点到 m 个标记点的最大距离，首先对于每个节点子树内最远的标记结点很好想，f[u]=min(f[v])+1 （v 代表 u 的子节点的集合，并且只有 v 中存在标记点才会进行状态转移）
//那么我们现在仅仅得到的是以 1 为根节点，然后每个节点子树内的最远标记距离，如果我们设 g[x] 为 x 到所有标记结点的最远距离，那么我们想到 g[v]=g[u]+1（除去到 v 子树的最远距离）
//那么这里我们怎么处理呢，g[x]还是比较好处理的，我们从上到小，g[x] 可以分成 f[fa[x]] 除去 f[x] 的值，然后还有 g[fa[x]] 也是一个参考。
//那么怎么判断 f[fa[x]] 的值是不是取决于 f[x] 呢，这里我们考虑同时记录 x 到其他所有标记点距离的最大值和次大值，这样如果 x 的最大值和 fa[x] 相等，我们只需要判断 fa[x] 的次大值是不是等于即可
//如果不同，那直接取值即可，因为两个取值集合有包含关系，最后遍历所有点，找到子树内和子树外最大距离都小于等于 d 的点

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1e5+10;

int n,m,d;
int head[maxn],to[maxn<<1],nex[maxn<<1],tot=0;
int vis[maxn],f[maxn][2],dist[maxn];

inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}

void dfs_1(int u,int fa){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs_1(v,u);
		if(f[v][0]+1>f[u][0]){
			f[u][1]=f[u][0];
			f[u][0]=f[v][0]+1;
		}
		else if(f[v][0]+1>f[u][1]){
			f[u][1]=f[v][0]+1;
		}
	}
}

void dfs_2(int u,int fa){
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa) continue;
		if(f[u][0]!=f[v][0]+1){
			dist[v]=max(dist[u]+1,f[u][0]+1);
		}
		else dist[v]=max(f[u][1]+1,dist[u]+1);
		dfs_2(v,u);
	}
}

int main(){
	memset(f,-0x3f,sizeof f);
	memset(dist,-0x3f,sizeof dist);
	scanf("%d %d %d",&n,&m,&d);
	int x;
	for(int i=1;i<=m;i++) scanf("%d",&x),f[x][0]=f[x][1]=0;
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs_1(1,0);
	dfs_2(1,0);
	int ans=0;
	if(f[1][0]<=d) ans++;
	for(int i=2;i<=n;i++){
		if(f[i][0]<=d&&dist[i]<=d) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
