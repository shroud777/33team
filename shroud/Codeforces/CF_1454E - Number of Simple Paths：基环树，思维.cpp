//题意：给出一棵 n 个结点的基环树，问任意两点直接的简单路径有多少条？

//思路：这道题要用到一些逆向思维，首先我们判断一些对于任意两个点，他们之间有多少简单路径
//1.两个点都在环上：2条
//2.一个点在某条支链上，一个点在换上：2条
//3.两个点分别在不同的支链上：2条
//4.两个点在同一条支链上：1条
//我们可以看出，这个环是解决问题的关键，两条边中间通过环一般就有 2 条，反之 1 条，实际上除了同一条支链上的点只要 1 条，其他点都有 2 条
//那么我们可以先假设所有点之间都是 2 条边，那么就是 n*(n-1) 条，然后减去每个支链子树大小/2 即可

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=2e5+10;
 
int n;
int head[maxn],nex[maxn<<1],to[maxn<<1],tot=0;
int vis[maxn],in[maxn],sz[maxn];
 
inline void add(int u,int v){
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
 
void top_sort(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(in[i]==1) q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=head[u];i;i=nex[i]){
			int v=to[i];
			if(vis[v]) continue;
			in[v]--;
			if(!vis[v]&&in[v]==1) q.push(v),vis[v]=1;
		}
	}
}
 
void dfs(int u,int fa){
	sz[u]=1; 
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v==fa||!vis[v]) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		tot=0;
		for(int i=1;i<=n+1;i++) vis[i]=in[i]=head[i]=0;
		int u,v;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&u,&v);
			add(u,v);
			add(v,u);
			in[v]++;
			in[u]++;
		}
		top_sort();
		ll res=1ll*n*(n-1);
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			dfs(i,0);
			//cout<<i<<" "<<sz[i]<<endl;
			res-=1ll*sz[i]*(sz[i]-1)/2;
		}
		cout<<res<<endl;
	}
	return 0;
} 
